section .data
fname:	db 'arra.txt', 0
menu:	db "Menu-", 0x0A
	db "1. Ascending Order", 0x0A
	db "2. Descending Order", 0x0A
	db "3. Exit", 0x0A, "Choice: "
mlen:	equ $-menu
error:	db "File not opened successfully.", 0x0A
elen:	equ $-error
error2:	db "Incorrect Choice. Enter again.", 0x0A
elen2:	equ $-error2
msg1:	db "Enter array of single digits-", 0x0A
len1:	equ $-msg1
count:	dq 00
enter:	db 0x0A
count1:	dq 00
count2:	dq 00

section .bss
choice: resb 2
fd: resb 8
message: resb 200
buffer:	resb 200

%macro print 2
mov rax, 1
mov rdi, 1
mov rsi, %1
mov rdx, %2
syscall
%endmacro

%macro read 2
mov rax, 0
mov rdi, 0
mov rsi, %1
mov rdx, %2
syscall
%endmacro

section .text
global _start
_start:
	mov rax, 2
	mov rdi, fname
	mov rsi, 2
	mov rdx, 0777
	syscall

	mov [fd], rax
	
	bt rax, 63
	jnc cont
	print error, elen
	print enter, 1
	jmp exit

cont:	mov rax, 0
	mov rdi, [fd]
	mov rsi, message
	mov rdx, 200
	syscall
	mov qword[count1], rax

break:	
	shr rax, 01
	mov qword[count], rax
	dec qword[count]
	
	mov rax, 3
	mov rdi, qword[fd]
	syscall
	
	print menu, mlen
	read choice, 2
	cmp byte[choice], 0x31
	je up0
	cmp byte[choice], 0x32
	je fun2
	cmp byte[choice], 0x33
	je exit
	print error2, elen2
	
up0:	
	xor rax, rax
	xor rbx, rbx
	xor rcx, rcx

	mov rsi, message
	mov rdi, message+2
	mov rcx, qword[count]

up:	
	mov bl, byte[rdi]
	cmp byte[rsi], bl
	jbe down
	mov al, byte[rsi]
	mov byte[rsi], bl
	mov byte[rdi], al

down:
	add rsi, 2
	add rdi, 2
	dec rcx
	jnz up
	dec qword[count]
	jnz up0
	jmp next0
	
fun2:	
	xor rax, rax
	xor rbx, rbx
	xor rcx, rcx

	mov rsi, message
	mov rdi, message+2
	mov rcx, qword[count]

up3:	
	mov bl, byte[rsi]
	cmp byte[rdi], bl
	jbe down3
	mov al, byte[rdi]
	mov byte[rdi], bl
	mov byte[rsi], al

down3:	
	add rsi, 2
	add rdi, 2
	dec rcx
	jnz up3
	dec qword[count]
	jnz fun2
	
next0:
	print message, qword[count1]
	mov rax, 2
	mov rdi, fname
	mov rsi, 2
	mov rdx, 0777
	syscall
	
	mov qword[fd], rax

	mov rax, 1
	mov rdi, qword[fd]
	mov rsi, message
	mov rdx, qword[count1]
	syscall
	

	mov rax, 3
	mov rdi, qword[fd]
	syscall
	
exit:	
	mov rax, 60
	mov rdi, 0
	syscall


