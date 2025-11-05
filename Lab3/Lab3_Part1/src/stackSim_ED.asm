.text
.global stackSim_ED_PUSH
.global stackSim_ED_POP

.func	stackSim_ED_PUSH

    stackSim_ED_PUSH:

    push {lr} //store link register

    str r2, [r0] // store r2 in simulated stack
    sub r0,r0,#4 // increase stack pointer
    
    pop {pc}	//restore
.endfunc

.func   stackSim_ED_POP

    stackSim_ED_POP:

    push {lr} 
    
    add r0, r0, #4
    ldr r2, [r0]

    pop {pc}
.endfunc


.end
