org 0x0100
jmp start

arr: db 1, 2, 4, 6, 3, 7, 8
length: db 7
len: db 8
result: db 0
missing: db 0
message: db 'Missing Number is: '


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

printMessage:
    push ax
    push di
    mov ax, 0xb800
    mov es, ax
    mov di, 162            ; Start printing from the second line
    mov si, message
    mov cx, 19            ; Length of the message string
    mov ah, 0x5F
nextchar:
    mov al, [si]
    mov [es:di], ax       ; Write character to screen
    add di, 2             ; Move to the next character position
    inc si
    loop nextchar

    pop di
    pop ax
    ret

findmissing:
    push ax
    push bx
    push cx
    push dx
    push si

sumofLength:
    mov al, [len]
    ;inc al
    mov ah, 0
    mov cx,0
    mov cx, ax
    inc cx
    mul cx
    shr ax, 1
    mov [missing], ax

sumofNumbers:
    mov si, 0
    xor cx,cx
    mov cl, [length]
    mov ax, 0
    mov bx, 0
sum_loop:
    mov bl, [arr + si]
    add ax, bx
    inc si
    loop sum_loop
    mov [result], ax

findMissing:
    mov ax, [missing]
    sub ax, [result]
    mov [missing], ax

    pop si
    pop dx
    pop cx
    pop bx
    pop ax
    ret

printnum:
    mov ax, 0xb800
    mov es, ax
    mov ax, [missing]
    mov bx, 10
    mov cx, 0
    mov di,202
nextdigit:
    mov dx, 0
    div bx
    add dl, 0x30
    mov [es:di], dl
    ret

start:
    call clrscr
    call printMessage
    call findmissing
    call printnum
    mov ax, 0x4c00
    int 0x21