%macro print 2
	mov rax,1
	mov rdi,1
	mov rsi,%1
	mov rdx,%2
	syscall
%endmacro

section .data

msg : db "Factorial is : "
lmsg : equ $-msg

count : db 00H

section .bss

factno : resb 4

section .text

global _start:

_start :

pop rbx ;;argc
pop rbx ;;./fact
pop rbx ;;number

mov al,byte[rbx]
cmp al,39H
jbe next
sub al,07H
next:
sub al,30H

P:
push ax
inc byte[count]
dec ax
cmp ax,01H
jg P

xor rax,rax
mov eax,01H

_facto:
pop bx
mul bx
dec byte[count]
jnz _facto

xor rbx,rbx
mov bx,ax
mov rdi,factno
call h_to_a

exit:
mov rax,60
mov rdi,0
syscall

;==================================================

h_to_a :

mov byte[count],04H

UP1 :
rol bx,04
mov dl,bl
and dl,0FH
cmp dl,09H
jbe NEXT1
add dl,07H

NEXT1 :
add dl,30H
mov byte[rdi],dl
inc rdi
dec byte[count]
JNZ UP1

print factno,4
ret


