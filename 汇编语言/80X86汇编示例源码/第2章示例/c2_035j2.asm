       ; Ѱַ��ʽ���� 
       ; ��ַѰַ
       ; ��ַѰַ��ʽ��ʹ���˱���ʱ���﷨�涨
       ;     (1) ȡ������ƫ�Ƶ�ַ�μ����㣬�����Ǳ�����Ԫ�е�����
       ;     (2) Ĭ�ϵĶ��Ǳ������ڵĶΡ�
       ;     (3) ������������Ϊ����������
       
.386
data   segment USE16
X      db 10H,20H,30H
Y      DW 1122H, 3344H, 5566H, 7788H
data   ends
       

CODE    SEGMENT USE16
        ASSUME  CS:CODE,DS:data 
START:  MOV   AX , DATA
        MOV   DS , AX
        MOV   BX , 0
        
        MOV   X[BX], 0       ;  �Ƚϸ��Լ�����Ԫ��0
        MOV   Y[BX], 0       ;
        
        MOV   Y+4[BX],1234H  ;  �Ǹ����ĸ���Ԫ�����ݣ�

EXIT:   MOV   AX , 4C00H
        INT   21H
CODE  ENDS
        END  START