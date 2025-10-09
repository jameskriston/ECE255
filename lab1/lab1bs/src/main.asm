		.data
		.align 4
x_array:	.word		0x24,0x12,0x05,0x66,0x12,0x01,0x08,0x14 
			
y_array:	.word		0x12,0x33,0x21,0x0A,0x15,0x11,0x25,0x99 


sum_array:	.space	32

		.text
		.global main

main:		nop
		ldr		r0, =x_array      @ Load register r0 with the value 5
		ldr		r1, =y_array
		ldr		r2, =sum_array
		mov		r3, #0
loop:
		cmp		r3, #8
		bge		stop
		ldr		r4, [r0]		@load content in r0
		ldr		r5, [r1]		@load content in r1
		add		r4, r4,	r5
		str		r4, [r2]

		add		r0, r0, #4
		add		r1, r1, #4
		add		r2, r2, #4
		add		r3, r3, #1
		b		loop
stop:	
		nop	
		b		stop
