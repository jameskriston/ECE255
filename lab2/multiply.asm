        .data
        .align 4
a:  .word 0x20 @ = 32 in decimal

b:  .word 0x10 @ = 16 in decimal

result: .word 0

        .text       
        .global main
    
main:       nop
        ldr     r1, = a
        ldr     r1, [r1]
        ldr     r2, = b 
        ldr     r2, [r2]
        ldr     r3, = result
        mov     r0, #0
        mov     r4, #0
loop:
     cmp r0, r1
     bge stop
     add    r4,r4,r2
     add    r0,r0,#1
     b      loop

    

stop:
        str r4, [r3]
        nop
        b       stop

