[org 0x0100]

jmp start
msg1: db 'Waleed'
msg2: db 'Shaikh'
msg3: db '               '
length: dw 6

clrscr:
    push es
    push ax
    push di
    mov ax, 0xb800        
    mov es, ax
    mov di, 0

    mov ah, 0x07
    mov al, 0x20
    mov cx, 2000
    
    cld 
    rep stosw
    
    pop di
    pop ax
    pop es
    ret

ConcatenateStrings:
    push es
    push ax
    push di
    push si
          

    mov si, msg1        ; Point SI to the start of the message1
    mov cx, [length]    ; Get the length of the string

    
    mov di,msg3     ;pointing di to starting of msg3

    loop1:
    mov al, [si]
    mov byte[di],al
    inc si
    inc di
    loop loop1

    mov cx,[length]
    inc di
    mov si,msg2
    loop2:
    mov al,[si]
    mov byte[di],al
    inc si
    inc di
    loop loop2

    ;Printing:


    mov ax, 0xb800            
    mov es, ax
    mov di, 1160      
    mov ah,0x07
    mov cx,[length]
    add cx,[length]
    inc cx
    
    cld
    nextchar:
    lodsb
    stosw
    loop nextchar

    pop si
    pop di
    pop ax
    pop es
    ret

start:
call clrscr
call ConcatenateStrings
mov ax, 0x4c00
int 0x21

