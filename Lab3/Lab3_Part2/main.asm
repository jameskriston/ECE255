.data
.align 4
.set size, 150

	sumOfArray: .word 0
	myArray: .space size*4
	stack_Sim_FA:	.space 600

.macro memorygenerate dest, size
   	ldr r3, =\dest
    mov r4, #1

   	loop:
    cmp r4, #\size
    bgt stoploop
    str r4, [r3],#4
    add r4,r4,#1
    b loop
    stoploop:
.endm
.text 
.global main
	main:
		
		memorygenerate myArray,size
		ldr r0, =stack_Sim_FA  @ stack pointer
		mov r1, r0
		sub r0,r0, #4			
		ldr r5, = myArray 	   @ array pointer
		mov r6, #size		   @ counter for array

	pushloop:
		cmp r6,#0
		beq addloop	
		ldr r2, [r5],#4 		   @r2 holds value to be pushed	
		bl stackSim_FA_PUSH
		sub r6,r6,#1
		b pushloop

	addloop:
		cmp r0, r1
		beq done
		bl addsubroutine
		b addloop

	done:
		bl stackSim_FA_POP
		ldr r1, = sumOfArray
		str r2, [r1]
		

stop:	
		b 		stop
		.end
