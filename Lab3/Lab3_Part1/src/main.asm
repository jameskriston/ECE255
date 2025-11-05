.data
	.align 4
	stack_Sim: .space 80


.text


	.global main
	main:
//---------  full Ascending stack setup -----------
// r0 is the pointer for stack simulation


	//	ldr r0, =stack_Sim		// USE FOR EMPTY ASCENDING STACK
	//	add r0,r0,#4
		

	//	ldr r0, =stack_Sim      // USE FOR EMPTY DESCENDING STACK
	//    sub r0,r0,#4


		ldr r0, =stack_Sim	    // USE FOR FULL ASCENDING or FULL DESCENDING	
		
		mov r2, #0				


//---------- Test --------------------------------
		mov r2, #5
		bl stackSim_FD_PUSH
		mov r2, #10
	 	bl stackSim_FD_PUSH
		mov r2,#114
		bl stackSim_FD_PUSH
		mov r2,#232
		bl stackSim_FD_PUSH
		mov r2,#86
		bl stackSim_FD_PUSH
		mov r2,#30
		bl stackSim_FD_POP
		bl stackSim_FD_POP
		bl stackSim_FD_POP
		bl stackSim_FD_POP


stop:	nop
		b 		stop
		.end
