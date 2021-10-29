cmd_buffer/modules.order := {  :; } | awk '!x[$$0]++' - > buffer/modules.order
