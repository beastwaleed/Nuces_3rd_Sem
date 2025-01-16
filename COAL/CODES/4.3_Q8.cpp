org 0x0100

;jmp start:
mov ax, 0c5A3h
mov bx, 0
mov cx,0
mov dx,0
mov si,0000

start:
mov dx,ax
mov cx,0

loop1:

shr dx,1
jnc noIncrement
add cx,1

noIncrement:
cmp dx,si
jne loop1

mov ax,cx

cmp ax,1
je done

done:
add bx,1

mov ax, 0x4c00
int 0x21