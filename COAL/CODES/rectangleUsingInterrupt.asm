[org 0x0100] 
 
	mov ah,00h
	mov al,13h
	int 10h
	
	mov ah,0ch
	mov al, 0x03 
	mov bx,0
	
	mov cx,50 	;x
	mov dx,20	;y
	
l1:	
	int 10h
	dec cx
	cmp cx,4
	jne l1
	

	mov cx, 50
	mov dx, 30
	
	l2:	int 10h
	dec cx
	cmp cx,4
	jne l2
	
	mov cx,50
	mov dx,21
	
	mov si,10
	
	l3:
	int 10h
	inc dx
	dec si
	cmp si,0
	jnz l3
	
	mov cx,50
	mov dx,26
	int 10h
	
	
	mov cx,4
	mov dx,21
	
	mov si,10
	
	l4:
	int 10h
	inc dx
	dec si
	cmp si,0
	jnz l4
	
	mov cx,50
	mov dx,26
	int 10h
		
		
	mov ax,0x4c00
	int 0x21

