; ����λ��ָ��  P62   �Ĳ���

;  ˫�ּӷ�����

DATA SEGMENT
DN1  DW 0F00FH, 1234H
DN2  DW 80F0H,  1234H
DSUM DW 0,0
DATA ENDS

;   1234F00FH + 123480F0H = 246970FF H
;   ����ʹ�ô���λ�ӷ�

CODE SEGMENT
     ASSUME CS:CODE,DS:DATA
START: MOV AX,DATA
       MOV DS,AX
       
       MOV AX,DN1
       ADD AX,DN2         ; ��־λ  OV,  CY
       
       MOV DSUM,AX
       MOV AX,DN1+2
       ADC AX,DN2+2
       
       MOV DSUM+2,AX
       MOV AH,4CH
       INT 21H
CODE ENDS
     END START
