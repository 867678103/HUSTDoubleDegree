     ; �߼���֧���򣺵�ַ�б�
     ; ���ڲ�ͬ�����룬������ͬ�Ļ�Ӧ
     ;    ���� 0����ʾ "zero"
     ;    ���� 1����ʾ "first"
     ;    ���� 2����ʾ ��two" ............
     ;    ���� 9����ʾ "nine"
     ;    ������������ʾ "error"
.386
DATA SEGMENT USE16
INPUTMSG  DB 'PLEASE INPUT A NUMBER (0~9):$'

MSG0    DB 0DH,0AH,'zero$'
MSG1    DB 0DH,0AH,'first$'
MSG2    DB 0DH,0AH,'two$'
MSG3    DB 0DH,0AH,'three$'
MSG4    DB 0DH,0AH,'four$'
MSG5    DB 0DH,0AH,'five$'
MSG6    DB 0DH,0AH,'six$'
MSG7    DB 0DH,0AH,'seven$'
MSG8    DB 0DH,0AH,'eight$'
MSG9    DB 0DH,0AH,'nine$'
ERR     DB 0DH,0AH,'error$'

MSGTABLE  DW  MSG0,MSG1,MSG2,MSG3,MSG4,MSG5,MSG6,MSG7,MSG8,MSG9,ERR

DATA ENDS

STACK SEGMENT USE16 STACK 
      DB 200 DUP(0)
STACK ENDS 

CODE SEGMENT  USE16
     ASSUME CS:CODE,DS:DATA,SS:STACK
BEGIN:
     MOV  AX,DATA
     MOV  DS,AX
     LEA  DX,INPUTMSG   ;
     MOV  AH,9
     INT  21H
     MOV  AH,1          ;
     INT  21H
     
     MOV  BX, 10
     CMP  AL,'0'
     JB   L1        ;  ����� '0' С
     CMP  AL,'9'
     JA   L1        ;  ����� '9' ��

     MOV  BL,AL
     SUB  BL,30H    ; ������������� (BL)��
     MOV  BH,0      

L1 : SHL  BX,1           ; (bx) *2 , һ����ַ��ռ�����ֽ�
     MOV  DX, MSGTABLE[BX]
     MOV  AH, 9
     INT  21H

     MOV  AH,4CH
     INT  21H
CODE ENDS
     END BEGIN

