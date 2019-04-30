section .bss

fname:resb 8
fname1:resb 8
fname2:resb 8
fname3:resb 8

fd_in:resb 8
fd_in1:resb 8
fd_in2:resb 8
fd_in3:resb 8

len:resb 8

buffer:resb 100
readfile:resb 100

%macro scall 4
mov rax,%1
mov rdi,%2
mov rsi,%3
mov rdx,%4
syscall
%endmacro

section .text
global _start
_start:
pop rbx
pop rbx
pop rbx

mov rsi,rbx
cmp byte[rsi],'T'
jne next
inc rsi
cmp byte[rsi],'Y'
jne exit
inc rsi
cmp byte[rsi],'P'
jne exit
inc rsi
cmp byte[rsi],'E'
je type
jne exit




next:
mov rsi,rbx
cmp byte[rsi],'C'
jne next1
inc rsi
cmp byte[rsi],'O'
jne exit
inc rsi
cmp byte[rsi],'P'
jne exit
inc rsi
cmp byte[rsi],'Y'
je copy
jne exit



next1:
mov rsi,rbx
cmp byte[rsi],'D'
jne exit
inc rsi
cmp byte[rsi],'E'
jne exit
inc rsi
cmp byte[rsi],'L'
jne exit
inc rsi
cmp byte[rsi],'E'
jne exit
inc rsi
cmp byte[rsi],'T'
jne exit
inc rsi
cmp byte[rsi],'E'
je del
jne exit


type:
pop rbx
mov rsi,fname
up:
mov al,byte[rbx]
mov byte[rsi],al
inc rsi
inc rbx
cmp byte[rbx],0
jne up

scall 2,fname,2,0777
mov qword[fd_in],rax
BT rax,63
jnc down
jmp exit

down:
scall 0,[fd_in],buffer,100
mov qword[len],rax
scall 1,1,buffer,[len]
jmp exit

copy:
pop rbx
mov rsi,fname1

up1:
mov al,byte[rbx]
mov byte[rsi],al
inc rsi
inc rbx
cmp byte[rbx],0
jne up1

pop rbx
mov rsi,fname2

up2:
mov al,byte[rbx]
mov byte[rsi],al
inc rsi
inc rbx
cmp byte[rbx],0
jne up2

scall 2,fname1,2,0777
mov qword[fd_in1],rax
BT rax,63
jnc down1
jmp exit

down1:
scall 2,fname2,2,0777
mov qword[fd_in2],rax
BT rax,63
jnc down2
jmp exit


down2:
scall 0,[fd_in1],buffer,100
mov qword[len],rax
scall 1,[fd_in2],buffer,[len]
jmp exit


del:
pop rbx
mov rsi,fname3
up3:
mov al,byte[rbx]
mov byte[rsi],al
inc rsi
inc rbx
cmp byte[rbx],0
jne up3

scall 2,fname3,2,0777
mov qword[fd_in3],rax
bt rax,63
jnc down3
jmp exit

down3:
mov rax,87
mov rdi,fname3
syscall



exit:
mov rax,60
mov rdi,0
syscall


