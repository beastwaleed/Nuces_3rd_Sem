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

HollowPyramid:
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

    mov cx, 10        ; start with 1 star
    mov bx, di       ; save starting position

    mov word [es:di], 0x042A   ; draw '*'
    add di,158
    mov dx,2    ;gap between stars

l2:

    ;mov word [es:di], 0x042A   ; draw '*'
    mov si, cx
    mov bx, di

    mov word [es:di], 0x042A   ; draw '*'
    add dx,4
    add di, dx
    mov word[es:di],0x042A
    sub di,dx
    add di,158

    loop l2
    mov si,0

    lastRow:
     mov word [es:di], 0x022A   ; draw '*'
     add di,4
     inc si
     cmp si,12
     jne lastRow

    pop bp
    ret 4

start:
    call clrscr
    mov ax, 15        ; starting x position (centered)
    push ax
    mov ax, 5         ; y position
    push ax
    call HollowPyramid

    mov ax, 0x4c00
    int 0x21
