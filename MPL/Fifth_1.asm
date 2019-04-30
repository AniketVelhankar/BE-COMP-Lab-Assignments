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

%macro scall 4
	mov rax,%1
	mov rdi,%2
	mov rsi,%3
	mov rdx,%4
	syscall
%endmacro

section .data
fname : db 'abc.txt',0

menu :
	db 10,13,'-----MENU-----'
	db 10,'1.Calculate number of spaces'
        db 10,'2.Calculate number of newline characters'
        db 10,'3.Calculate occurence of a particular character'
        db 10,'4.Exit'
        db 10,'Enter your choice: '
lmenu : equ $-menu

fileopen : db "File opened successfully",10
lfileopen : equ $-fileopen
notopen : db "Error opening file",10
lnotopen : equ $-notopen
closefile : db "File closed successfully",10
lclosefile : equ $-closefile

section .bss
global fd_in,buffer,buffer_len,len1,len2,len3

choice : resb 2
len1 : resb 8
len2 : resb 8
len3: resb 8
buffer : resb 1000
buffer_len : resb 8
fd_in : resb 8

section .text
global _start:

extern calc_space,calc_enter,calc_char

_start:

;==========================Open File================================

scall 2,fname,2,777
mov qword[fd_in],rax

bt rax,63
jc next

print fileopen,lfileopen
jmp readF

next :
print notopen,lnotopen
jmp exit

;==========================Read file================================

readF:

xor rax,rax

scall 0,[fd_in],buffer,1000
mov qword[buffer_len],rax
mov qword[len1],rax
mov qword[len2],rax
mov qword[len3],rax

xor rax,rax

;=========================Perform operations=========================
operations:

print menu,lmenu
read choice,2

cmp byte[choice],31H
je space

cmp byte[choice],32H
je enter

cmp byte[choice],33H
je p_char

cmp byte[choice],34H
je exit

space:
call calc_space
jmp operations

enter:
call calc_enter
jmp operations

p_char:
call calc_char
jmp operations

exit:
call close_file
mov rax,60
mov rdi,0
syscall

close_file:
mov rax,3
mov rdi,[fd_in]
syscall
print closefile,lclosefile
ret



















