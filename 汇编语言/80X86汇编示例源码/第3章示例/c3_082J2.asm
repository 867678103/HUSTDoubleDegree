;  c3_082J2  
;  ǿ������μĴ���������ϵ,����������ϵ�����ʱ����
;  ǿ�����μĴ�����ֵ�󣬷��ʽ������ȷ

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
     mov ax,data1
     mov ds,ax

  ;     mov  ax, F   ; �������: δ������ϵ����ʹ��F
     
     MOV  AX, ES:F   ; ���﷨�����߼���ȷ��
     
ASSUME es:data2

     MOV AX, F    ; ���﷨�����߼���ȷ��
     LES SI, T2
     mov AX, F    ;  �ȼ��� es : mov AX,[0006]

     MOV  BX,  T1    ; �Ƚ�ȡ����ϵ���Ƿ���ȷ
ASSUME DS:NOTHING
  ;   MOV  BX, T1     ; �������
  
     mov ah,4ch
     int 21h
code ends
     end start
