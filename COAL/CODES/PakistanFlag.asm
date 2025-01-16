[org 0x0100]
jmp start
message: db 'Pakistan'
length: dw 8

clrscr:
    push es
    push ax
    push di
    mov ax, 0xb800
    mov es, ax
    mov di, 0
nextloc:
    mov word [es:di], 0x0720
    add di, 2
    cmp di, 4000
    jne nextloc
    pop di
    pop ax
    pop es
    ret

flag:

    push es
    push ax
    push di
    mov ax, 0xb800
    mov es, ax
    mov di, 820                ; Start position for the square (row 10, col 20)
	
whitepart:
    mov cx, 8  	; 5 rows
	
	whitenextrow:
		push cx                    ; Save row counter
		mov bx, 6                  ; 6 columns
	whitenextcol:
		mov word [es:di], 0x073D   ; 0x07 (white on black), 0x2D ('-' character)
		add di, 2                  ; Move to next column (2 bytes per character)
		dec bx                     ; Decrement column counter
		cmp bx, 0
		jne whitenextcol               ; Continue for columns

		add di, 148         ; Move to the next row (80 * 2 bytes per row, subtract 12 for 6 characters printed)
		pop cx                     ; Restore row counter
		dec cx                     ; Decrement row counter
		cmp cx, 0
		jne whitenextrow   		; Continue for rows

greenpart:
	mov di,832
	mov cx,8 ; rows
	greenrow:
	push cx
	mov bx,20 ;columns
	
	greencol:
	mov word [es:di],0x023D
	add di,2
	dec bx
	cmp bx,0
	jne greencol
	
	add di, 120
	pop cx
	dec cx,
	cmp cx,0
	jne greenrow
	
	mov cx,10
	
poll:
	mov di, 1928
	mov cx, 15  	; 5 rows
	
	nextrow:
		push cx                    ; Save row counter
		mov bx, 3                  ; 6 columns
	nextcol:
		mov word [es:di], 0x073D   ; 0x07 (white on black), 0x2D ('-' character)
		add di, 2                  ; Move to next column (2 bytes per character)
		dec bx                     ; Decrement column counter
		cmp bx, 0
		jne nextcol               ; Continue for columns

		add di, 148         ; Move to the next row (80 * 2 bytes per row, subtract 12 for 6 characters printed)
		pop cx                     ; Restore row counter
		dec cx                     ; Decrement row counter
		cmp cx, 0
		jne nextrow  
	
	
	pop di
    pop ax
    pop es
	ret
	
textpart:
	push bp
    mov bp,sp
    push es
    push ax
    push cx
    push si 
    push di

    mov ax,0xb800
    mov es,ax
    mov di,1480
    mov cx, [bp+4]          ; Length of the message
    mov si, [bp+6]          ; Address of the message
    mov ah,0x07             ; Attribute: White on black

    nextchar:
        mov al,[si]
        mov [es:di], ax
        add di,2
        add si,1
        loop nextchar

    pop di
    pop si
    pop cx
    pop ax
    pop es
    pop bp
    ret 4

start:
    call clrscr
    call flag
	mov ax, message
	push ax
	push word[length]
	call textpart
    mov ax, 0x4C00
    int 0x21
