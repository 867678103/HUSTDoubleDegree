   ;  ��һ��  P28 �����ӵ��޸�
   ;  ����һ�����Դ���������
   ;  �ó����д����do ...while ѭ���Ľṹ��ͬ
   ;  �޸� c1_028g2.asm,  ���������Ĵ���
.386
DATA   SEGMENT USE16
       SUM    DW  0
DATA   ENDS

STACK  SEGMENT  USE16 STACK
       DB 200  DUP(0)
STACK  ENDS

CODE    SEGMENT USE16
        ASSUME  CS:CODE,DS:DATA,SS:STACK
BEGIN:  MOV   AX , DATA
        MOV   DS , AX

        MOV   SI ,  0   ;   0-> SI
        MOV   CX ,  1
MAINP:  ADD   SI , CX  
        ADD   CX , 2
        CMP   CX , 100
        JL    MAINP         ;�� (CX)<100����ת�� MAINP

        MOV   SUM , SI
        MOV   AX , 4C00H
        INT   21H
CODE  ENDS
        END  BEGIN