[org 0x0100]
jmp start
msg1: db 'You divided something by zero.$'

clrscr:
push ax
push bx
push cx
push dx
push di

mov ax, 0xb800
mov es,ax
mov di,0
mov cx,2000

mov ax,0x0720
rep stosw	
	
	pop di
	pop dx
	pop cx
	pop bx
	pop ax
	ret

printstr:

	; Set cursor position (INT 10h, AH=02h)
    mov ah, 02h         ; Function: Set cursor position
    mov bh, 0           ; Page number (always 0 for text mode)
    mov dh, 10   ; Row
    mov dl, 20    ; Column
    int 10h

	mov ah,09
	mov dx, msg1
	int 21h

ret

myisrfor0:
push ax
push bx
push cx
push dx
push si
push di
push bp
push ds
push es

push cs
pop ds

call clrscr
call printstr

pop di
pop si
pop dx
pop cx
pop bx
pop ax
ret

genint0:
mov ax, 0x8888
mov bl,2
div bl
ret

start:
mov ax,0
mov es,ax
mov word [es:0*4], myisrfor0
mov [es:0*4+2],cs
call genint0

mov ax, 0x4c00
int 0x21


;strlen:
;push bp
;mov bp,sp
;push bx
;push cx
;push dx
;
;mov ax,0
;mov cx,0xffff
;les di,[bp+4]
;
;repne scasb
;mov ax, 0xffff
;sub ax,cx
;dec ax
;
;pop dx
;pop cx
;pop bx
;pop bp
;
;ret 4
;

;strcmp:
;	push bp
;	mov bp,sp
;	push cx
;	push di
;	push es
;	push ds
;	
;	lds si,[bp+4]
;	les di,[bp+8]
;	
;	push ds
;	push si
;	call strlen
;	mov cx,ax
;	
;	push es
;	push di
;	call strlen
;	cmp cx, ax
;	jne exitfalse
;	
;	mov ax,1
;	repe cmpsb
;	jcxz exitTrue
;	
;	exitfalse:
;	mov ax,0
;	
;	exitTrue:
;	pop ds
;	pop es
;	pop di
;	pop cx
;	pop bp
;	ret 8

;start:
	;
	;push ds
	;mov ax, msg1
	;push ax
	;
	;push ds
	;mov ax,msg2
	;push ax
	;
	;call strcmp
	
 ; Compare msg1 and msg3
  ; push ds
  ; mov ax, msg1
  ; push ax
  ; push ds
  ; mov ax, msg2
  ; push ax
  ; call strcmp
  
	
;	mov ax, 0x4c00
;	int 0x21