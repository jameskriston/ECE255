.text

.global stackSim_FD_PUSH
.global stackSim_FD_POP
.func	stackSim_FD_PUSH
.func   stackSim_FD_POP

stackSim_FA_PUSH:
    push {lr} //store link register

    sub r0, r0, #4
    str r2, [r0] 
    pop {pc}	
    .endfunc


stackSim_FA_POP:
    push {lr} 

    ldr r2, [r0]
    add r0, r0, #4

    pop {pc}	
    .endfunc
