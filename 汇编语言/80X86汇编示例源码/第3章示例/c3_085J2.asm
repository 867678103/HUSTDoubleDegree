;C3_085J1 ǿ����ʾ��������DS:DX��
;C3_085J2 ǿ����'$'��β

; ǿ�� ��ʾ�ַ��� :��ʾ����DS:DX�е�����
; �ڱ���T1��û��'$'
; �ڱ���T2���м���'$'
; ������ʾ�Ľ����ʲô��


STACK SEGMENT STACK
      DB 200 DUP(0)
STACK ENDS

DATA  SEGMENT
T1    DB 'abcdef'
T2    DB  31H,32H,33H,'$',34H,35H
DATA  ENDS   

CODE SEGMENT
     ASSUME CS:CODE,DS:DATA,SS:STACK

BEGIN:MOV AX,DATA
      MOV DS,AX

      LEA DX,T1
      MOV AH,9
      INT 21H
      MOV AH,4CH
      INT 21H
CODE  ENDS
      END BEGIN

