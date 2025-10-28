
	        .data
        	.align 4

array: 		 .space 80 @ array for our 20 primes


        .text       
        .global main
    
    main:
		
        mov r1, #0 @ r1 is our number of primes found
        mov r0, #3 @ r0 is our i for the main loop 
		ldr r12, = array @ r12 is pointer to  array of primes 
	
		
    loop0:
      
        cmp r1, #20 @ if our n is greater or equal to 20 stop program
        bge stop
        mov r2, #3 @ begin factor checking at j = 3, then increment j by 2 (odd numbers) while j*j <= i (essentially our limit j is sqrt(i)) 
        b multiply @ go multipy j to get j*j
        
    loop1:
        
        cmp r8,r0 @ if j*j > i (other words, has our nested loop reached limit of sqrt(i))
        bgt prime @ if above is true then we have not found a factor and i must be prime

    	b modulo @ if still below limit, perform divison using modified division algorithm
        
        mod_check: @ check if modulo has found remainder of i%j to be 0
        cmp r6, #0
        beq not_prime @ if i%j == 0 then not prime
        add r2,r2,#2 @ else add 2 to j and perform modulo again
        b multiply 

        not_prime:
        add r0,r0,#2
		mov r2,#3
        b loop0

        prime: @ stores prime in array, increments n, resets j to 3
        str r0, [r12]
		add r12, r12, #4
        add r1, r1, #1
        mov r2, #3
        add r0,r0,#2
        b loop0
        
       multiply: @ multiply j*j using basic repeated addition algorithm
        mov r6, r2
        mov r7, #0
        mov r8, #0
        b 	multiplyloop

        multiplyloop: @ repeated addition of j
        cmp r7,r6
        bge loop1 @ once we have j*j go back to nested loop
        add r8,r8,r6
        add r7,r7,#1
        b   multiplyloop

        @ This division algorithm uses chunking to quicker get to the remainder
        @ Double the divisor until it is larger than the remainder
        @ Once divisor is larger than divisor, go back to previous divisor
        @ Subtract that previous divisor and repeat process above until once again divisor larger than remainder
        @ Once we can no longer get a larger subtraction value then that maximum value is our remainder 
        @ This optimization of divison hugely cuts down on the time required to check modulo
        @ If dividng a very large number, you may need to subtract thousands of times
        @ This chunking algorithm essentially cuts the required subtractions in half due to doubling of the divisor

        modulo:
        mov r6, r0  
        mov r7, r2   

        mod:                @ here we check if remainder < divisor
        cmp r6,r7 
        blt mod_check 
        mov r8,r7 

        mod_loop:
        add r8,r8,r8  @ repeatedly double divisor and compare with remainder
        cmp r8,r6
        ble mod_loop

        lsr r8,r8,#1  @ this is our way to get back to previous largest value (shift left to double)
        sub r6,r6,r8  @ then here we subtract the previous largest value from the remainder and begin process over going back to mod:
        b mod

stop:

    b stop


