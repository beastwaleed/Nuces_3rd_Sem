[org 0x0100]
jmp start

arr:	 	dw 1, 2, 3, 4
arrSize:	dw 8

counting:
	xor si, si

	checkOneZero:
		mov ax, [arr+si]       
		test ax, 1        		
		jz countZero           

		mov cx, 0              
		mov dx, 16             

	countOne:
		shr ax, 1              
		jnc skipOne            
		inc cx                 

	skipOne:
		dec dx
		jnz countOne
		mov [arr+si], cx       ; Store count in array
		jmp doneCounting

	countZero:
		mov cx, 0              
		mov dx, 16             ; 16-bit count

	countZeroLoop:
		shr ax, 1              
		jc skipZero            
		inc cx                 

	skipZero:
		dec dx
		jnz countZeroLoop
		mov [arr+si], cx       ; Store count of zeros in array

	doneCounting:
		add si, 2              
		cmp word si, [arrSize]
		jne checkOneZero
    
		ret

start:
    call counting
	
    mov ax, 0x4c00
    int 0x21