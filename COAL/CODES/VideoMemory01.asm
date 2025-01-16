org 0x0100

mov ax, 0xb800; load video base address in ax
mov es,ax ; point es to base address
mov di,0 ; point di to top left column

nextchar: ;loop for printing till last 

; '07' represent attribute byte of black background and '20' represent space in hexa

mov word[es:di], 0x0720 
add di,2 ;add 2 to di for jumping onto next cell
cmp di,4000 ; comparing di with the last video base adress
jne nextchar

mov ax,0x4c00
int 0x21