org 0x0100
jmp start
okay: db 'OKAY' ,0
notOkay: db 'Not Okay',0
Eq: db 'Equation: ',0
Check: db 'Checking Equation....',0
LHS: dw 0
RHS: db 0
Equation: db 0,0,0,0,0

clrscr:
push es
push ax
push di
mov ax, 0xb800
mov es, ax
mov di,0
mov ah, 0x07
mov al, 0x20
mov cx,2000
cld
rep stosw
pop di
pop ax
pop es
ret

inputRoutine:
push ax

push bx
push cx
push dx
push es
push si

;mov ah, 1 ;set key buffer
;int 16h ;sets keyboard interrupt
mov di, Equation
	
	inputLoop:
mov ah, 0 ; Wait for a key press
int 16h ; Get key input
cmp al, 13 ; Check if Enter (ASCII 13) is pressed
je inputEnd ; If Enter, terminate input
stosb ; Store the character in Equation and increment DI
jmp inputLoop ; Continue taking input
	
	inputEnd:
mov byte[di],0
pop di
pop es
pop dx
pop cx
pop bx
pop ax
ret

printEquation:
push ax
push bx
push cx
push dx
push es
push si
push di
mov ax, 0xb800
mov es,ax
	
printMsg:
mov di,370
mov si,Eq
mov ah,0x04
cld

	MsgLoop:
lodsb
cmp al,0
je next
stosw
jmp MsgLoop

	next:
mov di,390

mov si,Equation
mov ah,0x07
mov al,[si]
cld

	printLoop:
lodsb
cmp al,0
je printEnd
stosw
jmp printLoop

	printEnd:
mov di,530
mov si,Check
mov ah,0x07
;mov al,[si]
cld

	CheckPrintLoop:
lodsb
cmp al,0
je EndFunc
stosw
jmp CheckPrintLoop

EndFunc:
pop di
pop si
pop es
pop dx
pop cx
pop bx
pop ax
ret

formNumber:

mov al, [Equation]
sub al, 0x30
mov bl, al
mov al, [Equation+2]
sub al, 0x30
mov bh, al
mov al, [Equation+1]
cmp al, 43
je add_numbers
cmp al, 45
je subtract_numbers

cmp al, 42
je multiply_numbers

mov word [LHS], 0
jmp end_formNumber

add_numbers:
mov ax, 0
mov al, bl
add al, bh
jmp store_result

subtract_numbers:
mov ax, 0
mov al, bl
sub al, bh
jmp store_result

multiply_numbers:
mov ax, 0
mov al, bl
mul bh
jmp store_result

store_result:
mov [LHS], ax

end_formNumber:
ret

tokenizerRoutine:
push ax
push bx
push cx
push dx
push es
push si
push di
xor di,di
mov ax,0xb800
mov es,ax

mov al, [Equation+4]
sub al,0x30
cmp [LHS],al
jne printNotOkay

;else Okay
printOkay:
mov di,800
mov ah,0x02
mov si,okay
cld

OkayLoop:
lodsb
cmp al,0
je next
stosw

jmp OkayLoop
cmp al,0
je doneLoop

printNotOkay:
mov di,830
mov ah,0x04
mov si,notOkay
cld
NotOkayLoop:
lodsb
cmp al,0
je next
stosw
jmp NotOkayLoop

doneLoop:
pop di
pop si
pop es
pop dx
pop cx
pop bx
pop ax
ret



start:
call clrscr
call inputRoutine
call printEquation
call formNumber
call tokenizerRoutine
mov ax, 0x4c00
int 0x21