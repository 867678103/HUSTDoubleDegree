; �۲����д��λ��
; ���ų���������Գ����ڶ��ڣ�Ҳ���Գ����ڶ���
; ���������ã�����

AA=10

d1 segment
x    db  CC
buf1 db  AA
CC  = 30
buf2 dw  AA,CC
d1  ends

XYZ=40
code segment
     assume cs:code,ds:d1
begin:
     mov ax,d1
     mov ds,ax

     mov bx,aa      ; Դ��������ʲôѰַ��ʽ

     mov cx,BB      ; �����ã�����
BB =20

     mov dx,XYZ
     mov ax,4c00H
     int 21H
code ends
     end begin
