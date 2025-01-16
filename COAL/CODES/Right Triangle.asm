org 0x0100

jmp start


clrscr:
	push es
	push ax
	push di

	mov ax,0xb800
	mov es, ax
	mov di,0

	nextloc:
		mov word[es:di], 0x0720
		add di,2
		cmp di,4000
		jne nextloc

	pop di
 	pop ax
	pop es
	ret

pyramid:
	mov bp, sp
	mov ax, 0xb800
	mov es, ax
	mov di , 160
	mov ah, 0x07 
	mov cx, 1 
	mov bx, di
	
	l1:
	mov si, cx
	mov bx, di

	l2:
		mov word [es:di], 0x072A		
		add di, 2
		dec si
		cmp si, 0
		jne l2
		add bx, 160	
		mov di, bx	
		add cx, 2 
		cmp cx, 13 
		jne l1

	pop bp
	ret


start:
call clrscr
call pyramid

mov ax,0x4c00
int 0x21