 ; (1) ���ݶ�������еĵ�ַ���ʽ
 ;     �����������
 ; (2) ����ַ������   $
 ; (3) �û���ַ������αָ��

 DATA  SEGMENT
 BUF1  DB 'HELLO'
 BUF2  DB '1234'
 X     DW  BUF2 - BUF1
 Y     DW  $ - X
 Z     DW  $ - X
  
       ORG $+5
 BUF3  DB  '1234'
 DATA  ENDS
 CODE  SEGMENT
       ASSUME CS:CODE,DS:DATA
 START: MOV AX,DATA
        MOV DS,AX
        MOV AH,4CH
        INT 21h
 CODE ENDS
      END  START
