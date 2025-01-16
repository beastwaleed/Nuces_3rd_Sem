[org 0x0100]
jmp start

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

pyramid:
    push bp
    mov bp, sp

    mov ax, 0xb800
    mov es, ax

    mov al, 80
    mul byte [bp+4]  ; y-position
    add ax, [bp+6]   ; x-position
    shl ax, 1
    mov di, ax       ; calculate starting position
    mov ah, 0x07     ; white on black attribute

    mov cx, 1        ; start with 1 star
    mov bx, di       ; save starting position

l1:
    mov si, cx
    mov bx, di

l2:
    mov word [es:di], 0x072A   ; draw '*'
    add di, 2 
    dec si
    cmp si, 0
    jne l2

    add bx, 158       ; move to the next row
    mov di, bx        ; update di to the new row start
    add cx, 2         ; increase star count by 2 for next row

    cmp cx, 13        ; stop after 6 rows (7 rows total) 
    jne l1

    pop bp
    ret 4

start:
    call clrscr
    mov ax, 15        ; starting x position (centered)
    push ax
    mov ax, 5         ; y position
    push ax
    call pyramid

    mov ax, 0x4c00
    int 0x21
