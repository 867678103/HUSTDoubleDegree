; P71 TEST ָ��Ա�־λ��Ӱ��
;     OF=0,  CF=0,   ���� AND, OR, XOR һ�����
;     SF, ZF,  PF ��������� 

.386
CODE  SEGMENT  USE16
      ASSUME  CS:CODE
BEGIN:
      MOV  AX,0AFFFH
      MOV  BX,0A000H
      ADD  AX, BX
      MOV  AX, 1234H
      TEST  AX, 01H
      MOV  AX, 4C00H
      INT  21H
CODE  ENDS
      END BEGIN
