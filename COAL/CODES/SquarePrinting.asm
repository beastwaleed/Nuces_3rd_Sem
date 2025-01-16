org 0x0100
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

printdash1:
    push es
    push ax
    push cx
    push di

    mov ax, 0xb800
    mov es, ax
    mov di, 2
    mov cx, 10      ; We need 10 dashes
    mov ah, 0x07

nextchar1:
    mov al, 0x2D    ; ASCII code for '-'
    mov [es:di], ax
    add di, 2
    loop nextchar1

    pop di
    pop cx
    pop ax
    pop es
    ret

printverticaldash1:
    push es
    push ax
    push cx
    push di

    mov ax, 0xb800
    mov es, ax
    mov cx, 5       ; Print '|' 5 times
    mov ah, 0x07

nextline2:
    mov al, 0x7C    ; ASCII code for '|'
    mov [es:di], ax
    add di, 160     ; Move to the next row (80 columns * 2 bytes per character)
    loop nextline2

    pop di
    pop cx
    pop ax
    pop es
    ret

printlastdash:
    push es
    push ax
    push cx
    push di

    mov ax, 0xb800
    mov es, ax
    mov di, 642
    mov cx, 10      ; We need 10 dashes
    mov ah, 0x07

    nextchar2:
        mov al, 0x2D    ; ASCII code for '-'
        mov [es:di], ax
        add di, 2
        loop nextchar2

    pop di
    pop cx
    pop ax
    pop es
    ret

printverticaldash2:
    push es
    push ax
    push cx
    push di

    mov ax, 0xb800
    mov es, ax
    mov cx, 5       ; Print '|' 5 times
    mov ah, 0x07

    nextline3:
    mov al, 0x7C    ; ASCII code for '|'
    mov [es:di], ax
    add di, 160    ; Move to the next row (80 columns * 2 bytes per character)
    loop nextline3

    pop di
    pop cx
    pop ax
    pop es
    ret

start:
    call clrscr
    call printdash1
    mov di, 2       ; Start printing '|' below the first dash
    call printverticaldash1
    call printlastdash
    mov di,20
    call printverticaldash2
    mov ax, 0x4c00
    int 0x21
