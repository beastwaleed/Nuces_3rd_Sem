[org 0x0100]
jmp start
msg1: db 'Hello World',0
msg2: db 'Hello world again', 0
msg3: db 'Hello world again and again', 0 
 

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



strlen:
push bp
mov bp,sp
push bx
push cx
push dx

mov al,0
mov cx,0xffff
les di,[bp+4]

repne scasb
mov ax, 0xffff
sub ax,cx
dec ax

pop dx
pop cx
pop bx
pop bp

ret 4


printstr:
push bp
mov bp,sp
push es
push ax 
push cx
push si
push di

push ds
mov ax,[bp+4]
push ax
call strlen
cmp ax,0
jz exit

mov cx,ax
mov ax, 0xb800
mov es,ax
mov al,80
mul byte[bp+8]
add ax, [bp+10]
shl ax,1
mov di,ax

mov si,[bp+4]
mov ah,[bp+6]

cld
nextchar:
lodsb
stosw
loop nextchar

exit:
pop di
pop si
pop cx
pop ax
pop es
pop bp
ret 8


start:
 mov ah,10h	;service WRITE CHARACTER ONLY AT CURSOR POSITION
 mov al,03	;subservice 3 - toggle blinking
 mov bl,01	;enable blinking bit
 int 10h	;call BIOS video service

mov ah,0	;service 0 - get keystroke
int 16h		;call BIOS keyboard service

call clrscr	

mov ah,0	;service 0 - get keystroke
int 16h		;call BIOS keyboard service

mov ax, 30 ; push x position
push ax	
mov ax,5	;push y position
push ax

mov ax, 1	;push attribute byte
push ax
mov ax,msg1 ;push msg1
push ax
call printstr

mov ah,0	;service 0 - get keystroke
int 16h		;call BIOS keyboard service

mov ax, 30 ; push x position
push ax	
mov ax,5	;push y position
push ax

mov ax, 04 ;push attribute byte
push ax

mov ax, msg2 ;push msg2
push ax
call printstr

mov ah,0	;service 0 - get keystroke
int 16h		;call BIOS keyboard service

mov ax, 30 ; push x position
push ax	
mov ax,5	;push y position
push ax

mov ax, 05 ;push attribute byte
push ax

mov ax, msg2 ;push msg2
push ax
call printstr

mov ah,0
int 16h

mov ax, 0x4c00
int 0x21