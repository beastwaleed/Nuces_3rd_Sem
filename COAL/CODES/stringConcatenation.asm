org 0x0100
jmp start

msg1: db 'Waleed',0
msg2: db 'Afzal ' ,0
msg3: db '            ',0
len1: dw 6 

clrscr:
	push ax
	push bx
	push cx
	push es
	push ds
	push di
	
	mov ax, 0xb800
	mov es, ax
	mov di,0
	
	mov ax, 0x0720
	mov cx,2000
	rep stosw
	
	pop di
	pop ds
	pop es
	pop cx
	pop bx
	pop ax
	ret

concatenate:
	push bp
	mov bp,sp
	push ax
	push cx
	push di
	push si
	
	mov ax, 0xb800
	mov es, ax
	
	mov si, [bp+8] ; message 1
	mov di,msg3 ;message 3
	mov cx, [bp+4] ; length
	
	l1:
	mov al, [si]
	mov byte[di],al
	inc si
	inc di
	loop l1
	
	mov cx,[bp+4]
	inc di	;add a space between concatenation
	mov si,[bp+6];	msg 2
	
	l2:
	mov al,[si]
	mov [di],al
	inc si
	inc di
	loop l2
	
	;-------------------------Printing;
	mov di, 520
	mov ah, 0x07
	mov cx, 12

	mov si,msg3
	
	print:
	cld
	lodsb
	stosw
	loop print
	
	pop bp
	pop ax
	pop cx
	pop di
	pop si
	ret 6
	

start:
	call clrscr
	push msg1
	push msg2
	push len1
	call concatenate
	
	mov ax, 0x4c00
	int 0x21