//LZ decompressed written in assembly.
//Written by Mike Hoogendoorn
//Last edited 18-11-2019

.bss
char_buffer: .skip 40			//Create the buffer.
.text							//Indicate we want the following line in the text segment.
.align 2						//
.global decode

decode:
	push { r4, lr } 			//Push r4 and lr to the stack to be restored later.
	mov r4, r0 					//Copy r0 to r4 to preserve the memory address.

loop:
	LDRB r0, [r4] 				//Copy the first byte at the memory adress in r4 to r0.
	CMP r0, #0 					//Compare if r0 equals 0.
	BEQ end 					//If r0 equals 0 end the loop.
	
	CMP r0, #'@' 				//Compare if r0 equals '@'.
	BEQ decompress 				//If R0 equals '@' branch to decompress.
	
	CMP r0, #'*'
	BEQ endline
	
	BL print_char				//Print a char.
	LDRB r0, [r4] 				//Copy the first byte at the memory adress in r4 to r0.
	BL use_buffer				//Branch to the use buffer function.
	
	ADD r4, #1 					//Add 1 to the memory address in r4.
	B loop						//Continue the main loop.
	
endline:
	mov r0, #'\n'				//Replace the * with \n in r0
	BL print_char				//Print the character
	mov r0, #'\n'				//Re-assing r0 since print_char messed with it
	BL use_buffer				//Put the character into the buffer.
	ADD r4, #1					//Increment the memory pointer.
	B loop						//Return to the main loop.

use_buffer:
	push { r5, r6, r7, lr }		//Push the registers we will use to the stack.
	LDR r5, =char_buffer 		//Put the memory address of adr_buff into r5.
	add r5, #39 				//We want to start at the end of the buffer.
	MOV r6, #39 				//Decrease this every loop as a "countdown".
	
buffer_loop:

	SUB r5, #1 					//Go to a lower index in our buffer.
	LDRB r7, [r5] 				//Fetch the char thats in r5.
	STRB r7, [r5, #1] 			//place the fetched char in r5 + 1.

	SUB r6, #1 					//Decrease our loop countdown.
	CMP r6, #0 					//Check if we have reached 0.
	BNE buffer_loop 			//Keep going if we arent at 0 yet.
	STRB r0, [r5] 				//store a char in the buffer.
	pop { r5, r6, r7, pc }		//Return the used registers to their original state.


decompress:
	push { r5, r6, r7 } 		//Push registers we'll use to the stack.
	LDR r5, =char_buffer 		//Put the memory address of our buffer into r5.
	ADD r4, #1 					//Increment the memory address in r4.
	LDRB r7, [r4] 				//Fetch the index from the memory address in r4.
	SUB r7, #'0' 				//Subtract '0' to get the actual decimal value.
	ADD r4, #1 					//Increment the memory address in r4.
	LDRB r6, [r4] 				//Fetch the character amount from the memory address in r4.
	SUB r6, #'0' 				//Subtract '0' to get the actual decimal value,
	ADD r5, r7 					//Add r7 to r5 to get to the correct location in our buffer.
	ADD r4, #1 					//Increment the memory address in r4 once more to set it correct for next loop.
	
secondloop:
	LDRB r0, [r5]				//Fetch a character from the buffer.
	BL print_char				//Print this character.
	LDRB r0, [r5]				//Fetch the same character again in case print_char messed with r0.
	BL use_buffer				//Branch to the buffer function.
	SUB r6, #1					//Lower the loop countdown by 1.
	CMP r6, #0					//If the countdown == 0, end the loop.
	BNE secondloop				//Keep going if the countdown (r6) is above 0.
	pop { r5, r6, r7 }			//Return the used registers to their original state.
	B loop						//Continue the main loop.
	
end:
	pop { r4, pc } 				//Restore r4 and pc to their original state.
