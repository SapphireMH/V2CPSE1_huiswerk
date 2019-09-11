.text
.align 2
.global print_asciz

print_asciz:
	push { r4, lr } @Push r4 and lr to the stack to be restored later.
	mov r4, r0 @Copy r0 to r4 to preserve the memory address.

loop:
	LDRB r0, [r4] @Copy the first byte at the memory adress in r4 to r0.
	CMP r0, #0 @Compare if r0 equals 0.
	BEQ end @If r0 equals 0 end the loop.
	BL toggle_case @Branch link to the toggle case function.
	BL uart_put_char @Branch link to the uart_put_char function.
	ADD r4, #1 @Add 1 to the memory address in r4.
	B loop @Continue the loop.
	
end:
	pop { r4, pc } @Restore r4 and pc to their original state.