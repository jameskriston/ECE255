	.text
	.global	stackSim_FA_PUSH
	.global	stackSim_FA_POP
	.func	stackSim_FA_PUSH


	stackSim_FA_PUSH:
		push {lr} //store link register

		add r0,#4 // increase stack pointer
		str r2,[r0] // store r2 in simulated stack


		pop {pc}	//restore
	.endfunc



	.func	stackSim_FA_POP
	stackSim_FA_POP:
		push {lr} //store link register

		ldr r2,[r0]
		sub r0,#4


		pop {pc}	//restore
	.endfunc

	.end
