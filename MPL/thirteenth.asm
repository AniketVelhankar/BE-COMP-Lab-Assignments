.MODEL TINY
.286
ORG 100H


CODE SEGMENT
     ASSUME CS:CODE,DS:CODE,ES:CODE
        OLD_IP DW 00
        OLD_CS DW 00
JMP INIT

MY_TSR:
        PUSH AX
        PUSH BX
        PUSH CX
        PUSH DX
        PUSH SI
        PUSH DI
        PUSH ES

        MOV AX,0B800H				;Address of Video RAM
        MOV ES,AX					;we will overwrite AX so we are storing contents of AX in ES register
        MOV DI,3650					;where to print on the dosbox

        MOV AH,02H			;To Get System Clock
        INT 1AH				;CH=Hrs, CL=Mins,DH=Sec 					
        MOV BX,CX					;we will overwrite CX so we are storing contents of AX in BX register

        MOV CL,2
LOOP1:  ROL BH,4
        MOV AL,BH
        AND AL,0FH
        ADD AL,30H
        MOV AH,17H				;color in which you'll display the value
        MOV ES:[DI],AX
        INC DI
        INC DI
        DEC CL
        JNZ LOOP1

        MOV AL,':'
        MOV AH,97H 				;color of the colon
        MOV ES:[DI],AX
        INC DI
        INC DI

        MOV CL,2
LOOP2:  ROL BL,4
        MOV AL,BL
        AND AL,0FH
        ADD AL,30H
        MOV AH,17H
        MOV ES:[DI],AX
        INC DI
        INC DI
        DEC CL
        JNZ LOOP2

        MOV AL,':'
        MOV AH,97H
        MOV ES:[DI],AX
        INC DI
        INC DI

        MOV CL,2
        MOV BL,DH 			;mov seconds value to BL

LOOP3:  ROL BL,4
        MOV AL,BL
        AND AL,0FH
        ADD AL,30H
        MOV AH,17H
        MOV ES:[DI],AX
        INC DI
        INC DI
        DEC CL
        JNZ LOOP3

        POP ES
        POP DI
        POP SI
        POP DX
        POP CX
        POP BX
        POP AX

	jmp MY_TSR

        

INIT:
        MOV AX,CS				;Initialize code and data
        MOV DS,AX

        CLI					;Clear Interrupt Flag

        MOV AH,35H			;Get Interrupt vector Data and store it
        MOV AL,08H 			;type of interrupt
        INT 21H

        MOV OLD_IP,BX
        MOV OLD_CS,ES

        MOV AH,25H			;Set new Interrupt vector
        MOV AL,08H
        LEA DX,MY_TSR
        INT 21H

        MOV AH,31H			;Make program Transient
        MOV DX,OFFSET INIT
        STI
        INT 21H

CODE ENDS

END

