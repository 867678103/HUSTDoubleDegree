
;   ���������ʵ��

;   ���ֲ���     , �۲����ɵ� LIST�ļ�
;       ���ڸ������ԣ�������ݶ��д�ŵ�������һ����
;                     ��������չ�׶Σ����ɵ�LIST�ļ���ͬ

;   �������ֻ��Ϊ�ַ����е�һ���֣����Ľ���ǲ����� 


stack0 macro  a
stack  segment stack
       db  a
stack  ends
       endm

stack0 <500 dup(0)>

data1 macro a,b,c,d
      dw    a,b,c
      db    d dup(1)
      endm

data segment
x = 10
y=20
     data1 %x+2,5,%x+y, %y-5
     data1 x+2,5,x+y,y-5
data ends

code segment
     assume cs:code,ss:stack,ds:data
begin:
     mov ax,data
     mov ds,ax
                 ; �۲����ݶ�    

     mov ah,4ch
     int 21h
code ends
     end begin
        