; �������������⣬��ַԽ��
; Ϊʲô���Թ�����

data segment
x db 1,2,3
y dw 12,34
data ends

code segment
     assume cs:code,ds:data
begin:
    mov ax,data
    mov ds,ax
    mov ah, x
    mov al, x+3
    mov bl, x+4
    mov ah,4ch
    int 21h
code ends
     end begin