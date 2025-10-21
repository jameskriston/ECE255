        .data
        .align 4
i:           .word 0x03
n:           .word 0x20
j:           .word 0x00
k:           .word 0x01


binaryarray: .word 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
prime:       .space 4
limit:       .space 4
 
Primearray: .space 80

        .text       
        .global main
    
    main:

        ldr r0, = i
        ldr r1, = n
        ldr r2, = j
        ldr r3, = prime
        ldr r4, = limit
        ldr r5, = Primearray
        
        ldr r0, [r0]
        ldr r1, [r1]
        ldr r2, [r2]

        loop0:
        cmp r2,r0
        gotoloop1 with i*i
        add r2,r2,r2
        loop

      

        
        loop1:
        cmp r0,#4
        blt stop 

        

        ldr r4, [r5]  @
        cmp r0,1
        beq loop2

            add r0, r0,#1

    loop2: // for j=i^2, i^2+i +2i ... less than n
                   // set A[j] false


        /*
        
        i   
            n=3 to n=20

                let boolarray = [1,1,1,....] from index 2 to n
                for(i,2,3,4... < sqrt(n)){
                if array[i]=true
                for j=i^2, i^2+i +2i ... less than n
                    set A[j] false

                    return all i such a[i] is true
         */