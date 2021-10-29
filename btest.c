#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <linux/kernel.h>
#include <sys/syscall.h>

#define __NR_init_buffer_421 442
#define __NR_insert_buffer_421 443
#define __NR_print_buffer_421 444
#define __NR_delete_buffer_421 445
int main(){
	if (syscall(__NR_init_buffer_421) == 0){
		printf("List has been made successfully \n");
		for(int i =1; i <21; i++){
			if(syscall(__NR_insert_buffer_421,i) == -1){
				printf("Something went wrong inserting, list might be full");
				break;
			}
		}
		if(syscall(__NR_print_buffer_421) == -1){
			printf("List might not be initialized");
		}
		if(syscall(__NR_delete_buffer_421) == -1){
			printf("Something went wrong");
		}
	}else{
		printf("List has already been made\n");
	}
	


}
