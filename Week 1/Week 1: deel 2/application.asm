.data
var1: .asciz "Hello world\n"

.text
.align 2
.global application

application:
	LDR r0, adr_var1
	B print_asciz
	
adr_var1: .word var1