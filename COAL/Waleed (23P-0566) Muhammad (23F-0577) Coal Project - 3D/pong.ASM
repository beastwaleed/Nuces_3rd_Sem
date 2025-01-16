[org 0x0100]
jmp start

; Variables

DotX:       dw 0A0h        ; xStarting-position
DotY:       dw 64h         ; yStarting-position
DotSize:    dw 04h         ; Ball size
DotSpeedX:  dw 05h         ; x speed
DotSpeedY:  dw 02h         ; y speed
Width:      dw 140h        ; Screen width (320 in mode 13h)
Height:     dw 0C8h        ; Screen height (200 in mode 13h)
padding:    dw 6           ; Padding around the edges
DotXCentre: dw 0A0h        ;Centre Postion X
DotYCentre: dw 64h         ;Centre Position Y
PeddleLeftX: dw 1Eh         ;Starting Postion X of Left Peddle
PeddleLeftY: dw 0Bh         ;Starting Postion Y of Left Peddle
PeddleLeftWidth:dw 05h      ;Width of Left Peddle
PeddleLeftHeight:dw 1Fh     ; Height of Left Peddle
PeddleRightX: dw 120h         ;Starting Postion X of Right Peddle
PeddleRightY: dw 0Bh         ;Starting Postion Y of Right Peddle
PeddleRightWidth:dw 05h      ;Width of  Right Peddle
PeddleRightHeight:dw 1Fh     ;Height of Right Peddle
PeddleVelocity:dw 0Ah        ; The velocity of peddle to move up or down

PLeftPoint:dw 00             ;Left Player Points
PRightPoint: dw 00           ;Right Player Points

ShowPlayerOne: db '0','$'    ;Player one text showing
ShowPlayerTwo:db '0','$'     ;Player two text showing
TextGameOver: db 'Game Over' , '$'

WinnerIndex: db 0  
GameWinner : db ' Player 1 Won!!' ,'$'

PlayAgain: db 'Press R to Restart','$'

MainMenu: db 'Press E to Main Menu','$'
MainMenuTitle: db 'Main Menu','$'
StartGame: db 'Press S to start the Game','$'
ExitGame: db 'Press E to Exit The Game','$'
Goals: db 'Enter Number of Goals to Win  ','$'

GamePaused: db 0	;flag for game pause / unpause (0=running , 1=pause)

PlayerPoint: dw 0



BorderLeftX: dw 02h         ;Starting Postion X of Left Peddle
BorderLeftY: dw 02h         ;Starting Postion Y of Left Peddle
BorderWidth:dw 01h      ;Width of Left Peddle
BorderHeight:dw 192     ; Height of Left Peddle
BorderRightX: dw 139h         ;Starting Postion X of Right Peddle
BorderRightY: dw 02h         ;Starting Postion Y of Right Peddle
BorderWidthN:dw 136h      ;Width of Left Peddle
BorderHeightN:dw 02h     ; Height of Left Peddle

BorderTopY: dw 02h          ; Starting Y of Top Border
BorderBottomY: dw 194      ; Starting Y of Bottom Border


; Function: Draw Borders
Border:
    ; Draw Left Vertical Border
    mov cx, [BorderLeftX]   ; Start x-coordinate
    mov dx, [BorderLeftY]   ; Start y-coordinate
DrawLeftBorder:
    mov ah, 0Ch             ; Write pixel function
    mov al, 0x03            ; Cyan color
    int 0x10                ; BIOS interrupt to draw
    inc dx                  ; Move down
    mov ax, dx
    sub ax, [BorderLeftY]
    cmp ax, [BorderHeight]  ; Check if height reached
    jl DrawLeftBorder       ; Repeat for full height

    ; Draw Right Vertical Border
    mov cx, [BorderRightX]  ; Start x-coordinate
    mov dx, [BorderRightY]  ; Start y-coordinate
DrawRightBorder:
    mov ah, 0Ch             ; Write pixel function
    mov al, 0x03            ; Cyan color
    int 0x10                ; BIOS interrupt to draw
    inc dx                  ; Move down
    mov ax, dx
    sub ax, [BorderRightY]
    cmp ax, [BorderHeight]  ; Check if height reached
    jl DrawRightBorder      ; Repeat for full height

    ; Draw Top Horizontal Border
    mov cx, 02h   ; Start x-coordinate
    mov dx, [BorderTopY]    ; Top border y-coordinate
DrawTopBorder:
    mov ah, 0Ch             ; Write pixel function
    mov al, 0x03            ; Cyan color
    int 0x10                ; BIOS interrupt to draw
    inc cx                  ; Move right
    mov ax, cx
    sub ax, 02h
    cmp ax, 138h   ; Check if width reached
    jl DrawTopBorder        ; Repeat for full width

    ; Draw Bottom Horizontal Border
    mov cx, 02h   ; Start x-coordinate
    mov dx, [BorderBottomY] ; Bottom border y-coordinate
DrawBottomBorder:
    mov ah, 0Ch             ; Write pixel function
    mov al, 0x03            ; Cyan color
    int 0x10                ; BIOS interrupt to draw
    inc cx                  ; Move right
    mov ax, cx
    sub ax, 02h
    cmp ax, 138h   ; Check if width reached
    jl DrawBottomBorder     ; Repeat for full width

    ret   


; Function: PlaySound
; Description: Generates a sound using the PC speaker
; Input: AX = frequency (in Hz)

PlaySound:
    ; Convert frequency to divisor for PIT
    mov bx, 11931       ; PIT base frequency
    div bx                ; AX = divisor

    ; Send command to PIT
    mov al, 0xB6          ; Channel 2, low/high byte, square wave
    out 0x43, al
    mov al, bl            ; Low byte of divisor
    out 0x42, al
    mov al, bh            ; High byte of divisor
    out 0x42, al

    ; Enable the speaker
    in al, 0x61
    or al, 0x03           ; Set bits 0 and 1
    out 0x61, al

    ; Delay for sound duration
    mov cx, 5000          ; Adjust for duration
SoundDelay:
    loop SoundDelay

    ; Disable the speaker
    in al, 0x61
    and al, 0xFC          ; Clear bits 0 and 1
    out 0x61, al

    ret



inputScore:
    call clrscr               ; Clear the screen
    mov ah, 02h               ; Set cursor position
    mov bh, 00h               ; Page 0
    mov dh, 06h               ; Row 6
    mov dl, 08h               ; Column 8
    int 10h

    mov ah, 09h               ; Display string
    lea dx, [Goals]           ; Prompt for input
    int 21h

    mov ah, 01h               ; Wait for key press
    int 21h
    sub al, 30h               ; Convert ASCII to numeric
    movzx ax, al              ; Zero-extend AL to AX
    mov [PlayerPoint], ax     ; Store in PlayerPoint

    ret


exitscr:
			
			mov ah,00h                   ;set the configuration to video mode
			mov al,02h                   ;choose the video mode
			int 10h    					 ;execute the configuration 
		
			mov ah,0Bh 					 ;set the configuration
			mov bh,00h 					 ;to the background color
			mov bl,00h 					 ;choose black as background color
			int 10h    					 ;execute the configuration
			
			ret
clrscr:
			
			mov ah,00h                   ;set the configuration to video mode
			mov al,13h                   ;choose the video mode
			int 10h    					 ;execute the configuration 
		
			mov ah,0Bh 					 ;set the configuration
			mov bh,00h 					 ;to the background color
			mov bl,00h 					 ;choose black as background color
			int 10h    					 ;execute the configuration
			
			ret

checkPause:
	mov ah,01h	;check if key is pressed
	int 16h	;interupt for keyboard
	jz continueGame		
	
	mov ah, 00h	;get the key press
	int 16h
	cmp al, 'P'
	je togglePause
	
	cmp al, 'p'
	je togglePause
	
	continueGame:
	ret
	
	togglePause:
	mov al, [GamePaused]
	xor al,1	;Toggle the pause state (0->1, 1->0)
	mov [GamePaused],al
	
ret
	
	


; Clear the area where the ball was previously drawn
clearBall:
    mov cx, [DotX]         ; Start x-coordinate
    mov dx, [DotY]         ; Start y-coordinate

ClearHorizontal:
    mov ah, 0Ch            ; Write pixel function
    mov al, 0x00           ; Black color (background)
    int 0x10               ; Call BIOS interrupt to draw
    inc cx 
    mov ax, cx
    sub ax, [DotX]
    cmp ax, [DotSize]
    jng ClearHorizontal
    mov cx , [DotX]
    inc dx

    mov ax, dx
    sub ax, [DotY]
    cmp ax, [DotSize]
    jng ClearHorizontal

    ret

; Update the dot's position
moving:

    mov ax, [DotSpeedX]
    add [DotX], ax
    cmp word[DotX], ax
    jl GivePointtoTwo        ;jumping to give point to player tw

    mov ax, word[Width]
    sub ax, word[DotSize]
    sub ax, [padding]
    cmp word[DotX], ax
    jg GivePointtoOne         ;jumpint to give point to player one
    jmp moveVertically



GivePointtoOne:               ;small loop for giving point to left plyaer
inc word[PLeftPoint]
call PlaySound
    call RestartCentre
        call updateScoreOne
        mov ax,word[PlayerPoint]
    cmp word[PLeftPoint],ax
    jge GameOver
	
 ret

 GivePointtoTwo:                ;small loop for giving point to left plyaer
inc byte[PRightPoint]
call PlaySound
 call RestartCentre
 call updateScoreTwo
 mov ax,word [PlayerPoint]
 cmp word[PRightPoint],ax
     jge GameOver

 ret

skipMovement:
ret

 GameOver:                   ;  Game Over loop

  mov ax,word[PlayerPoint]

	cmp word[PLeftPoint], ax
	jnl WinPone
	jmp WinPTwo
	
	WinPone:
	mov word[WinnerIndex], 01h
	jmp continueGameOver
	
	WinPTwo:
	mov word[WinnerIndex], 02h
	jmp continueGameOver
	
	
	continueGameOver:
	mov word[PLeftPoint],00h
	mov word[PRightPoint],00h
	call DrawOverMenu
    call updateScoreOne
    call updateScoreTwo
	
	jmp exit
	
	ret
 
 DrawOverMenu:
  call clrscr
 
  mov ah,02h
  mov bh,00h
  mov dh,04h
  mov dl,10h
  int 10h
  
  mov ah,09h
  lea dx,[TextGameOver]
  int 21h
  
  mov ah,02h
  mov bh,00h
  mov dh,06h
  mov dl,10h
  int 10h
  
  call updateWin
  
  mov ah,09h
  lea dx,[GameWinner]
  int 21h
  
  ;restart message
  mov ah,02h
  mov bh,00h
  mov dh,08h
  mov dl,10h
  int 10h
  
  mov ah,09h
  lea dx,[PlayAgain]
  int 21h
 

 
  ;Main menu message
  mov ah,02h
  mov bh,00h
  mov dh,0Ah
  mov dl,10h
  int 10h
  
  mov ah,09h
  lea dx,[MainMenu]
  int 21h
 ;wait for keypress
	mov ah,00h
	int 16h
;For Restarting Game
	cmp al, 'R'
	je Restart
	cmp al , 'r'
	je Restart


    ;For Goint to Main Menu of Game
	cmp al, 'E'
	je DrawMainMenu
	cmp al , 'e'
	je DrawMainMenu
	ret
;
 updateWin:
 mov al,byte[WinnerIndex]
 add al,0x30
 mov byte[GameWinner+8],al 
 ret
   
Restart:
	mov word[PLeftPoint],00h
	mov word[PRightPoint],00h
     call updateScoreOne
    call updateScoreTwo
call start
ret


DrawMainMenu:

  call clrscr


;Main menu Title
  mov ah,02h
  mov bh,00h
  mov dh,06h
  mov dl,08h
  int 10h
  
  mov ah,09h
  lea dx,[MainMenuTitle]
  int 21h


 ;SinglePlayer text
  mov ah,02h
  mov bh,00h
  mov dh,08h
  mov dl,08h
  int 10h
  
  mov ah,09h
  lea dx,[StartGame]
  int 21h


;Exit Text
  mov ah,02h
  mov bh,00h
  mov dh,0Ah
  mov dl,08h
  int 10h
  
  mov ah,09h
  lea dx,[ExitGame]
  int 21h

  ;wait for keypress
	mov ah,00h
	int 16h

    ;For Restarting Game
	cmp al, 'S'
	je Restart
	cmp al , 's'
	je Restart


    ;For Goint to Main Menu of Game
	cmp al, 'E'
	je QuitGame
	cmp al , 'e'
	je QuitGame

ret



QuitGame:
call exitscr
mov al,00h
mov ah,0x4c
int 0x21
ret

   ;Restrating from centre after colliding with left and right Wall
RestartCentre:
    mov ax,[DotXCentre]
    mov [DotX],ax

    mov ax,[DotYCentre]
    mov [DotY],ax
    neg word[DotSpeedX]
    neg word[DotSpeedY]
    ret

    ; Remaining part of the Moving Ball
 moveVertically:
    mov ax, word[DotSpeedY]
    add word[DotY], ax
    cmp word[DotY], 2

    jl reverseSpeedY

    mov ax, word[Height]
    sub ax, word[DotSize]
    sub ax, [padding]
    cmp word[DotY], ax
    jg reverseSpeedY

    mov ax,[DotX]
    add ax,[DotSize]
    cmp ax,[PeddleRightX]
    jng checkwithLeft


    mov ax,[PeddleRightX]
    add ax,[PeddleRightWidth]
    cmp [DotX],ax
    jnl checkwithLeft


    mov ax,[DotY]
    add ax,[DotSize]
    cmp ax,[PeddleRightY]
    jng checkwithLeft


    mov ax,[PeddleRightY]
    add ax,[PeddleRightHeight]
    cmp [DotY],ax
    jnl checkwithLeft

    jmp  reverseSpeedX

checkwithLeft:
    mov ax,[DotX]
    add ax,[DotSize]
    cmp ax,[PeddleLeftX]
    jng ExitCollision

    mov ax,[PeddleLeftX] 
    add ax,[PeddleLeftWidth]
    cmp [DotX],ax
    jnl ExitCollision

    mov ax,[DotY]
    add ax,[DotSize]
    cmp ax,[PeddleLeftY]
    jng ExitCollision

    mov ax,[PeddleLeftY]
    add ax,[PeddleLeftHeight]
    cmp [DotY],ax
    jnl ExitCollision



   jmp  reverseSpeedX
reverseSpeedY:
    neg word [DotSpeedY]
    ret
reverseSpeedX:
    neg word [DotSpeedX]
    ret
    
    ExitCollision:
    ret
 
 

 
; Draw the ball at its current position
drawBall:
    mov cx, [DotX]         ; Start x-coordinate
    mov dx, [DotY]         ; Start y-coordinate

DotHorizontal:
    mov ah, 0Ch            ; Write pixel function
    mov al, 0x0f           ; White color
    int 0x10               ; Call BIOS interrupt to draw
    inc cx 
    mov ax, cx
    sub ax, [DotX]
    cmp ax, [DotSize]
    jng DotHorizontal
    mov cx , [DotX]
    inc dx

    mov ax, dx
    sub ax, [DotY]
    cmp ax, [DotSize]
    jng DotHorizontal

    ret


ClearPeddl:
    mov cx, [PeddleLeftX]         ; Start x-coordinate
    mov dx, [PeddleLeftY]         ; Start y-coordinate

PeddlLeftHorizontal1:
    mov ah, 0Ch            ; Write pixel function
    mov al, 0x00           ; black color
    int 0x10               ; Call BIOS interrupt to draw
    inc cx 
    mov ax, cx
    sub ax, [PeddleLeftX]
    cmp ax, [PeddleLeftWidth]
    jng PeddlLeftHorizontal1
    mov cx , [PeddleLeftX]
    inc dx

    mov ax, dx
    sub ax, [PeddleLeftY]
    cmp ax, [PeddleLeftHeight]
    jng PeddlLeftHorizontal1


    mov cx, [PeddleRightX]         ; Start x-coordinate
    mov dx, [PeddleRightY]         ; Start y-coordinate

PeddlRightHorizontal1:
    mov ah, 0Ch            ; Write pixel function
    mov al, 0x00           ; White color
    int 0x10               ; Call BIOS interrupt to draw
    inc cx 
    mov ax, cx
    sub ax, [PeddleRightX]
    cmp ax, [PeddleRightWidth]
    jng PeddlRightHorizontal1
    mov cx , [PeddleRightX]
    inc dx

    mov ax, dx
    sub ax, [PeddleRightY]
    cmp ax, [PeddleRightHeight]
    jng PeddlRightHorizontal1
	
    ret


drawPeddl:
    mov cx, [PeddleLeftX]         ; Start x-coordinate
    mov dx, [PeddleLeftY]         ; Start y-coordinate

PeddlLeftHorizontal:
    mov ah, 0Ch            ; Write pixel function
    mov al, 0x05          ; White color
    int 0x10               ; Call BIOS interrupt to draw
    inc cx 
    mov ax, cx
    sub ax, [PeddleLeftX]
    cmp ax, [PeddleLeftWidth]
    jng PeddlLeftHorizontal
    mov cx , [PeddleLeftX]
    inc dx

    mov ax, dx
    sub ax, [PeddleLeftY]
    cmp ax, [PeddleLeftHeight]
    jng PeddlLeftHorizontal


    mov cx, [PeddleRightX]         ; Start x-coordinate
    mov dx, [PeddleRightY]         ; Start y-coordinate

PeddlRightHorizontal:
    mov ah, 0Ch            ; Write pixel function
    mov al, 0x06           ; White color
    int 0x10               ; Call BIOS interrupt to draw
    inc cx 
    mov ax, cx
    sub ax, [PeddleRightX]
    cmp ax, [PeddleRightWidth]
    jng PeddlRightHorizontal
    mov cx , [PeddleRightX]
    inc dx

    mov ax, dx
    sub ax, [PeddleRightY]
    cmp ax, [PeddleRightHeight]
    jng PeddlRightHorizontal
ret



movPeddle:
;left Peddle movement
;check if key is being presseed(If not check the other peddle)
mov ah,01h
int 16h
jz RightPeddleMovement
                          ;check which key is being pressed(AL = ASCII character)
mov ah,00h
int 16h
                          ;if is 'w' or 'W' move up

cmp al,77h                ;for 'w'
jz moveLeftPeddleUp

cmp al,57h                ;for 'W'
jz moveLeftPeddleUp

                          ;if is 's' Or 'S' move down

cmp al,73h                ;for 's'
jz moveLeftPeddleDown

cmp al,53h                ;for 'S'
jz moveLeftPeddleDown
jmp RightPeddleMovement

moveLeftPeddleUp:
mov ax,[PeddleVelocity]
sub [PeddleLeftY],ax

mov ax,[padding]
cmp [PeddleLeftY],ax
jl fixLeftPeddleTop
jmp RightPeddleMovement


fixLeftPeddleTop:
mov ax,[padding]
mov [PeddleLeftY],ax
jmp RightPeddleMovement


moveLeftPeddleDown:
mov ax,[PeddleVelocity]
add [PeddleLeftY],ax
mov ax,[Height]
sub ax,[padding]
sub ax,[PeddleLeftHeight]
cmp [PeddleLeftY],ax
jg fixLeftPeddleBottom
jmp RightPeddleMovement


fixLeftPeddleBottom:
mov [PeddleLeftY],ax
jmp RightPeddleMovement


;Right Peddle movement

RightPeddleMovement:

;check if key is being presseed(If not Exit Programm)


   ;if is 'o' or 'O' move up

cmp ah,48h                ;for 'up arrow'
jz moveRightPeddleUp

cmp ah,50h                ;for 'down arrow'
jz moveRightPeddleDown


jmp ExitPeddleMovement


moveRightPeddleUp:
mov ax,[PeddleVelocity]
sub [PeddleRightY],ax

mov ax,[padding]
cmp [PeddleRightY],ax
jl fixRightPeddleTop
jmp ExitPeddleMovement


fixRightPeddleTop:
mov ax,[padding]
mov [PeddleRightY],ax
jmp ExitPeddleMovement


moveRightPeddleDown:
mov ax,[PeddleVelocity]
add [PeddleRightY],ax
mov ax,[Height]
sub ax,[padding]
sub ax,[PeddleRightHeight]
cmp [PeddleRightY],ax
jg fixRightPeddleBottom
jmp ExitPeddleMovement


fixRightPeddleBottom:
mov [PeddleRightY],ax
jmp ExitPeddleMovement


ExitPeddleMovement:
ret


DrawScore:  ;Code for Drawing score on screen
;for Left Peddle Score
  mov ah,02h
  mov bh,00h
  mov dh,02h
  mov dl,06h
  int 10h
  
  mov ah,09h
  lea dx,[ShowPlayerOne]
int 21h

;for Right Peddle
  mov ah,02h
  mov bh,00h
  mov dh,02h
  mov dl,1Fh
  int 10h
  
  mov ah,09h
  lea dx,[ShowPlayerTwo]
int 21h

ret

updateScoreOne:     ;Subroutine for updating player one
xor ax,ax
mov al,[PLeftPoint]

add al,30h
mov [ShowPlayerOne],al

ret


updateScoreTwo:      ;Subroutine for updating player one

xor ax,ax
mov al,[PRightPoint]

add al,30h
mov [ShowPlayerTwo],al

ret

 
; Main program

start:
call inputScore
    ; Set graphics mode (Mode 13h - 320x200, 256 colors)
    mov ax, 0x0013
    int 0x10

main_loop:
	call checkPause
	mov al, [GamePaused]
	cmp al,1
	je playTheGame
	
	call Border
    call clearBall           ; Clear the old ball
    call moving              ; Update position
    call drawBall            ; Draw the new ball
	
    call ClearPeddl
    call movPeddle
    call drawPeddl           ; Draw the both Peddles
    call DrawScore
	

 ; Small delay for smooth movement

mov cx, 0FFFFh          ; Delay loop
delay_loop:
loop delay_loop

inner:
    loop inner

    mov cx,0xffbb
inner1:
    loop inner1
	jmp main_loop           ; Repeat the loop


playTheGame:
jmp main_loop

; Exit to DOS
exit:
    mov ax, 0x4c00
    int 0x21


	