       ; �����£�ϰ�� 3.11
       ;     �Ķ�����ָ������Ĺ���

; ���³������ʾ���Ϊ (NUM)=39H
; ��һ���ֽڵĶ�������ת����ʮ�����Ƶ���ʽ��ʾ����
; �����У����ڵ����⣺����������9����ΪA--F,��ʾ�Ľ�����ԡ�
; ���磬NUM DB 00111011B

A     SEGMENT
NUM   DB  00111001B
BUF   DB  0AH,0DH,'(NUM)='
BUF0  DB  4 DUP(?)
A     ENDS

B  SEGMENT  STACK
   DB 200  DUP(0)
B  ENDS

C    SEGMENT
        ASSUME  DS:A,SS:B,CS:C
BEGIN: MOV  AX,A
       MOV  DS,AX
       LEA  DI,BUF0
       MOV  AL,NUM
       MOV  CL,4
       SHR  AL,CL
                       ; AL�ĸ���λΪ0��ԭ���ĸ���λ�Ƶ��˵���λ
       OR   AL,30H     ; �൱��ִ���� ADD AL,30H
       MOV  [DI],AL
       INC  DI
       MOV  AL,NUM
       AND  AL,0FH     ; ����λ��Ϊ0
       OR   AL,30H
       MOV  [DI],AL
       INC  DI
       MOV  BYTE PTR [DI],'H'
       INC  DI
       MOV  BYTE PTR [DI],'$'
       LEA  DX,BUF
       MOV  AH,9
       INT  21H
       MOV  AH,4CH
       INT   21H
C      ENDS
       END  BEGIN

