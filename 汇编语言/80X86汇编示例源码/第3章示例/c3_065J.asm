
;  �з��ų˷� IMUL, ���޷��ų˷�MUL

code segment
     assume cs:code
begin:
     mov  al,10H
     mov  bl,-2      ;  (bl)=FE
     imul bl         ;  (ax)=FFE0  ,������ֽ�����Чλ����NC, NV

     mov  al,10H
     mul  bl         ;  (ax)=0FE0,  ������ֽ�����Чλ����CY, OV

     mov  al,-10h
     mov  bl,2
     imul bl         ; (ax) = FFE0 

     mov  al,-10h
     mov  bl,2
     mul  bl         ; (ax) = 01E0

 
     mov  ah,4ch
     int  21h
code ends
     end begin