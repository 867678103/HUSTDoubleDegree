;Ҫ�㣺��1�����ݵĴ��
;      ��2��LDSָ��
;      ��3�������ַ�ļ��㣬���ݵ�Ԫ�ķ���
;             ���� MOV  AX,T1�Ľ���Ƚ�

data1  segment 
T1     dw 50H
T2     dd F
data1 ends

data2 segment
buf   db 'ABCDEF'
F     DW 70H
data2 ends

stack segment stack
      db 200 dup(0)
stack ends

code segment
     assume cs:code,ds:data1,ss:stack
start:
     MOV AX,0      ;
     MOV AX,T1     ; ��û�н�DATA1�ε���ַ��DS,(AX)=?

     mov ax,data1
     mov ds,ax
     MOV AX,T1     ; DS��ΪDATA1�ε���ַ��(AX) = ?

     LDS SI,T2     ; LDS�Ĺ����ǣ�
     MOV AX,[SI]   ; (AX)= ?

     mov AX,T1    ; (AX)=?
     
     mov AX,4C00H
     int 21h
code ends
     end start

