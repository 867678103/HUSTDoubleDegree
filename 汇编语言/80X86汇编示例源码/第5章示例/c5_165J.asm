
;   ���ֲ���     
;   �����������     ������ֻ��Ϊ�ַ����е�һ���� 


data1 macro a,b,c,d
      dw    buf&a,buf&b
      endm

data segment  
x = 10
y = 20
     buf10  dw 1
     buf20  dw 2
     bufx   dw 3
     bufy   dw 4
     data1 %x, %y
     data1 x, y
data ends

code segment
     assume cs:code,ds:data
begin:
     mov ax,data
     mov ds,ax
                 ; �۲����ݶ�    

     mov ah,4ch
     int 21h
code ends
     end begin
        