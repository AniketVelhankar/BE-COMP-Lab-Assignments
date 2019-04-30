%macro scall 4
mov rax,%1
mov rdi,%2
mov rsi,%3
mov rdx,%4
syscall
%endmacro

section .data

array : dd 56.32, 23.4, 108.45, 372.67, 209.27
count : dw 5

title : db 0x0a,"Numbers :  ",0x0A
db "56.32, 23.4, 108.45, 372.67, 209.27", 0x0A
ltitle : equ $-title

meanm : db 0x0A,"Mean : "
lmeanm : equ $-meanm

variancem : db 0x0A,"Variance : "
lvariancem: equ $-variancem

devm : db 0x0A,"Standard deviation : "
ldevm : equ $-devm

decimal: db "."

hesc: dq 100
cnt2: db 02H

section .bss

buffer: rest 1 
dispbuffer: resb 2
mean: resd 1
variance: resd 1


section .text

global _start

_start:

scall 1,1,title,ltitle

; - - - - - - - MEAN - - - - - - - - 

xor rcx,rcx
mov cx,word[count]

FINIT 
FLDZ

mov rsi,array

up:
	FADD dword[rsi]
	add rsi,4
	loop up

FIDIV word[count]
FST dword[mean]
scall 1,1,meanm,lmeanm
call disp

;- - - - - Variance - - - - - - - 

scall 1,1,variancem,lvariancem

FLDZ
mov rcx,00
mov cx, word[count]
mov rsi,array

up1:
	FLD dword[rsi] 
	FSUB  dword[mean]
	FST ST1
	FMUL ST0,ST1
	FADD dword[variance]
	FST dword[variance] 
	add rsi,4
	loop up1

FLD dword[variance]
FIDIV word[count]

FST dword[variance]
call disp

;- - - - - Standard Deviation Calculation - - - - - 
scall 1,1, devm,ldevm
FLD dword[variance]
FSQRT
call disp

EXIT:
mov rax,60
mov rdi,0
syscall

;- - - - Disp - - - - 

disp:

	FIMUL dword[hesc]
	FBSTP [buffer] 
	xor rcx,rcx 
	mov cx,9 
	mov rsi,buffer+9 
	TOP:
		push rcx 
		push rsi
		
		mov bl,byte[rsi] 
		call HtoA  
		pop rsi
		dec rsi
		pop rcx
		dec rcx
		jnz TOP

scall 1,1,decimal,1 

;printing digits after decimal point
mov rsi,buffer
mov bl,byte[rsi] 
call HtoA
ret

;- - - -HEX TO ASCII CONVERSION - - - - -

HtoA:
mov rdi,dispbuffer
mov byte[cnt2],2H
aup:
rol bl,04
mov cl,bl
and cl,0FH
cmp cl,09H
jbe ANEXT
ADD cl,07H
ANEXT: 
add cl, 30H
mov byte[rdi],cl
INC rdi
dec byte[cnt2]
JNZ aup
scall 1,1,dispbuffer,2
ret

