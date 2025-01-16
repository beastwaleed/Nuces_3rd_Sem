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


printnum:
push bp
mov bp,sp
push es
push ax
push bx
push cx
push dx
push di


mov ax,0xb800
mov es,ax
mov ax,[bp+4]
mov bx,10
mov cx,0

nextdigit:
mov dx,0
div bx			; ==> ax/bx ==> quotient in ax, remainder in dl
add dl, 0x30	;converting into hexa ascii
push dx			; push the converted number in ascii to stack
inc cx			;counting digits
cmp ax,0		;if quotient is 0
jnz nextdigit

mov di,0

nextpos:
pop dx			;removing a digit from stack
mov dh, 0x07	; normal attribute
mov [es:di],dx	;print popped dx on screen
add di,2
loop nextpos

pop di
pop dx
pop cx
pop bx
pop bx
pop ax
pop es
pop bp
ret 2

start:
	call clrscr
	mov ax, 45662
	push ax
	call printnum

mov ax,0x4c00
int 0x21