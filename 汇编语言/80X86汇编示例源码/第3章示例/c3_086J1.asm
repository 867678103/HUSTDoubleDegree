; P86 �����ַ���

; (1) �۲��������ݵĴ�Ž�� ,��֤�����������ַ�������֤�����ʽ
; (2) ���������������С���۲��������ݵĴ�Ž��
; (3) ���ܵȼ۵����ݶ������

STACK SEGMENT STACK
      DB 200 DUP(0)
STACK ENDS

DATA  SEGMENT
BUF   DB  11
      DB  ?
      DB  11 DUP(0)
DATA  ENDS   

CODE SEGMENT
     ASSUME CS:CODE,DS:DATA,SS:STACK

START:MOV AX,DATA
      MOV DS,AX

      LEA DX,BUF
      MOV AH,10
      INT 21H
      MOV AH,4CH
      INT 21H
CODE  ENDS
      END START

; �� BUF �Ķ����Ϊ  DB 20,?,10 dup(0)
;                    DB 1,2,3,4,5,6,7,8