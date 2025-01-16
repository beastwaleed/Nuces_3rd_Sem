[org 0x0100]

jmp start
exp: db '0'

clrscr:
	push es
	push ax
	push cx
	push di
	
	mov ax, 0xb800
	mov es,ax
	mov di, 0
	
	mov ah, 0x07
	mov al, 0x20
	mov cx, 2000
	
	cld
	rep stosw
	
	pop di
	pop cx
	pop ax
	pop es
	ret

calculator:
	push bp
	mov bp,sp
	push ax
	push bx
	push cx
	push dx
	
	;Print Expression
	mov ax, 0xb800
	mov es,ax
	
	mov di,320
	mov si,exp
	
	loop1:
	mov al,[si]
	cmp al,0
	je done
	mov ah,0x07
	stosw
	inc si
	jmp loop1
	
	done:
	;print answer:
	mov al,[exp] ;first operand
	sub al,'0'
	
	mov bl,[exp+2]	;second operand
	sub bl,'0'
	
	mov cl,[exp+1]
	
	cmp cl,'*'
	jmp multiply
	
	cmp cl,'+'
	jmp addition
	
	cmp cl,'-'
	jmp subtract
	
	cmp cl, '/'
	jmp divide
	
	jmp exit
	
	multiply:
	mul  bl
	mov di, 480
    add al, '0'          ; Convert back to ASCII
    mov ah, 0x07
    stosw
	jmp exit
	
	addition:
	add al,bl
	mov di, 480
    add al, '0'          ; Convert back to ASCII
    mov ah, 0x07
    stosw
	jmp exit

	subtract:
	sub al,bl
	mov di, 480
    add al, '0'          ; Convert back to ASCII
    mov ah, 0x07
    stosw
	jmp exit
	
	divide:
	div bl
	mov di, 480
    add al, '0'          ; Convert back to ASCII
    mov ah, 0x07
    stosw
	jmp exit

	exit:
	pop dx
	pop cx
	pop bx
	pop ax
	pop bp
	ret
	
start:
	call clrscr
	
	mov si,0
	l1:
	mov ah,00h
	int 16h
	mov [exp+si],al
	inc si
	cmp al,0Dh
	jne l1
	mov byte [exp+si-1],0
	
	
	call calculator
	
	mov ax, 0x4c00
	int 0x21