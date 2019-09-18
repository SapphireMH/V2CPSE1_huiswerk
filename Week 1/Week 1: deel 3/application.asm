//Assembly homework Week 1, Part 3
//Written by: Mike Hoogendoorn
//Date of last edit: 17-09-2019

.data
var1: .asciz "Hello world, the ANSWER is 42! @[]`{}~\n" @Write our string in memory.

.text
.align 2
.global application

application:
	LDR r0, adr_var1 @Put the memory address of adr_var1 into r0.
	B print_asciz @Branch to print_asciz.
	
adr_var1: .word var1 @Put the memory address of var1 into adr_var1.
