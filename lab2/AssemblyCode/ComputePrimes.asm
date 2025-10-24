
	        .data
        	.align 4

array: 		 .space 400


        .text       
        .global main
    
    main:
		
/*
i is r0
n is r1
j is r2
r12 array pointer
other registers used for arithmetic operations.
*/
   
        mov r1, #0
        mov r0,#3
		ldr r12, = array
		mov r11, #0
		
		
    loop0:
      
        cmp r1,#100
        bge stop
        mov r2, #3
        b multiply
        
    loop1:
        
        cmp r8,r0
        bgt prime

    	b divide
        
        mod_check:
        cmp r6,#0
        beq not_prime

        add r2,r2,#2
        b multiply


        not_prime:
        add r0,r0,#2
		mov r2,#3
        b loop0

        prime:
        str r0, [r12]
		add r12, r12, #4
        add r1, r1, #1
        mov r2, #3
        add r0,r0,#2
        b loop0
        
       multiply: 
        mov r6, r2
        mov     r7, #0
        mov     r8, #0
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
           
        
		divide_loop:
     	cmp r6,r2                  
     	blt    mod_check       
     	sub    r6,r6,r7           
     	           

     	b     divide_loop

stop:

    b stop



