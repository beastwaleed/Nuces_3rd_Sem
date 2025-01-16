[org 0x0100]
jmp start

name: db 'my name is waleed', 0
oldISR: dd 0

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


myKBISR:
	in al,0x60
	cmp al,0x0F
	jne nextkeyCheck
	
	call printstr
	jmp doneISR
	
	nextkeyCheck:
	cmp al,0x39
	jne enterKey
	call reverse
		
doneISR:
jmp far[cs:oldISR]

printstr:
	push ax
	push bx
	push cx
	push dx
	push si
	
	mov ax, 0xb800
	mov es,ax
	mov di,160
	mov cx, 17
	mov si,name
	mov ah,0x04
	
	cld
	printLoop:
	lodsb
	stosw
	loop printLoop
	
	pop si
	pop dx
	pop cx
	pop bx
	pop ax
	ret

reverse:
	push ax
	push bx
	push cx
	push dx
	push es
	push si
	push di
	
	mov ax, 0xb800
	mov es,ax
	
	mov cx,17
	mov di,160
	
	mov si, name
	add si,16
	mov ah,0x0f
	mov al,0
	
	l2:
	std
	lodsb
	cld
	stosw
	loop l2
	
	
	pop ax
	pop bx
	pop cx
	pop dx
	pop es
	pop si
	pop di
	ret
	

start:
	call clrscr
	
	mov ax,0
	mov es, ax
	;
	mov ax, [es:9*4]
	mov [oldISR],ax
	mov ax, [es:9*4+2]
	mov [oldISR+2],ax
	;
	cli
	mov word[es:9*4],myKBISR
	mov word[es:9*4+2],cs
	std
	;
	loop1:
	mov ah,0
	int 0x16
	;
	cmp al,27
	jne loop1
	;
	mov ax, [oldISR]
	mov bx, [oldISR+2]
	;
	cli
	mov word[es:9*4],ax
	mov word[es:9*4+2],bx
	std
		
	mov ax,0x4c00
	int 21h