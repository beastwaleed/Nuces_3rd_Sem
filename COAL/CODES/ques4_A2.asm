[org 0x0100]
jmp start

size:	dw 5			; size = size + num = 10
num:	dw 5			; 23P-0566
sum:	dw 0

clrscr:	
		push ax
		push es
		push di
		
		mov ax, 0xb800
		mov es, ax
		mov di,0
		
		mov ax, 0x0720
		
	nextloc:
		mov [es:di], ax
		add di, 2
		cmp di, 4000
		jne nextloc
		
		pop di
		pop es
		pop ax
		
		ret

calculateSum:	
		push bp
		mov bp, sp
		
		push ax
		push bx
		push cx
		push dx
		
		xor ax, ax
		mov ax, [bp+6]
		add ax, [bp+4]				; Total size
		mov bx,0				; Outerloop counter
		mov cx,0				; Innerloop counter
		mov dx,0
	
	; Outer most loop
	mainloop:
		mov cx,0
		inc bx
		cmp bx, ax
		jg exit
	
	; Addition till size
	innerloop:
		inc cx
		add dx, cx
		cmp cx, bx
		jl innerloop
	
		; Addition from size till 1
	innerloop2:
		cmp cx, 1
		je mainloop
		dec cx
		add dx, cx
		jmp innerloop2
	
	exit:
		mov [sum], dx
	
		pop dx
		pop cx
		pop bx
		pop ax
		pop bp
		
		ret 4
		
displaySum:
		

		push bp
		mov bp, sp
		
		push ax
		push bx
		push cx
		push dx
		push es
		push di
		
		mov ax, 0xb800
		mov es, ax
		mov di, 160					; Printing from row 2 column 1
		
		mov ax, [bp+4]				; Loading number into ax
		mov bx, 10					; Base 10 for Decimal number
		mov cx, 0
		
	; Converting decimal into hexadecimal
	convert:
		mov dx,0
		div bx
		add dl, 0x30
		push dx
		inc cx
		cmp ax, 0
		jnz convert
		
	; Printing sum digits on screen
	print:
		pop dx
		mov dh, 0x0F
		mov [es:di], dx
		add di, 2
		loop print
		
		pop di
		pop es
		pop dx
		pop cx
		pop bx
		pop ax
		pop bp
		
		ret 2

start:	
		call clrscr
		; Pushing parameters
		push word [size]
		push word [num]
		
		; Calling subroutine
		call calculateSum
		
		; Pushing parameters
		push word [sum]
		
		; Calling subroutine
		call displaySum

		mov ax, 0x4c00			
		int 0x21