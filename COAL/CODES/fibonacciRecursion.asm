org 0x0100

jmp start
number: dw 5
result: dw 0

start:
    mov ax, 0
    mov dx, 1
    mov cx, [number]
    mov si, 0
    mov [result], ax
    
    call fibonacci
    
    mov ax, 0x4c00
    int 0x21

fibonacci:
    inc si
    cmp si, cx
    jge end_fib

    mov bx, ax
    add ax, dx
    mov dx, bx
    mov [result], ax

    call fibonacci

end_fib:
    ret
