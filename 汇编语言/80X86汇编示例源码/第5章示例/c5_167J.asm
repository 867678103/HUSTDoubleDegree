
; ��ӡ�˷��ھ���
; ���� head ���ڴ�ŵ�һ��Ҫ��ʾ�����ݣ������ظ����
; ���� buf  ���ڴ�ű��е�һ������

crlf macro
     mov ah,2
     mov dl,0ah
     int 21h
     mov dl,0dh
     int 21h
     endm

data segment
head db '    '
     N = 31H
     REPT  9
     db 3 dup(' '),N
     N = N + 1
     ENDM
     db '$'
buf  db '    $'
data ends

stack segment stack
      db 200 dup(0)
stack ends

code segment
     assume cs:code,ds:data
begin:
     mov ax,data
     mov ds,ax

     lea dx,head
     mov ah,9
     int 21h

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
      lea di,buf+3
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
      mov buf+2,' '        ; Ϊ��һ�����׼��

      ret
f2t10 endp

code ends
     end begin
