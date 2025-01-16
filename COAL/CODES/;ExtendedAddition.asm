;Extended Addition

org 0x0100
num1: dd 40000
num2: dd 500

mov ax,[num2]

add word [num2],ax
mov ax, [num2+2]
adc word[num1+2],ax

mov ax, 0x4c00
int 0x21
