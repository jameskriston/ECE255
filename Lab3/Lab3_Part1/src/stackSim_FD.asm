.text

.global stackSim_FD_PUSH
.global stackSim_FD_POP

.func stackSim_FD_PUSH

    stackSim_FD_PUSH:

    push {lr}       //store link register

    sub r0, r0, #4  //decrease ptr to empty space
    str r2, [r0]    //store value

    pop {pc}	    // restore

    .endfunc
.func stackSim_FD_POP

    stackSim_FD_POP:

    push {lr}       //store link register

    ldr r2, [r0]    // take value from top of stack 
    add r0, r0, #4  // add to stack pointer to go to previous position

    pop {pc}	

    .endfunc
