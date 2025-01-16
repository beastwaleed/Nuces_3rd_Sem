[org 0x0100]
jmp start
arraystr: db 'hello',0,'class room',0, 'is',0,'language',0
arraylen: db 0,0,0,0,0


findMinString:
	push bp
	mov bp,sp
	push ax
	push bx
	push cx
	push es
	push dx

	mov si,arraystr
	mov dx,0xffff
	mov cx,0
	mov bx,0
	lodsb
	
	loop1:
	cmp al,0
	je stringEnd
	
	inc cx
	lodsb
	jmp loop1
	
	stringEnd:
	cmp dx,cx
	jb skipUpdate
	mov dx,cx

	skipUpdate:
	add bx,cx
	inc bx
	mov si,arraystr
	add si,bx
	mov cx,0
	lodsb
	cmp al,0
	jne loop1
	
	mov ax,0xb800
	mov es,ax
	mov di,360
	
	add dl,0x30
	mov dh, 0x07
	
	mov word[es:di],dx
	
	pop dx
	pop es
	pop cx
	pop bx
	pop ax
	pop bp
	
	ret
	

start:
	
	mov ax, 0
	call findMinString
	
mov ax,0x4c00
int 0x21
