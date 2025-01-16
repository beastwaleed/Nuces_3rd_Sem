[org 0x0100]

jmp start
msg2: db 'Waleed '
len: dw 6

clrscr:
	push ax
	push cx
	push di
	
	mov ax, 0xb800
	mov es,ax

	mov di,0
	
	nextloc:
	mov word[es:di],0x0720
	add di,2
	cmp di,4000
	jne nextloc
	
	pop di
	pop cx
	pop ax
	ret
	

printstr:
	push bp
	mov bp,sp
	push es
	push ax
	push di
	
	mov ax, 0xb800
	mov es, ax	
	mov di,160

	mov si,[bp+4]
	mov cx, [len]
	mov ah,0x0f
	
	nextchar:
	mov al,[si]
	mov word[es:di],ax
	add di,2
	add si,1
	loop nextchar
	
	pop di
	pop ax
	pop es
	pop bp
	
	ret 4

start:
	call clrscr
	mov ax, msg2
	push ax
	call printstr
	mov ax, 0x4c00
	int 21h