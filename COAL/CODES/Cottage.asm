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
    mov word [es:di], 0x072D  ; draw '-'
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


printline:
    push bp
    mov bp, sp

    mov ax, 0xb800
    mov es, ax

    mov al, 80
    mul byte [bp+4]  ; y-position
    add ax, [bp+6]   ; x-position
    shl ax, 1
    mov di, ax       ; calculate starting position

    mov ah, 0x07   
    mov cx,40

    loop1:
    mov al, 0x2D ;(Asci of '-' is '2D')
    mov word [es:di], ax
    add di,2
    loop loop1

    pop bp
    ret 4

printLastLine:
    push bp
    mov bp, sp

    mov ax, 0xb800
    mov es, ax

    mov al, 80
    mul byte [bp+4]  ; y-position
    add ax, [bp+6]   ; x-position
    shl ax, 1
    mov di, ax       ; calculate starting position

    mov cx, 1        ; start with 1 star
    mov bx, di

    lloop:
    add di,158
    add cx,2
    cmp cx,13
    jne lloop

    mov ah, 0x07   
    mov cx,50

    lloop1:
    mov al, 0x2D ;(Asci of '-' is '2D')
    mov word [es:di], ax
    add di,2
    loop lloop1

    pop bp
    ret 4

closingLine:
    ;mov di,0
    push bp
    mov bp, sp

    mov ax, 0xb800
    mov es, ax

    mov al, 80
    mul byte [bp+4]     ; y-position (row number)
    add ax, [bp+6]       ; x-position (column number)
    shl ax, 1            
    mov di, ax           ; set starting position in video memory

    add di, 240          ; move to the next row (160 bytes forward)

    mov ah, 0x07         ; white on black attribute
    mov cx, 6            ; draw 6 '-' characters vertically

newloop:

    mov al, 0x2D         ; ASCII code for '-'
    mov word [es:di], ax ; store character and attribute in video memory
    add di, 162         ; move to the next row with a 2 byte shift
    loop newloop        

    pop bp
    sub di,2
    ret 4

    
    
verticallastline:
mov cx,13
;mov ah,0x07
    newloop2:
    mov ax, 0xb800
    mov es, ax
    mov ax, 0x072D         ; ASCII code for '-'
    mov word [es:di], ax ; store character and attribute in video memory
    add di, 160         ; move to the next row with a 2 byte shift
    loop newloop2  
    ret

verticalLine1:
mov di,1778
mov cx,13
;mov ah,0x07
    newloop3:
    mov ax, 0xb800
    mov es, ax
    mov ax, 0x072D         ; ASCII code for '-'
    mov word [es:di], ax ; store character and attribute in video memory
    add di, 160         ; move to the next row with a 2 byte shift
    loop newloop3  
    ret

verticalLine2:
mov di,1800
mov cx,13
;mov ah,0x07
    newloop4:
    mov ax, 0xb800
    mov es, ax
    mov ax, 0x072D         ; ASCII code for '-'
    mov word [es:di], ax ; store character and attribute in video memory
    add di, 160         ; move to the next row with a 2 byte shift
    loop newloop4  
    ret


belowline:
sub di,22
mov cx, 50
     
    mov ah, 0x07  

    llloop1:
    mov al, 0x2D ;(Asci of '-' is '2D')
    mov word [es:di], ax
    add di,2
    loop llloop1

    ret

roof:
    mov di, 834          
    mov cx, 20           
    mov ah, 0x07         
    mov bx, 2            
    mov si, 0            

roof_loop:
    cmp si, cx           
    je roof_end          

    mov al, 0x2F         
    mov word [es:di], ax 

    add di, 2            

    cmp di, 1722         
    jne roof_row_end     

roof_row_end:
    add di, 160          
    add di, bx           
    add bx, 2            
    inc si               
    jmp roof_loop        

roof_end:
    ret                  



start:
    call clrscr
    mov ax, 15        ; starting x position
    push ax
    mov ax, 5         ; y position
    push ax
    call pyramid

    mov ax, 15        ; starting x position 
    push ax
    mov ax, 5         ; y position
    push ax
    call printline

    mov ax, 15        ; starting x position
    push ax
    mov ax, 5         ; y position
    push ax
    call printLastLine

    mov ax, 15        ; starting x position
    push ax
    mov ax, 5  
    push ax
    call closingLine
    call verticallastline
    call verticalLine1
    call verticalLine2
    call belowline
    call roof
    mov ax, 0x4c00
    int 0x21