       ; Ѱַ��ʽ���� 
       ; ��ַѰַ
       ; ��ַѰַ��ʽ��ʹ���˱���ʱ���﷨�涨
       ;     (1) ȡ������ƫ�Ƶ�ַ�μ����㣬�����Ǳ�����Ԫ�е�����
       ;     (2) Ĭ�ϵĶ��Ǳ������ڵĶΡ�
       
.386
data   segment USE16
X      db 10H,20H,30H
X2     db 11H, 22H
data   ends
       
STACK  SEGMENT  USE16 STACK
Y      db  40H, 50H
       DB 200  DUP(0)
STACK  ENDS

CODE    SEGMENT USE16
        ASSUME  CS:CODE,DS:data,SS:STACK
Z       DB    60H,70H        
START:  MOV   AX , DATA
        MOV   DS , AX
        MOV   BX , 0

        MOV   AH , X[BX]     ; �۲���õ�ʲô�Σ�
        MOV   AL,  Y[BX]
        MOV   CL,  Z[BX]
        
        MOV   AH,  X2[BX]     ; ȡ X2��ƫ�Ƶ�ַ
        
        MOV   AH, CS:X[BX]    ; �۲�ǿ�ƶ�
        MOV   AL, SS:X[BX]

EXIT:   MOV   AX , 4C00H
        INT   21H
CODE  ENDS
        END  START