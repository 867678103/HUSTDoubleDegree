;Ҫ�㣺��1�����ݵĴ��
;      ��2��LDSָ��
;      ��3�������ַ�ļ��㣬���ݵ�Ԫ�ķ���

.386
data1  segment USE16
T1     dw -50H
T2     dd F
T3     db '1234567'
data1 ends

data2 segment USE16
buf   db 'ABCDEF'
F     DW 70H
data2 ends

stack segment USE16 stack
      db 200 dup(0)
stack ends

code segment USE16
     assume cs:code,ds:data1,ss:stack
start:
     mov ax,data1
     mov ds,ax

     MOV SI, 6        ;������������䣬�Ժ�MOV AX,[SI]�Ƚ�
     MOV AX,[SI]    

     MOV AX,T1
     LDS SI,T2
     MOV AX,[SI]

     MOV AX, T1    ; �� �����MOV AX, T1�Ľ���кβ�ͬ��

     mov ah,4ch
     int 21h
code ends
     end start

