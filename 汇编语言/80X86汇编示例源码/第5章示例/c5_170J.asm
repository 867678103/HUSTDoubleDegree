;  ������������

;  �� INCLUDEPART = 1 , ����� PART1���ֵĳ���
;  ���򣬲����� PART1���ֵĳ���

.386
INCLUDEPART   =  0

code segment use16
     assume  cs:code
begin:
     mov  ax,0
IF   INCLUDEPART EQ 1
     MOV  BX, 0
     MOV  CX, 0
ENDIF
     MOV  AX, 4C00H
     INT  21H
CODE ENDS
     END BEGIN