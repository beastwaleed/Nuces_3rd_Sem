[org 0x0100]
jmp start

name: db 'my name is waleed', 0

clrscr:
push es
push di
push ax
push cx

mov ax, 0xb800
mov es, ax
mov ax,0x0720
mov cx,2000
xor di,di

cld
rep stosw

pop cx
pop ax
pop di
pop es

ret

printstr:
	mov al,1
	mov bh,0
	mov bl,7
	mov cx, 17
	mov dl,10
	mov dh,7
	push cs
	pop es
	
	mov bp,name
	mov ah,13h
	
	int 10h
	
	ret
	
	
convertCapital:
	push ax
	push bx
	push cx
	push dx
	push di
	push si
	push es

mov cx, 17
mov si,name

l1:
mov al,[si]
sub al, 0x20
mov [si], al

inc si
loop l1


	pop es
	pop si
	pop di
	pop dx
	pop cx
	pop bx
	pop ax
	
	ret

start:
	call clrscr
	call convertCapital
	call printstr
	
	mov ax,0x4c00
	int 21h