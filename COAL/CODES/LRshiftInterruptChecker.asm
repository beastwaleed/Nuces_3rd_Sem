[org 0x0100] 
jmp start

shiftCheck:
	push ax
	push es
	
	mov ax,0xb800
	mov es, ax	;point es to video memory
	
	in  al, 0x60	;read a char from keyboard port
	cmp al, 0x2a	;compare if the key is left shiftCheck
	
	jne nextCmp
	
	mov byte[es:0],'L'	;if Yes --> print L on screen
	jne nomatch
	
	nextCmp:
	cmp al,0x36
	jne nomatch
	
	mov byte[es:0],'R'

	nomatch:
	mov al, 0x20
	out 0x20,al
	
	pop es
	pop ax
	iret
	
start:

	xor ax, ax
	mov es, ax
	cli 
	mov word [es:9*4], shiftCheck
	mov [es:9*4+2], cs
	sti
	
	
	mov ax, 0x4c00
	int 0x21