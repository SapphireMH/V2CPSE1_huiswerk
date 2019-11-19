//Assembly homework Week 1, Part 4
//Written by: Mike Hoogendoorn
//Date of last edit: 17-09-2019

.text
.align 2
.global toggle_case

toggle_case:
	push { lr } //Lr to the stack to be restored later.
	
	CMP r0, #'a' //Compare r0 with 'a'.
	BGE temp //Branch if r0 is higher then 'a'.
	CMP r0, #'A' //Compare r0 with 'A'.
	BGE temp2 //Branch if r0 is higher then 'A'.
	B end //Branch to end if both statements were false.
	
temp:
	CMP r0, #'z' //Compare r0 with 'z'.
	BLE subtract //Branch if r0 is smaller then 'z'.
	B end //Branch to the end if both statements were false.
	
temp2:
	CMP r0, #'Z' //Compare r0 with 'Z'.
	BLE addup //Branch if r0 is smaller then 'Z'.
	B end //Branch to end if both statements were false.
	
subtract:
	SUB r0, #32 //Subtract 32 from r0.
	B end //Branch to the end.
	
addup:
	ADD r0, #32 //Add 32 to r0.

end:
	pop { pc } //Restore pc to their original state.
