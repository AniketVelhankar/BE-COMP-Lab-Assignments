%macro print 2
	mov rax,1
	mov rdi,1
	mov rsi,%1
	mov rdx,%2
	syscall
%endmacro


section .data

msg : db "Printing register contents",10
lmsg : equ $-msg

gr_msg : db "Contents of GDTR are :",10
lgr_msg : equ $-gr_msg

lr_msg : db "Contents of LDTR are :",10
llr_msg : equ $-lr_msg

ir_msg : db "Contents of IDTR are :",10
lir_msg : equ $-ir_msg

t_msg : db "Contents of TR are :",10
lt_msg : equ $-t_msg

m_msg : db "Contents of MSW are : "
lm_msg : equ $-m_msg

realM : db "Working in real mode",10
lrealM : equ $-realM

proM : db "Working in protected mode",10
lproM : equ $-proM

addrb : db "The base address is : "
laddrb : equ $-addrb

addrl : db "The limit value is : "
laddrl : equ $-addrl 

ent : db "",10
lent : equ $-ent

count : db 00H

section .bss

gdtcont : resd 1
      resw 1

idtcont : resd 1
      resw 1

ldtcont : resw 1

trcont : resw 1

result : resb 4

section .text 

global _start:

_start :

print msg,lmsg

smsw ax
bt ax,0
jc modemsg

print realM,lrealM
jmp operations

modemsg :
print proM,lproM
jmp operations

operations :

print m_msg,lm_msg
call h_to_a
print ent,lent

 print gr_msg,lgr_msg
 sgdt [gdtcont]
 print addrb,laddrb
 mov ax,word[gdtcont+4]
 call h_to_a
 mov ax,word[gdtcont+2]
 call h_to_a
 print ent,lent
 print addrl,laddrl
 mov ax,word[gdtcont]
 call h_to_a
 print ent,lent

 print ir_msg,lir_msg
 sidt [idtcont]
 print addrb,laddrb
 mov ax,word[idtcont+4]
 call h_to_a
 mov ax,word[idtcont+2]
 call h_to_a
 print ent,lent
 print addrl,laddrl
 mov ax,word[idtcont]
 call h_to_a
 print ent,lent

 print lr_msg,llr_msg
 sldt [ldtcont]
 mov ax,word[ldtcont]
 call h_to_a
 print ent,lent

 print t_msg,lt_msg
 str [trcont]
 mov ax,word[trcont]
 call h_to_a
 print ent,lent


exit :
mov rax,60
mov rdi,0
syscall


;=============================== Hex to Ascii ===================================
h_to_a :

mov rdi,result
mov byte[count],04H

UP1 :
rol ax,04
mov dl,al
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

print result,4
ret

