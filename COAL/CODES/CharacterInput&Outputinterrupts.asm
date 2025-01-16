[org 0x0100]
jmp start

maxlength: db 80
msg1: db 'Babar Azam is $'
buffer: times 80 db 0	; buffer space for input

start:	mov cx, [maxlength]
	mov si,buffer

nextchar: 
	
	mov ah,1	;service 1 -read CHARACTER
	int 21h		;dos service

	cmp al,13	;is enter key pressed
	je exit		;yes-> leave
	mov [si],al ;no -> save this character
	inc si		; increment buffer POSITION
	loop nextchar	
	
exit: 

	mov byte[si],'$'	;appened $ to user string

	mov dx, msg1
	mov ah,09	;service for writing string ending with $
	int 21h		;dos service
	
	
	mov dx, buffer
	mov ah,09	;service for writing string ending with $
	int 21h		;dos service
	
	mov ax, 0x4c00
	int 21h