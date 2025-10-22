.text
.global main
.align 2
.data
array: .space 150*4

.macro memorygenerate array, size
   ldr r0, =\array
    mov r1, #1

    1: STR r1, [r0], #4
       add r1, r1, #1
       cmp r1, #\size+1
       ble 1b

main:
    push {lr}	
    memorygenerate array,150
    pop {pc}	

