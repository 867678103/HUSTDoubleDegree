; (1) �۲���ǰ׺�Ĵ�����ָ��, si, di�ı仯
; (2) �۲���ǰ׺�Ĵ�����ָ���CX����0ʱ��si, di�ı仯
; (3) �۲���ǰ׺�Ĵ�����ָ��
; �۲� �� CX=0 ʱ�������Ƿ��ƶ���SI, DI �Ƿ�仯
; �۲� �� CX<>0  ʱ�����ݵ��ƶ������SI,DI ��ָ��ʲô��Ԫ

.386
data segment USE16 
buf1  db '012345'
n    = $ -buf1
buf2  db 'abcdef'
data  ends

stack segment  USE16 stack
      db 200 dup(0)
stack ends

code segment USE16 
     assume cs:code,ss:stack,ds:data,es:data
begin:
     mov ax, data
     mov ds, ax
     mov es, ax
     lea si, buf1
     lea di, buf2
     cld
     
     mov cx, n
     ; mov cx, 0
     movsb       ;�ȹ۲���ǰ׺�Ĵ�����ָ��
     rep movsb

     mov ah,4ch
     int 21h
code ends
     end begin
