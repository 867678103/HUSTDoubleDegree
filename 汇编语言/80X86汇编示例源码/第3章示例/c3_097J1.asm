       ; �����£�ϰ�� 3.11  ������޸�
       ; 

; c3_p87.asm �����У����ڵ����⣺����������9����ΪA--F,��ʾ�Ľ�����ԡ�
; ���磬NUM DB 00111011B
; ������ 
;    ����λ��������Ϊ 0 ,  ��Ҫ��ʾ 0 ��ASCII��'0'��ASCIIΪ 30H,Ҫ��ԭ���������ϼ�30H
;    ����λ��������Ϊ 9 ,  ��Ҫ��ʾ 9 ��ASCII��'9'��ASCIIΪ 39H,Ҳ����ԭ���������ϼ�30H
;    ����λ��������Ϊ 1010 ,  ��Ҫ��ʾ A ��ASCII��'A'��ASCIIΪ 41H,
;              Ҫ��ԭ���������ϼ�37H  (41H - 0AH  =37 H)
; �ó����ۣ�����λ��������<10, ��� 30H; �����  37H

A     SEGMENT
NUM   DB  00111011B
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
       CMP  AL,10
       JB   L1
       ADD  AL,7
L1:    ADD  AL,30H
                        ; ������OR AL,30H, Ϊʲô��
;       OR   AL,30H     ; �൱��ִ���� ADD AL,30H

       MOV  [DI],AL
       INC  DI
       MOV  AL,NUM
       AND  AL,0FH     ; ����λ��Ϊ0

       CMP  AL,10
       JB   L2
       ADD  AL,7
L2:    ADD  AL,30H

;       OR   AL,30H

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

