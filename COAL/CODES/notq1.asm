org 0x0100

jmp start

; Data Section
arr: db 1, 2, 4, 6, 3, 7, 8       
length: db 7                        
len: db 8       
result: db 0 

missing: db 0                     

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


findmissing:
    push es
    push ax
    push di
    mov ax, 0xb800
    mov es, ax
    mov di, 0

    sumofLength:
    mov si, [len]   ;si= 8
    add si,1        ; 8+1
    mov ax,si       ;=> ax= 9
    mov cx,si
    dec cx
    mul cx          ;multiply ax*cx => 9*8 = 76
    shr ax,1        ; now we have ax = 76/2 == 36
    

    sumofNumbers:

    mov si,2
    mov cx,[length]
    ;dec cx
    mov bx,[arr]
    mov [result],bx

        loop1:

        mov dx,[arr+si]
        add [result],dx
        add si,2
        loop loop1


    findMissing:
    sub ax,[result]
    mov [missing], ax ;missing element


    printnum:
    mov ax,0xb800
    mov es,ax
    mov ax,[missing]
    mov bx,10
    mov cx,0

    nextdigit:
    mov dx,0
    div bx	; ==> ax/bx ==> quotient in ax, remainder in dl
    add dl, 0x30 ;converting into hexa ascii
    push dx		; push the converted number in ascii to stack
    inc cx		;counting digits
    cmp ax,0	;if quotient is 0
    jnz nextdigit

    mov di,160

    nextpos:

    pop dx ;removing a digit from stack
    mov dh, 0x07; normal attribute
    mov [es:di],dx ;print popped dx on screen
    add di,2
    loop nextpos

    pop di
    pop ax
    pop es

    ret


start:

    call clrscr
    call findmissing
   
    mov ax, 0x4c00              
    int 0x21
