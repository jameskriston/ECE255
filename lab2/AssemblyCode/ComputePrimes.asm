        .data
        .align 4
i:           .word 0x03
n:           .word 0x20
j:           .word 0x00
k:           .word 0x01
a:           .word 0
b:           .word 0
c:           .word 0
d:           .word 0
e:           .word 0
prime:       .word 0
limit:       .word 0
quotient:    .space 4
remainder:   .space 4
Primearray: .space 80


        .text       
        .global main
    
    main:

        ldr r0, = i
        ldr r1, = n
        ldr r2, = j
        ldr r3, = prime
        ldr r12, array
        
        ldr r0, [r0]
        ldr r2, [r2]
        ldr r3, [prime]
        ldr r5, [PrimeArray]
        mov r1, #0
        mov r0,#3

    loop0:
      
        cmp r1,#20
        bge stop
        mov r3, #1
        mov r2, #3
        b multiply
        
    loop1:
        
        cmp r0,r7
        blt prime_check



    b divide
        
        mod_check:
        cmp(r8,#0)
        beq not_prime

        add r2,r2,2
        b multiply


        not_prime:
        mov r3, #0
        b prime_check


        prime_check:
        cmp(r3,#1)
        beq found_prime
        mov r2, #2
        add r0,r0,#2
        b loop0


        found_prime: 
        str r0, [r12]
        add r12,r12,#4
        //store i in the array 
        add r1, r1, #1
        add r0,r0,#2
        b loop0
        

       multiply: 
        ldr     r6, = a
        ldr     r6, [r2] 
        
      
        mov     r7, #0
        mov     r8, #0
        b multiplyloop

        multiplyloop:
        cmp r6,r6
        bge stopmultiply
        add r8,r6,r6
        add r7,r7,#1
        b   multiplyloop

        stopmutiply:
        
        ldr r7, [r8]
        b loop1 
        

     
divide:       nop
        ldr     r6, = a         @ address a into R1
        ldr     r6, [r0]        @ get value from memory location and put in R1
        ldr     r7, = b         @ address b into R2
        ldr     r7, [r2]        @ get value from memory location and put in R2

        cmp r7,#0               @ check if value in R2 (our b in a/b) is = 0
        beq     stop              @ branch to stop if true


        ldr     r8, = a         @ address of a into r0
        ldr     r8, [r8]        @ index set to value of a
        mov     r9, #0          @ put 0 into R6 to use in computation

        
divide_loop:
     cmp r8,r2                  @ compare values of r0 and r1 (our index and b)
     blt    valid_divison       @ if our index(a ) is less than b we are done
     sub    r8,r8,r7            @ do r5-r2 and put into r5 (a - b)
     add    r9, r9,#1           @ add 1 to r6, put new value in r6 (increment our quotient by 1)

     b      divide_loop

    

valid_divison:
        ldr     r3, = remainder  @ load r3 with remainder address
      
       
        str r8, [r8]            @ store remainder

       
        b     mod_check            


stop

    nop
    b stop
