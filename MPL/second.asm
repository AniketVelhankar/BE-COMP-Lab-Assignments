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
array : dq 1234567890123456H, 5646832145846569H, 3054104158421454H, 7984798524987245H,9134324101541067H, 00H, 00H, 00H, 00H, 00H
ent : db 0x0A
lent : equ $-ent
colon : db " : "
lencol : equ $-colon
menu :
db "1 : Non-overlapping without string",10
db "2 : Non-overlapping with string",10
db "3 : Overlapping without string",10
db "4 : Overlapping with string",10
db "5 : Exit",10
db "Enter your choice",10
lenmenu : equ $-menu

before : db "Before copy",10
lenbe : equ $-before
after : db "After copy",10
lenaf : equ $-after

section .bss
data : resb 16
cnt1 : resb 1
cnt2 : resb 1
choice : resb 2

section .text
global _start
_start:
print menu,lenmenu
read choice,2
cmp byte[choice],31H
JE NOWOS
cmp byte[choice],32H
JE NOWS
cmp byte[choice],33H
JE OWOS
cmp byte[choice],34H
JE OWS
cmp byte[choice],35H
JE EXIT

;procedure for non overlapping without string instructions

CALL1 :

;print array before copying data
print ent,lent
print before,lenbe
call print_array

;set source and destination
mov rsi,array
mov rdi,array+40
mov byte[cnt1],5

;mov data from rsi to rdi using rax variable

UP2 :
mov rax,qword[rsi]
mov qword[rdi],rax
add rsi,8
add rdi,8
dec byte[cnt1]
JNZ UP2

;print array after copying the contents

print ent,lent
print after,lenaf
call print_array
ret

EXIT :
mov rax,60
mov rdi,0
syscall

;hex to ascii conversion

h_to_a :
mov rdi,data
mov byte[cnt2],16

UP1 :
rol rbx,4
mov dl,bl
and dl,0FH
cmp dl,09H
jbe NEXT
add dl,07H

NEXT :
add dl,30H
mov byte[rdi],dl
inc rdi
dec byte[cnt2]
JNZ UP1

print data,16
ret

;procedure for printing array

print_array :
mov rsi,array ;set source pointer to array 
mov byte[cnt1],10 ;count is having 10 because number of numbers in array are 10

UP :

;first we print addresses so we move rsi for htoa conversion

mov rbx,rsi

;push rsi because we'll require rsi later

push rsi
call h_to_a

;after printing address we print colon

print colon,lencol

;now we pop rsi pushed earlier and now we move byte[rdi] to rbx that is the number to be printed 

pop rsi
mov rbx,qword[rsi]
push rsi
call h_to_a

;after printing address colon and the data at that address we print enter and loop for rest of the array

print ent,lent
pop rsi
add rsi,8
dec byte[cnt1]
JNZ UP
ret


;procedure for overlapping without string

CALL2 : 
print ent,lent
print before,lenbe
call print_array

mov rsi,array
mov rdi,array+32
mov byte[cnt1],5

UP3 :
mov rax,qword[rsi]
mov qword[rdi],rax
add rsi,8
add rdi,8
dec byte[cnt1]
JNZ UP3

print ent,lent
print after,lenaf
call print_array
ret

;procedure for non overlapping with string

CALL3 :
print before,lenbe
call print_array

mov rsi,array
mov rdi,array+40
mov byte[cnt1],5

UP4:

; we clear the direction flag so that we'll increment array addresses automatically

CLD

;mov string of quadword for moving a complete string of data from source to destination

movsq
dec byte[cnt1]
JNZ UP4

print ent,lent
print after,lenaf
call print_array
ret

;procedure for overlapping with string

CALL4 :
print before,lenbe
call print_array

mov rsi,array
mov rdi,array+32
mov byte[cnt1],5

UP5 :
CLD
movsq
dec byte[cnt1]
JNZ UP5

print ent,lent
print after,lenaf
call print_array
ret

;labels to call procedures

NOWOS :
call CALL1
JMP _start

OWOS :
call CALL2
JMP _start

NOWS :
call CALL3
JMP _start

OWS :
call CALL4
JMP _start
