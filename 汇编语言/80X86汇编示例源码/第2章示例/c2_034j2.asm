  ;  Ѱַ��ʽ 
  ;  ����BUFΪ��ַ��5�������ݵĺ�
  ;  �Ĵ������Ѱַ��ʽ��Ӧ��
.386
STACK  SEGMENT  USE16 STACK
       DB 200  DUP(0)
STACK  ENDS

DATA   SEGMENT USE16
BUF    DW  10,20,30,40,50
RES    DW  ?
DATA   ENDS

CODE    SEGMENT USE16
        ASSUME  CS:CODE,DS:DATA,SS:STACK
START:  MOV   AX , DATA
        MOV   DS , AX
        MOV   BX , OFFSET  BUF
        MOV   CX , 5
        MOV   AX , 0
LP:     ADD   AX, [BX]      ; ָ��ɷ񻻳� MOV AX,BX
                            ; ��������н����ʲô��
        INC   BX
        INC   BX
        DEC   CX
        JNZ   LP
        MOV   RES,AX
EXIT:   MOV   AX , 4C00H
        INT   21H
CODE  ENDS
        END  START