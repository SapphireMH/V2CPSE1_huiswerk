//Assembly homework Week 1, Part 2
//Written by: Mike Hoogendoorn
//Date of last edit: 17-09-2019

.text
.align 2
.global print_asciz

print_asciz:
	push { r1, lr }
	mov r1, r0

loop:
	LDRB r0, [r1] 
	CMP r0, #0
	BEQ end
	BL uart_put_char
	ADD r1, #1
	B loop
	
end:
	pop { r1, pc }
