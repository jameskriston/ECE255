        .data
        .align 4
a:  .word 0x15 @ = 32 in decimal // let this be numerator

b:  .word 0x04 @ = 16 in decimal //let this be denominator

quotient:    .space 4
remainder:   .space 4


        .text
        .global main

main:       nop
        ldr     r1, = a         @ address a into R1
        ldr     r1, [r1]        @ get value from memory location and put in R1
        ldr     r2, = b         @ address b into R2
        ldr     r2, [r2]        @ get value from memory location and put in R2

        cmp r2,#0               @ check if value in R2 (our b in a/b) is = 0
        beq     stop              @ branch to stop if true

        ldr     r3, = remainder  @ address of quotient into r3
        ldr     r4, = quotient @ address of remainder r4
        ldr     r0, = a         @ address of a into r0
        ldr     r0, [r0]        @ index set to value of a
        mov     r5, #0          @ put 0 into R6 to use in computation

        
loop:
     cmp r0,r2                  @ compare values of r0 and r1 (our index and b)
     blt    valid_divison       @ if our index(a ) is less than b we are done
     sub    r0,r0,r2            @ do r5-r2 and put into r5 (a - b)
     add    r5, r5,#1           @ add 1 to r6, put new value in r6 (increment our quotient by 1)

     b      loop

    

valid_divison:
        str r5, [r4]            @ store remainder
        str r0, [r3]            @ store quotient

       nop
        b       stop            

stop: @stop program 
        
        nop
        
