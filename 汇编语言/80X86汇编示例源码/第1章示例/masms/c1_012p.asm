; P11 ~ P13 �е�ָ��˵��
; ʾ��1 ��  push  04f8h
; ��1.1 ,   
; PUSHA
; PUSHAD
;        ˵����(1)  ��8086�Ļ���У������������� push�ᱨ��
;              (2)  ��.386����£������򲻻ᱨ��
;              (3)  ʹ����.386��Ӧָ������ 16λ�Σ���USE16.
;              (4)  ��ʹ����.386,����USE16ʱ��ȱʡ�� USE32��
;              (5)  TD.exe ֻ�ܵ��� 16λ�εĻ�����
.386
my_stack  segment  use16 stack  
          db 200 dup(0)
my_stack  ends

my_code  segment  use16
         assume cs:my_code, ss:my_stack
begin:
         push 04f8h        ; ʾ��1
         
         mov  eax,7ffA0011h  ; ��1.1        
         push eax          
         pop  bx
         pop  ecx
         
         mov  ax,1122h       ; ʾ��3
         mov  bx,3344h
         mov  cx,5566h
         mov  dx,7788h
         mov  bp,1234h
         mov  si,0AABBH
         mov  di,0CCDDH
         PUSHA             ; ax, cx,dx, bx, sp,bp, si, di
                           ; �����spֵ����ִ�и�ָ��ǰ��sp��ֵ��
         
         PUSHAD            ; eax,ecx,edx,ebx,esp,ebp,esi,edi
         
         mov  ah,4ch
         int  21h
my_code  ends
         end  begin
                  
                           
