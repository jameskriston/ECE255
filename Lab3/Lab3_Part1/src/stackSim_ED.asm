.text
.global stackSim_ED_PUSH
.global stackSim_ED_POP
.func	stackSim_ED_PUSH
.func   stackSim_ED_POP

stackSim_ED_PUSH:
    push {lr} //store link register

    add r0, #4 // increase stack pointer
    str r2, [r0] // store r2 in simulated stack

    pop {pc}	//restore
    .endfunc

    stackSim_ED_POP:
    push {lr} 
    ldr r2, [r0]
    add r0, r0, #4
    pop {pc}
    .endfunc