
; �� BEG (begin) ��ʼ�� �� (COUNT) ��������BEGΪ������
;                       ��ż����BEGΪż�����ĺ͡�
;�ʹ��� SUM ��Ԫ��
;�����ǵ�ƽ�������ŵ� AVG�С�

   ;   NAME    MAIN_MODULE
       EXTRN   SUB_P : FAR       ; �ر�ע�⣬�˴�����extern
                                 ; ��ģ���õ��ⲿ�ӳ��� SUB_P
       PUBLIC  AVG, COUNT     
               ;��ģ���еı���AVG, COUNT Ϊ����ģ������
DATA1  SEGMENT
BEG    EQU   1
COUNT  DW    50
AVG    DW    0
DATA1  ENDS

STACK SEGMENT PARA STACK 'STACK'
      DB  200 DUP(0)
STACK ENDS

CODE1 SEGMENT PARA 'C1'
      ASSUME  CS:CODE1,SS:STACK,DS:DATA1
START:
      MOV  AX,  DATA1
      MOV  DS,  AX
      MOV  BX,  BEG
      MOV  CX,  COUNT
      CALL SUB_P      ; �����ⲿ�ӳ���
      MOV  AH,  4CH
      INT  21H
CODE1 ENDS
      END  START