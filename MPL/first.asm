section .data
arr : dq 1234567891011123H , 2254131654045848H , 5567295814726845H , 8653421974063120H , 9653241478218320H
pos : db 0
neg : db 0
count : db 5
msg1 : db "No. of Positive Numbers : "
len1 : equ $-msg1
ent : db 10
len : equ $-ent
msg2 : db "No. of Negative Numbers : "
len2 : equ $-msg2

section .bss
%macro print 2
mov rax,1
mov rdi,1
mov rsi,%1
mov rdx,%2
syscall
%endmacro

section .text
global _start
_start:
mov rsi,arr
Loop1 :
	mov rax,qword[rsi]
	BT rax,63
	jc Loop2
	inc byte[pos]
	add rsi,8
	dec byte[count]
	jnz Loop1
	jmp Loop3

Loop2 :
	inc byte[neg]
	add rsi,8
	dec byte[count]
	jnz Loop1

Loop3 :
	cmp byte[pos],9
	jbe Loop4
	add byte[pos],07H

Loop4 :
	add byte[pos],30H
	cmp byte[neg],9
	jbe Loop5
	add byte[neg],07H

Loop5:
	add byte[neg],30H

print msg1,len1
print pos,1
print ent,len
print msg2,len2
print neg,1
print ent,len

mov rax,60
mov rdi,0
syscall

