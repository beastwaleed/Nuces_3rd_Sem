org 0x0100

jmp start
multiplicand: db 13
multiplier: db 5
result: dw 0

start:
mov cl,4
mov bl, [multiplicand]
mov dl, [multiplier]

checkbit:
shr dl,1
jnc skip

	add [result],bl

skip:
shl bl,1
dec cl
jnz checkbit

mov ax, 0x4c00
int 0x21