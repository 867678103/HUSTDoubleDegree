; �۲���������÷���
; �����ִ�����̿����ж��֣�˳�򡢷�֧��ѭ��
; ����������мӹ�ʱ����˳��ɨ��Դ����
; �����еķ��ų����滻����Ӧ��ֵ,ֱ������ͬ���ķ��ų�����

code segment
     assume cs:code
begin:

XX = 30
     JMP L2

L1:
     mov bx,XX      
     JMP EXIT
XX = 40

L2:
     mov cx,XX
     JMP L1

EXIT:
     mov ax,4c00H
     int 21H
code ends
     end begin
