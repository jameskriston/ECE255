.text
.global addsubroutine
.func addsubroutine

addsubroutine:

push {lr}
ldr r2, [r0]
sub r0,r0,#4
ldr r3, [r0]
add r2,r2,r3
str r2, [r0]
pop {pc}
.endfunc
.end
