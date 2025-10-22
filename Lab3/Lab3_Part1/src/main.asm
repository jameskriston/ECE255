.data
	.align 4
	stack_Sim_FA: .space 80


.text


	.global main
	main:
//---------  full Ascending stack setup -----------
		ldr r0, =stack_Sim_FA   // r0 is the pointer for stack simulation
		sub r0, #4				// Since it is full stack
		mov r2, #0				// r2: push or pop


//---------- Test --------------------------------
		mov r2, #5
		bl stackSim_FA_PUSH
		mov r2, #10
	 	bl stackSim_FA_PUSH
		mov r2,#114
		bl stackSim_FA_PUSH
		mov r2,#232
		bl stackSim_FA_PUSH
		mov r2,#86
		bl stackSim_FA_PUSH
		mov r2,#30
		bl stackSim_FA_PUSH
		bl stackSim_FA_POP
		bl stackSim_FA_POP
		bl stackSim_FA_POP
		bl stackSim_FA_POP


stop:	nop
		b 		stop
		.end
