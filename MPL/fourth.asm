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

msg1 : db 10,13,'Enter a 2-digit Multiplicant: '
lmsg1 : equ $-msg1
     
msg2 : db 10,13,'Enter a 2-digit Multiplier: '
lmsg2 : equ $-msg2
     
msg3 : db 10,13,'Addition after Successive addition is:  '
lmsg3 : equ $-msg3
     
msg4 : db 10,13,'Addition after Add & Shift method is: '
lmsg4 : equ $-msg4

menu :
	db 10,13,'-----MENU-----'
	db 10,'1.Successive Addition'
        db 10,'2.Add and Shift Method'
        db 10,'3.Exit'
        db 10,'Enter your choice: '
lmenu : equ $-menu

ent : db 10
entl : equ $-ent

section .bss

number : resb 3
num1 : resb 3
num2 : resb 3
count : resb 4
result : resb 8
choice : resb 2
display_buff : resb 8

section .text

global _start:

_start:

print menu,lmenu
read choice,2

cmp byte[choice],31H
je sadd

cmp byte[choice], 32H
je addnshift

cmp byte[choice],33H
je exit

exit:
mov rax,60
mov rdi,0
syscall

sadd:
call succAdd
jmp _start

addnshift:
call addANDshift
jmp _start


succAdd:

;get first number

print msg1,lmsg1
read number,3
call Ascii_to_Hex
mov byte[num1],bl

;get second number

print msg2,lmsg2
read number,3
call Ascii_to_Hex
mov byte[num2],bl

xor rax,rax
xor rcx,rcx

;add rax with rax rcx times which means (4*3=12). eg. Here we are taking 4 in rax and 3 in rcx and we do 4 + 4 + 4 = 12 

mov al,byte[num1]

mult:
add rcx,rax
dec byte[num2]
jnz mult 

;store contents of rcx in result and pass result to htoa code

mov [result],rcx
mov bx,[result]
print msg3,lmsg3
call h_to_a
ret


addANDshift:

;get first number

print msg1,lmsg1
read number,3
call Ascii_to_Hex
mov byte[num1],bl

;get second number

print msg2,lmsg2
read number,3
call Ascii_to_Hex
mov byte[num2],bl

print msg4,lmsg4
xor rax,rax
xor rbx,rbx
xor rcx,rcx
xor rdx,rdx

;add and shift is one algorithm for multiplication

mov dl,byte[num1]
mov bl,byte[num2]
mov byte[count],08H

l1:
	shl ax,1
        rol bl,1
        jnc l2
    	add ax,dx
l2:	
dec byte[count]
jnz l1

mov bx,ax
call h_to_a
ret 
;======================== ASCII To HEX Conversion ================================

Ascii_to_Hex:

	xor bl,bl
	mov rsi,number
	mov byte[count],02H

	up:
		rol bl,04
		mov dl, byte[rsi]
		cmp dl, 39H
		jbe next
		sub dl, 07

	next:
		sub dl,30H
		add bl,dl
		inc rsi
		dec byte[count]
		jnz up
ret

;=============================== Hex to Ascii ===================================
h_to_a :

mov rdi,display_buff
mov byte[count],04H

UP1 :
rol bx,4
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

print display_buff,4
ret


