
;  �Ƚ�  ������ָ�� ��  ���ø�ָ���Ч������

;  �ڳ������п�ʼ�ͽ�����ʱ��ȡ��ʱ�䣬�����ʾ���õ�����

;  ����������в����ϵͳʱ���Сʱ������δ��Сʱ������

;  �� c5_152_3.asm �Ƚ�
;  ���� 8000H * FFFFH ���ֽڣ���������ʱ 14�룬 �� c5_152_3.asm ��ʱ 3��
;  ���� 5000H * FFFFH ���ֽڣ���������ʱ 9�룬 �� c5_152_3.asm ��ʱ 2��
;  ע�����л���, ��ͬ����������ٶȲ�һ��

.386
stack segment USE16 stack
hour1    db ?
minute1  db ?
second1  db ?
hensec1  db ?         ; �ٷ�֮һ�룬������Ч
hour2    db ?
minute2  db ?
second2  db ?
hensec2  db ?  
         db 100 dup(0)
stack    ends
    
code segment USE16
     assume cs:code,ss:stack
gettime proc 
     mov ah,2ch
     int 21h
     mov [bp], ch
     mov [bp+1],cl
     mov [bp+2],dh
     mov [bp+3],dl
     ret
gettime endp

begin:     
     mov bp,0
     call gettime

     mov dx,8000H
lop_1:
     mov cx,0ffffH
     mov si,0
     mov di,0
lop_2:
     mov al,[si]
     mov [di],al
     inc si
     inc di
     dec cx
     jnz lop_2
     dec dx
     jnz lop_1

     mov bp,4
     call gettime
     mov  al, minute2
     sub  al, minute1
     mov  bl, 60
     mul  bl
     mov  dx, ax
     mov  al, second2
     sub  al, second1
     cbw             ; ��� ʱ��2������ ��ʱ��1�����������ֱ�Ӽ���������
                     ; ���� �������Ӧ������
     add  ax,dx
     mov  cx,0
     mov  bl,10
l1:  mov  ah,0
     div  bl
     push ax
     inc  cx
     cmp  al,0
     jnz  l1      

l2:  pop  dx
     xchg dh,dl
     add  dl,30h
     mov  ah,2
     int  21h
     loop l2 
     mov ah,4ch
     int 21h
code ends
     end begin
