     ;  ��ʾASCII ��
     ;  HEAD1, �������ĸ���ţ�HEAD1_0,HEAD1_1,HEAD1_2 ��ʾ�˵�һ����
     ;         ��һ���ߣ�����һ�����ַ���ʽ��ʾ�ġ�
     ;  TOP1 �����˵�һ�����ֺ��ߵ���ʾ����������ʾ�����
     ;  MIDDLE_L : �м������
     ;  END_L    : ����µ�����
     ;  DATA_L   : �м������ݵ���
     ;             �ڳ����У��޸ĸ����в�ͬ������ֵ���ﵽ��ʾ��ͬ�����Ŀ��
CRLF MACRO 
     MOV AH,2
     MOV DL,0AH
     INT 21H
     MOV DL,0DH
     INT 21H
     ENDM

L_VERTICAL MACRO        ; ��ʾ����
     MOV AH,2
     MOV DL,179
     INT 21H
     ENDM

DISPLAY MACRO  A     ; ��ʾ�м������������
                     ; A ������һ��������Ŀ�ʼλ��
     LEA DX,A
     MOV AH,9
     INT 21H
     ENDM

data segment
LUC      EQU  218     ; "��"
HHH      EQU  196     ; "��"
HTH      EQU  194     ; "��"
RUC      EQU  191     ; "��"
VVV      EQU  179     ;  "��"
CRS      EQU  197     ; "��"
VEV      EQU  195     ; "��"
top1     db   VVV,3 dup(20H),VVV,3 dup(20H),VVV,32,32,30H,VVV
         db   ' 16',VVV,' 32',VVV,' 48',VVV,' 64',VVV
         DB   ' 80',VVV,' 96',VVV,'112',VVV,'128',VVV
         DB   '144',VVV,'160',VVV,'176',VVV,'192',VVV
         DB   '208',VVV,'224',VVV,'240',VVV,0DH,0AH,'$'

top2     db '0123456789ABCDEF'
MIDDLE_L db VEV, 17 dup (3 dup(HHH),CRS), HHH,HHH,HHH,180,0dh,0ah,'$'
DATA_L   DB   19 DUP( VVV,3 dup(20H)),0DH,0AH,'$'

END_L    DB 192, 17 DUP(3 DUP(HHH),193),HHH,HHH,HHH,217,0DH,0AH,'$'


data ends

stack segment stack
      db 200 dup(0)
stack ends

code segment
     assume cs:code,ds:data,ss:stack
begin:
     mov ax,data
     mov ds,ax

display_head:
     mov dl,LUC
     mov ah,2
     int 21h
head1:
     mov BX,17
head1_0:
     MOV CX,3
     mov dl,HHH
     MOV AH,2
HEAD1_1:     
     INT 21H
     LOOP HEAD1_1
     MOV  DL,HTH
     MOV  AH,2
     INT  21H
     DEC  BX
     JNE  HEAD1_0

     MOV  CX,3
     MOV  DL,HHH
     MOV  AH,2
HEAD1_2:
     INT  21H
     LOOP HEAD1_2         
     MOV  DL,RUC
     MOV  AH,2
     INT  21H
     CRLF               ; ���ϳ�����ʾ�˵�һ����
     
     LEA DX,TOP1
     MOV AH,9
     INT 21H            ; ��ʾ�˵�һ��  ���� 0��16��32......
    
     DISPLAY   MIDDLE_L      ; ��ʾ�м������

     LEA  BX,DATA_L+10
     MOV  CX,16
     MOV  SI,OFFSET TOP2
WR_DATA1:
     MOV  DL,[SI]
     MOV  [BX],DL
     ADD  BX,4
     INC  SI
     LOOP WR_DATA1
     LEA  DX,DATA_L
     MOV  AH,9
     INT  21H           ; ��ʾ�˵ڶ���  ���� 0��1��2��...... F
          

     MOV  SI,0          ; ��һ������
MAIN:          
     DISPLAY  MIDDLE_L  ; ��ʾ����
     MOV  BX,OFFSET DATA_L+2      ; ǰ����
     MOV  DL,TOP2[SI]
     MOV  [BX],DL
     ADD  BX,4
     MOV  [BX],DL
     ADD  BX,4
     MOV  DX,SI             ; ʵ��ֻ�õ��˵�8λ
     MOV  CX,16             ; һ��16������
WR_DATA3:
     CMP  DL,7
     JZ   LLL
     cmp  DL,8
     JZ   LLL
     CMP  DL,9
     JZ   LLL
     CMP  DL,0AH
     JZ   LLL
     CMP  DL,0DH
     JZ   LLL
     CMP  DL,'$'           ; ����������ڴ��к���$�ַ�������ӡ����������Ĳ��ֲ����ӡ
     JZ   LLL
     MOV  [BX],DL
     JMP  LLLL
LLL: MOV  [BX],BYTE PTR ' '
LLLL:ADD  DL,16
     ADD  BX,4
     LOOP WR_DATA3

     LEA  DX,DATA_L         ; ��ʾ������
     MOV  AH,9
     INT  21H
     
     INC  SI                ; ��ʾ���е���
     CMP  SI,8
     JBE  MAIN

     DISPLAY END_L     
     mov  ah,4ch
     int  21h
code ends
     end begin
 