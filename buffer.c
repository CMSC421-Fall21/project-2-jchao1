#include <linux/kernel.h>
#include <linux/syscalls.h>

#include "buffer.h"

static ring_buffer_421_t list;

SYSCALL_DEFINE0(delete_buffer_421){
	if(list.length == 20){
		int i;
		for(i = 0; i < SIZE_OF_BUFFER; i++){
				node_421_t *temp = list.read;
				list.read = list.read->next;
				kfree(temp);
		}
		return 0;
	}
	return -1;
}

SYSCALL_DEFINE1(insert_buffer_421,int,i){
	if(list.length == 20){
		node_421_t *curr = list.read;
		while(curr->data != 0 && curr != list.write){
			curr = curr->next;
			
		}
		if(curr->data == 0){
			curr->data = i;
			return 0;
		}
	}
	return -1;
}

SYSCALL_DEFINE0(print_buffer_421){
	if(list.length == 20){
		node_421_t *curr = list.read;
		int i;
		for(i = 0; i < 20; i ++){
			printk("Node %d data: %d \n", i,curr->data); 
			curr = curr->next;
		}
		return 0;
	}
	return -1;
}

SYSCALL_DEFINE0(init_buffer_421){
	if (list.read == NULL){
		int i;
		node_421_t *curr;
		node_421_t *temp;
		
		for(i = 0; i < SIZE_OF_BUFFER; i++){
			temp= kmalloc(sizeof(node_421_t *),GFP_KERNEL);
			if(i == 0 ){
				list.read = temp;
				list.write = temp;
				temp->next = NULL;
				temp->data = 0;
				list.length ++;
		
			}else{
				curr = list.read;
				while(curr != list.write){
					curr = curr->next;
				}
				curr->next = temp;
				list.write = temp;
				temp->data = 0;
				temp->next = list.read;
				list.length++;
			}
		}
		return 0;
	}
	return -1;

	
}
