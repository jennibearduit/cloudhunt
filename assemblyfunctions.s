@ FUNCTION 1: computes the next rocket index using the following formula: 
@ cur_rkt = (cur_rkt+SEED)% 4 + (cur_rkt + SEED) % 2 + 1;
@ extern int getNextRocket(u32 curr_rkt, u32 seed);
    .GLOBL getNextRocket
getNextRocket:
    swp     r4, r4, [sp]			 @ pop last input argument from stack and put it in r4
    stmfd   sp!, {r4-r11, lr}     @ save content of r4-r11 and link register into the sp register
	 @ Main
	 add 		r5, r0, r1				 @ r5 = curr_rkt + SEED
	 and 		r6, r5, #3 				 @ r6 = (curr_rkt + SEED) % 4 using XOR (range: 0 - 3)
	 and 		r7, r5, #1				 @ r7 = (curr_rkt + SEED) % 2 using XOR (range: 0 - 1)
	 add 		r8, r6, r7 				 @ r8 = (curr_rkt + SEED) % 4 + (curr_rkt + SEED) % 2 (range: 0-4)
	 add 		r8, r8, #1				 @ r8++ since rocket is not zero-based
	 mov 		r0, r8 					 @ store result in r0
    @ Exit from function
    ldmfd   sp!, {r4-r11, lr}     @ Recover past state of r4-r11 and link register from sp register
    swp     r4, r4, [sp]			 @ Restore state of r4
    mov     pc, lr					 @ Branch back to lr (go back to C code that called this function)



@ FUNCTION 2: returns 1 if (num1 < num2), 0 otherwise.
@ extern int isLessThan(u32 num1, u32 num2);
    .GLOBL isLessThan
isLessThan:
    swp     r4, r4, [sp]			 @ pop last input argument from stack and put it in r4
    stmfd   sp!, {r4-r11, lr}     @ save content of r4-r11 and link register into the sp register
    @ Main
	 mov 		r5, #0					 @ r5 = 0
	 subs		r6, r0, r1				 @ r6 = r0 - r1					 
	 addmi 	r5, r5, #1				 @ r5 = (r0-r1) < 0 ? r5+1 : r5
	 mov 		r0, r5					 @ store result in r0
    @ Exit from function
    ldmfd   sp!, {r4-r11, lr}     @ Recover past state of r4-r11 and link register from sp register
    swp     r4, r4, [sp]			 @ Restore state of r4
    mov     pc, lr					 @ Branch back to lr (go back to C code that called this function)



@ FUNCTION 3: modulo num by 11.
@ extern int modulo16(u32 num);
		.GLOBL modulo16
modulo16:
    swp     r4, r4, [sp]			 @ pop last input argument from stack and put it in r4
    stmfd   sp!, {r4-r11, lr}     @ save content of r4-r11 and link register into the sp register
	 @ Main
	 and 		r5, r0, #15 			 @ Use bit mask of 0xF = 15
	 mov 		r0, r5 					 @ store result in r0
    @ Exit from function
    ldmfd   sp!, {r4-r11, lr}     @ Recover past state of r4-r11 and link register from sp register
    swp     r4, r4, [sp]			 @ Restore state of r4
    mov     pc, lr					 @ Branch back to lr (go back to C code that called this function)
