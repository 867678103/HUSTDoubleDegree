; C5_180m.asm  Ϊ��ģ��
; C5_180s.asm  Ϊ��ģ��

    ;  NAME    SUB_MODULE
       EXTRN   AVG:WORD,COUNT:WORD
                ;  �õ����ⲿ����
       PUBLIC  SUB_P
                ; �ӳ��� SUB_P Ϊ�ⲿģ��������

DATA2  SEGMENT PARA 'A1'
SUM    DW  0     ; �� 1+3+5+...+99 �ĺͣ����Ϊ 2500,�� 09C4H
DATA2  ENDS

STACK  SEGMENT PARA STACK 'STACK'
       DB  200 DUP(0)
STACK  ENDS

CODE2  SEGMENT PARA 'C1'
       ASSUME CS:CODE2,SS:STACK,ES:DATA2
SUB_P  PROC FAR
       MOV  AX,  DATA2
       MOV  ES,  AX
       MOV  AX,  0
NEXT:  ADD  AX,  BX
       ADD  BX,  2
       LOOP NEXT
       MOV  SUM, AX
       MOV  DX,  0
       DIV  COUNT
       MOV  AVG, AX
       RET
SUB_P  ENDP
CODE2  ENDS
       END
       