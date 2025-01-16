[org 0x0100]

jmp start
msg: db 'hello world'
length: dw 11
count: dw -1

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

countVowels:
    push es
    push ax
    push di
    push si

    mov ax, 0xb800            
    mov es, ax
    mov di, 1160                

    mov si, msg                ; Point SI to the start of the message
    mov cx, [length]           ; Get the length of the string

    mov ah, 0x07               ; attribute BYTE
    mov al,[si]
    
    vowel:
    inc word[count]
    cld
    nextChar:
    lodsb
    mov dl,'a'
    cmp al,dl
    je vowel
    mov dl, 'e'
    cmp al,dl
    je vowel
    mov dl,'i'
    cmp al, dl
    je vowel
    mov dl,'u'
    cmp al, dl
    je vowel
    mov dl,'o'
    cmp al, dl
    je vowel

    loop nextChar

   ; printing Count of Vowels
   mov al,[count]
   add al,0x30
   mov [es:di],ax

    pop si
    pop di
    pop ax
    pop es
    ret

start:
call clrscr
call countVowels
mov ax, 0x4c00
int 0x21

