.text
.global stackSim_EA_PUSH
.global stackSim_EA_POP
.func	stackSim_EA_PUSH
.func   stackSim_EA_POP

stackSim_EA_PUSH:
    push {lr}
    add r0, r0, #4
    str r2, [r0] 
    pop {pc}	
    .endfunc    

    stackSim_FA_POP:
    push {lr}
    ldr r2, [r0]
    sub r0, r0, #4
    pop {pc}
    .endfunc
