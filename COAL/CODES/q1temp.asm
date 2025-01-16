org 0x0100
jmp start

arr: db 1, 2, 5, 6, 3, 7, 8
length: db 7
len: db 8
result: db 0
missing: db 0
message: db 'Missing Number is:'

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
    mov di, 160            ; Start printing from the second line
    mov si, message
    mov cx, 17            ; Length of the message string
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
    mov ah, 0
    mov cx, ax
    inc cx
    mul cx
    shr ax, 1
    mov [missing], al

sumofNumbers:
    mov si, 0
	xor cx, cx
    mov cl, [length]
    mov ax, 0
    mov bx, 0
sum_loop:
    mov bl, [arr + si]
    add ax, bx
    inc si
    loop sum_loop
    mov [result], al

findMissing:
    mov al, [missing]
    sub al, [result]
    mov [missing], al

    pop si
    pop dx
    pop cx
    pop bx
    pop ax
    ret

printnum:
    mov ax, 0xb800
    mov es, ax
    mov dl, [missing]
    mov di, 198           ; Position for printing the missing number
	mov dh, 0x8F
    add dl, 0x30
    mov [es:di], dx

    ret

start:
    call clrscr
    call printMessage       ; Print the message before the number
    call findmissing
    call printnum
    mov ax, 0x4c00
    int 0x21