   ;  ��һ��  P28 �����ӵ��޸�
   ;  ����һ�����Դ���������
   ;  �ó����д����do ...while ѭ���Ľṹ��ͬ
   ;  ��c1_028g1.asm  ��һ��ָ��
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

        MOV   AX ,  0   ;   0-> AX
        MOV   BX ,  1
MAINP:  ADD   AX , BX   
        ADD   BX , 2
        CMP   BX , 100
        JL    MAINP         ;�� (BX)<100����ת�� MAINP

        MOV   SUM , AX
        MOV   AX , 4C00H
        INT   21H
CODE  ENDS
        END  BEGIN