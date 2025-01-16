[org 0x0100]

jmp start

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
	
printnum:
	push bp
	mov bp,sp
	push es
	push ax
	push bx
	push cx
	push dx
	push di
	
	mov ax, 0xb800
	mov es, ax
	
	mov ax, [bp+4]	;number 
	mov bx,10	;divider
	mov cx,0	;digit counter

	nextDigit:
	mov dx,0
	div bx	;ax/bx ==> quotient in ax, remainder in dl
	add dl,0x30	;converting into hexa for printing
	push dx	;push into stack for printing in right order
	
	inc cx
	cmp ax, 0
	jnz nextDigit
	
	mov di,160
	nextPos:
	pop dx
	mov dh,0x0f
	
	mov [es:di],dx
	add di,2
	loop nextPos
	
	
	pop di
	pop dx
	pop cx
	pop bx
	pop ax
	pop es
	pop bp
	
	ret 4

start:
	call clrscr
	mov ax, 69
	push ax
	call printnum
	mov ax, 0x4c00
	int 21h