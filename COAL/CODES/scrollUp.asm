org 0x0100

jmp start

num: db 1
message: db 'Waleed is a skilled programmer and freelance web developer with a focus on C++ and creating user-friendly websites. He also writes SEO content and product descriptions with great attention to detail. Waleed is good at simplifying complex ideas and making them easy to understand. He is always learning and works hard to deliver the best results in his projects', 0

clrscr:
push ax
push bx
push cx
push dx
push di

mov ax, 0xb800
mov es,ax
mov di,0
mov cx,2000

	loop1:
	mov word[es:di],0x0720
	add di,2
	loop loop1;
	
	
	pop di
	pop dx
	pop cx
	pop bx
	pop ax
	ret


print:
    push bp
    mov bp, sp
    push ax
    push cx
    push si
    push di
    push es

    mov ax, 0xb800
    mov es, ax 
    mov ah, 0x07
	
	mov di,320
	
	mov si,message
	mov ah,0x07
	
	printLoop:
	lodsb
	cmp al,0
	
	je nextPrint
	mov [es:di],ax
	add di,2
	jmp printLoop
	
	nextPrint:
    mov di, 2000
    mov al, [num]
    add al, '0'         ; Convert to ASCII
    stosw               ; Print 1
	
    add di, 160
    add al, 1           ; Increment for the next number
    stosw               ; Print 2

    add di,160
    add al, 1           ; Increment for the next number
    stosw               ; Print 3

    add di, 160
    add al, 1           ; Increment for the next number
    stosw               ; Print 4

    add di,160
    add al, 1           ; Increment for the next number
    stosw               ; Print 5

	pop es
	pop di
	pop si
	pop cx
	pop ax
	pop bp
	
	ret 4
	

scrollup:
    push bp
    mov bp, sp
    push ax
    push cx
    push si
    push di
    push es

    mov ax, 0xb800
    mov es, ax
    mov ds, ax          ; Set `ds` to video memory as well

    mov ax, 80
    mul byte [bp+4]     ; Multiply by rows to scroll
    mov si, ax
    shl si, 1           ; Convert rows to words
	
    mov di, 0           ; Start copying from the top
    mov cx, 2000
    sub cx, si          ; Calculate remaining lines
    cld
    rep movsw           ; Move screen content up

    mov ax, 0x0720      ; Fill cleared lines with spaces (attribute: 0x07)
    mov cx, si
    rep stosw

    pop es
    pop di
    pop si
    pop cx
    pop ax
    pop bp
    ret 2

start:
    mov ax, cs          ; Set `ds` to `cs` (data segment)
    mov ds, ax

	call clrscr
	
    call print          ; Call the `print` function
    mov ax, 4           ; Number of rows to scroll
    push ax
    call scrollup       ; Call the `scrollup` function

    mov ax, 0x4c00
    int 0x21            ; Exit the program
