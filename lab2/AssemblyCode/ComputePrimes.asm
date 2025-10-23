
	        .data
        	.align 4
i:           .word 0
n:           .word 0
j:           .word 0
prime:       .word 0
limit:       .word 0
array: 		 .space 80

        .text       
        .global main
    
    main:

        ldr r0, = i
        ldr r1, = n
        ldr r2, = j
        ldr r3, = prime
        ldr r12, = array
        ldr r0, [r0]
        ldr r2, [r2]
        ldr r3, [r3]
        mov r1, #0
        mov r0,#3

    loop0:
      
        cmp r1,#20
        bge stop
        mov r3, #1
        mov r2, #3
        b multiply
        
    loop1:
        
        cmp r8,r0
        bgt 	prime_check

    	b divide
        
        mod_check:
        cmp r6,#0
        beq not_prime
        add r2,r2,#2
        b multiply


        not_prime:
        mov r3, #0
        b prime_check

        prime_check:
        cmp r3,#1
        beq found_prime
        mov r2, #2
        add r0,r0,#2
        b loop0

        found_prime: 
		str r0, [r12]
		add r12, r12, #4
        add r1, r1, #1
        add r0,r0,#2
        b 	loop0
        
       multiply: 
        mov r6, r2
        mov r7, #0
        mov r8, #0
        b 	multiplyloop

        multiplyloop:
        cmp r7,r6
        bge loop1
        add r8,r8,r6
        add r7,r7,#1
        b   multiplyloop

		divide:             
        mov  r6, r0 
        mov  r7, r2       
        cmp r7,#0              
        beq    stop              
        mov     r9, #0          
        
		divide_loop:
     	cmp r6,r2                
     	blt    mod_check    
     	sub    r6,r6,r7           
     	add    r9, r9,#1           

     	b     divide_loop

    stop:

    nop
    b stop
