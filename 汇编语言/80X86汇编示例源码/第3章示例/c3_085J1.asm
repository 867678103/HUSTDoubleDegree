;c3_085J1 ǿ����ʾ��������DS:DX��
;C3_085J2 ǿ����'$'��β

; ǿ����ʾ�ַ��� :��ʾ����DS:DX�е�����
; ���������Σ�һ����Ϊ���ݶΣ�һ����Ϊ���ӶΣ�
; ������ʾ�Ľ����ʲô��
; ������DX���õ���T2��Ч��ַ��ʵ�ʵ���ʾ����ΪT1�е����ݡ�

STACK SEGMENT STACK
      DB 200 DUP(0)
STACK ENDS

DATA1 SEGMENT
T1    DB 'abcdef',0dh,0ah,'$'
DATA1 ENDS   

DATA2 SEGMENT
T2    DB '012345678',0dh,0ah,'$'
DATA2 ENDS   

CODE SEGMENT
     ASSUME CS:CODE,DS:DATA1,ES:DATA2,SS:STACK

BEGIN:MOV AX,DATA1
      MOV DS,AX
      MOV BX,DATA2
      MOV ES,BX

      LEA DX,T2
      MOV AH,9
      INT 21H
      MOV AH,4CH
      INT 21H
CODE  ENDS
      END BEGIN

