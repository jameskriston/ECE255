.text
.global stackSim_EA_PUSH
.global stackSim_EA_POP


.func	stackSim_EA_PUSH

stackSim_EA_PUSH:
    push {lr} //store link register

    
    str r2, [r0] // store r2 in simulated stack
    add r0,r0,#4 // increase stack pointer
    
    pop {pc}	//restore	
.endfunc    


.func   stackSim_EA_POP

    stackSim_EA_POP:

    push {lr}
    
    sub r0, r0, #4
    ldr r2, [r0]

    pop {pc}
.endfunc
    
    .end
