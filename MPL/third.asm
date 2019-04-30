section .data
menu: 	db "Menu-",0x0A
	db "1. Hexadecimal to BCD", 0x0A
	db "2. BCD to Hexadecimal", 0x0A
	db "3. Exit", 0x0A, "Choice: "
mlen: equ $-menu
error: db "Incorrect choice. Enter again.", 0x0A
elen: equ $-error
msg1: db "Enter a 4 digit Hexadecimal number: "
len1: equ $-msg1
msg2: db "Enter a 5 digit BCD number: "
len2: equ $-msg2 
enter: db 0x0A
count: db 00
count1: db 00
count2: db 00
result: db 00
result2: dd 00
multi: db 01

section .bss
choice: resb 2
input1: resb 5
input2: resb 6
result3: resb 8

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
	print menu, mlen
	read choice, 2
	cmp byte[choice], 0x31
	je fun1
	cmp byte[choice], 0x32
	je fun2
	cmp byte[choice], 0x33
	je exit
	print error, elen
	jmp _start
exit:
	mov rax, 60
	mov rdi, 0
	syscall
	
fun1: 	print msg1, len1
	read input1, 5
	call atoh4
	mov bx, 0x0A			
up1:	mov dx, 00
	div bx
	push dx
	inc byte[count]
	cmp eax, 00
	jne up1
up11:	mov dx, 00
	pop dx
	cmp dl, 0x09
	jbe down1
	add dl, 0x07
down1:	add dl, 0x30
	mov byte[result], dl
	print result, 1
	dec byte[count]
	jnz up11
	print enter, 1
	jmp _start 
	
fun2: 	print msg2, len2
	read input2, 6
	mov byte[count], 5
	mov rsi, input2
	add rsi, 4
	xor eax, eax
	mov dword[result2], 00
up2:	mov al, byte[rsi]
	cmp al, 0x39
	jbe down2
	sub al, 0x07
down2:	sub al, 0x30
	mov bx, word[multi]
	mul bx
	add dword[result2], eax
	mov eax, 00
	mov ax, word[multi]
	mov bx, 0x0A
	mul bx
	mov word[multi], ax
	xor rax, rax
	dec rsi
	dec byte[count]
	jnz up2
	call htoa5
	print result3, 8
	print enter, 1
	jmp _start 
	
atoh4:	mov eax, 00
	mov byte[count1], 4
	mov rsi, input1
up3:	rol eax, 4
	mov dl, byte[rsi]
	cmp dl, 0x39
	jbe down3
	sub dl, 0x07
down3:	sub dl, 0x30
	add al, dl
	inc rsi
	dec byte[count1]
	jnz up3
	ret
	
htoa5:	mov eax, dword[result2]
	mov byte[count1], 0x08
	mov rdi, result3
up4:	rol eax, 4
	mov cl, al
	and cl, 0x0F
	cmp cl, 0x09
	jbe down4
	add cl, 0x07
down4:	add cl, 0x30
 	mov byte[rdi], cl
 	inc rdi
 	dec byte[count1]
 	jnz up4
 	ret
