org 0x0100

jmp start
mov ax, 5
mov bx, 0
mov dx,1
mov cx,ax
dec cx
shl dx,cx
xor bx,dx

mov ax, 0x4c00
int 0x21