org 0x0100

jmp start
message: db '==> W A L E E D <==='
length: dw 19

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

Delay:
	push cx
	mov cx,0xFFFF
	delayLoop1:
		nop 
		loop delayLoop1

	mov cx,0xFFFF
	delayLoop:
		nop 
		loop delayLoop

		pop cx
		ret

MegaLoop:
	
	push bp
	mov bp,sp
	push es
	push ax
	push cx
	push si 
	push di

	mov di,0
	mov bx,0

	printstr:
	call Delay
	call clrscr


	mov ax,0xb800
	mov es,ax
	add di,160
	mov si,[bp+6]
	mov cx, [bp+4]
	mov ah,0x07

	nextchar:
		mov al,[si]
		mov [es:di], ax
		add di,2
		add si,1

	loop nextchar

	sub di,38
	inc bx
	cmp bx, 25
	jne printstr

	done:
	pop di
	pop si
	pop cx
	pop ax
	pop es
	pop bp
	ret 4

start:
	;call clrscr
	mov ax, message
	push ax
	push word[length]
	call MegaLoop

mov ax,0x4c00
int 0x21