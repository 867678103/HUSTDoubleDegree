
; ��ӡ�˷��ھ���
; ���� head ���ڴ�ŵ�һ�е�һ������
; ���� buf  ���ڴ�ű��е�һ������

crlf macro
     mov ah,2
     mov dl,0ah
     int 21h
     mov dl,0dh
     int 21h
     endm

data segment
head db '   $'
buf  db '   $'
data ends

code segment
     assume cs:code,ds:data
begin:
     mov ax,data
     mov ds,ax

     mov cx,9
     mov si,offset head+2

     lea dx,head
     mov ah,9
     int 21h
     mov bl,31H
l1:
     mov [si],bl
     int 21h
     inc bl
     loop l1

     crlf

     mov ch,1           ; ��ӡ 9��  (��Ҫ��ch ��Ϊһ������ ��
l2:
     mov al,ch
     mov ah,0
     call f2t10         ; ����ߵĳ���  (ch)

     mov cl,1           ; ��Ϊ һ�� ���еĳ���������ѭ���б仯��
l3:
     mov al, cl
     mul ch
     call f2t10         ; ��ת�������� AX��
     inc cl
     cmp cl,10
     jb  l3
     crlf
     inc ch
     cmp ch,10
     jb  l2
     crlf          
     mov ah,4ch
     int 21h


f2t10 proc
      lea di,buf+2
      mov bl,10
start:
      div bl
      add ah,30h
      mov [di],ah
      dec di
      cbw 
      cmp al,0
      jne start

      lea dx,buf
      mov ah,9
      int 21h
      mov buf+1,' '        ; Ϊ��һ�����׼��

      ret
f2t10 endp

code ends
     end begin
