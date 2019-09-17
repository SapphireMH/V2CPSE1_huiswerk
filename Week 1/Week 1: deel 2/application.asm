@Assembly homework Week 1, Part 2
@Written by: Mike Hoogendoorn
@Date of last edit: 17-09-2019

.data
var1: .asciz "Hello world\n"

.text
.align 2
.global application

application:
	LDR r0, adr_var1
	B print_asciz
	
adr_var1: .word var1
