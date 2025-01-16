[org 0x0100]
jmp start

arr: db 1,3,2,5,4,7,9,8
length: db 8
swap: db 0
minimum: db 0
maximum: db 0
median: db 0

MinMsg: db 'Minimum: '
MaxMsg: db 'Maximum: '
MedianMsg: db 'Median: '

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


BubbleSort:
    mov byte [swap], 0
    mov bx, 0

outerloop:
    mov byte [swap], 0
    mov bx, 0

innerloop:
    mov al, [arr + bx]
    cmp al, [arr + bx + 1]
    jbe noswap

    mov dl, [arr + bx + 1]
    mov [arr + bx + 1], al
    mov [arr + bx], dl
    mov byte [swap], 1

noswap:
    add bx, 1
    cmp bx, 7
    jne innerloop

    cmp byte [swap], 1
    jne outerloop

ret

StatsOfArray:
    ; Minimum is the first element after sorting
    mov al, [arr]
    mov [minimum], al

    ; Maximum is the last element after sorting
    mov al, [arr + 7]
    mov [maximum], al

    ; Calculate Median
    mov al, [length]
    mov cl, al
    shr al, 1                   ; Divide length by 2 to get the middle index
    mov si, ax                  ; Store half-length in si

    cmp cl, 2                   ; Check if length is even
    jnc evenLength              ; Jump if even

oddLength:
    mov al, [arr + si]          ; Load middle element for odd length
    mov [median], al
    jmp done

evenLength:
    mov al, [arr + si]          ; Load first middle element
    mov ah, [arr + si - 1]      ; Load second middle element
    add al, ah                  ; Add them
    shr al, 1                   ; Divide by 2
    mov [median], al            ; Store median

done:
    ret

printNumbers:
        
    push es
	push ax
	push cx
	push si 
	push di

    printMax:
	mov ax,0xb800
	mov es,ax
	mov di,160
	mov si,MaxMsg
	mov cx, 9
	mov ah,0x4F

	nextcharMax:
		mov al,[si]
		mov [es:di], ax
		add di,2
		add si,1

		loop nextcharMax

    MaxValue:
    mov di,178
    mov ah,0x4f
    mov al,[maximum]
    add al,0x30
    mov [es:di], ax
    add di,4


    printMin:
	mov ax,0xb800
	mov es,ax
	mov di,182
	mov si,MinMsg
	mov cx, 9
	mov ah,0x2F

	nextcharMin:
		mov al,[si]
		mov [es:di], ax
		add di,2
		add si,1

		loop nextcharMin

    MinValue:
    mov di,198
    mov ah,0x2F
    mov al,[minimum]
    add al,0x30
    mov [es:di], ax
    add di,2

    printMedian:
	mov ax,0xb800
	mov es,ax
	mov di,202
	mov si,MedianMsg
	mov cx, 8
	mov ah,0x1F

	nextcharMedian:
		mov al,[si]
		mov [es:di], ax
		add di,2
		add si,1

		loop nextcharMedian

    MedianValue:
    mov di,218
    mov ah,0x1F
    mov al,[median]
    add al,0x30
    mov [es:di], ax
    add di,2

	pop di
	pop si
	pop cx
	pop ax
	pop es
    ret
   

start:
    call clrscr
    call BubbleSort

    mov cx, [length]
    mov si, 0

pushElements:
    mov ch,0
    mov al, [arr + si]
    mov ah, 0
    push ax
    inc si
    loop pushElements

    call StatsOfArray
    call printNumbers
    mov ax, 0x4c00
    int 0x21
