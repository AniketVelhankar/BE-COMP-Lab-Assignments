%macro print 2
	mov rax,1
	mov rdi,1
	mov rsi,%1
	mov rdx,%2
	syscall
%endmacro

%macro read 2
	mov rax,0
	mov rdi,1
	mov rsi,%1
	mov rdx,%2
	syscall
%endmacro

section .data

msg1 : db "Enter the character",10
lmsg1 : equ $-msg1

spaces : db "No. of spaces are : "
lspaces : equ $-spaces
enters : db "No. of newline characters are : ",10
lenters : equ $-enters
chars : db "No. of characters are : ",10
lchars : equ $-chars

scount : db 00H
ecount : db 00H
ccount : db 00H
count : db 00H 

section .bss
extern buffer,buffer_len,len1,len2,len3

sp_count : resb 2
ent_count : resb 2
chr_count : resb 2
ch_in : resb 2

section .text

global _start2:
global calc_space,calc_char,calc_enter

_start2:

calc_space:
mov rsi,buffer

up:
	cmp byte[rsi],20H
	jne next
	inc byte[scount]
next:
	inc rsi
	dec qword[len1]
	jnz up

mov bl,byte[scount]
mov rdi,sp_count
call h_to_a
print spaces,lspaces
print sp_count,2
ret

calc_enter:

mov rsi,buffer

up1:
	cmp byte[rsi],0x0A
	jne next1
	inc byte[ecount]
next1:
	inc rsi
	dec qword[len2]
	jnz up1

mov bl,byte[ecount]
mov rdi,ent_count
call h_to_a
print enters,lenters
print ent_count,2
ret

calc_char:

print msg1,lmsg1
read ch_in,2

mov rsi,buffer

up2:
	mov al,byte[rsi]
	cmp al,byte[ch_in]
	jne next2
	inc byte[ccount]
next2:
	inc rsi
	dec qword[len3]
	jnz up2

mov bl,byte[ccount]
mov rdi,chr_count
call h_to_a
print chars,lchars
print chr_count,2
ret

;=============================== Hex to Ascii ===================================
h_to_a :

mov byte[count],02H

UP1 :
rol bl,04
mov dl,bl
and dl,0FH
cmp dl,09H
jbe NEXT
add dl,07H

NEXT :
add dl,30H
mov byte[rdi],dl
inc rdi
dec byte[count]
JNZ UP1
ret
