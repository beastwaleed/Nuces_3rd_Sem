org 0x0100
jmp start

arr: dw 1, 2, 3, 4
length: dw 8

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


bitCounting:
	mov si, 0

checkOneZero:
    mov ax, [arr+si]       ; take number from array into ax
    test ax, 1             ; Check if number is even or odd
    jz countZero           ; If even, jump to countZero

    mov cx, 0              ; set count for ones
    mov dx, 16             ; Process 16 bits

countOne:
    shr ax, 1              ; Shift right to isolate bits
    jnc skipOne            ; If carry is clear, skip increment
    inc cx                 ; Increment count for ones

skipOne:
    dec dx
    jnz countOne
    mov [arr+si], cx       ; Store count of ones back in array
    jmp doneCounting

countZero:
    mov cx, 0              ; Initialize count for zeros
    mov dx, 16             ; Process 16 bits

countZeroLoop:
    shr ax, 1              ; Shift right to isolate bits
    jc skipZero            ; If carry is set, skip increment
    inc cx                 ; Increment count for zeros

skipZero:
    dec dx
    jnz countZeroLoop
    mov [arr+si], cx       ; Store count of zeros back in array

doneCounting:
    add si, 2              ; Move to the next word in the array
    cmp word si, [length]
    jne checkOneZero
    
    ret

printnum:
    push bp
    mov bp, sp
    push es
    push ax
    push bx
    push cx
    push dx
    push di

    mov ax, 0xb800
    mov es, ax
    mov si, 0               ; Reset array index

    mov di, 160
print_loop:
    mov ax, [arr+si]       ; Load word from array into AX
    mov bx, 10
    mov cx, 0

nextdigit:
    mov dx, 0
    div bx                 ; Divide AX by 10 to isolate each digit
    add dl, 0x30           ; Convert remainder to ASCII
    push dx                ; Store digit on the stack
    inc cx                 ; Count digits
    cmp ax, 0              ; Check if quotient is zero
    jnz nextdigit

    ;add di, si             ; Update display offset based on array index
    ;add di, si             ; Adjust position on screen

nextpos:
    pop dx                 ; Retrieve each digit from stack
    mov dh, 0x07           ; Set attribute for display
    mov [es:di], dx        ; Display digit on screen
    add di, 2              ; Move to next display position
    loop nextpos           ; Repeat for all digits

    add si, 2              ; Move to next word (16-bit) element in array
	add di, 2
    cmp si, [length]
    jl print_loop          ; Repeat for all elements in array

    pop di
    pop dx
    pop cx
    pop bx
    pop ax
    pop es
    
	mov bp, sp
	pop bp
	
    ret 

start:
    call clrscr
    call bitCounting
	call printnum
    mov ax, 0x4c00
    int 0x21