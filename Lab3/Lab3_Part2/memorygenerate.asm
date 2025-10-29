
.macro memorygenerate dest, size
   ldr r0, =\dest
    mov r1, #1

   loop:
   cmp r1, #\size
   bgt stoploop
   str r1, [r0],#4
   add r1,r1,#1
   b loop
   stoploop:
   .endm


