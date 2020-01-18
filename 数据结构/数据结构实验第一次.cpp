/* Linear Table On Sequence Structure */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2

typedef int status; 
typedef int ElemType; //����Ԫ�����Ͷ���

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef struct     //˳���˳��ṹ���Ķ���
{ 
	ElemType * elem;
	int length;
	int listsize;
}SqList;

status IntiaList(SqList & L) //��ʼ�����Ա� 
{
	L.elem = (ElemType *)malloc( LIST_INIT_SIZE * sizeof (ElemType));
    if(!L.elem) exit(OVERFLOW);
	L.length=0;
    L.listsize=LIST_INIT_SIZE;
	return OK;
}

status DestroyList(SqList & L)	//�������Ա� 
{
	if(!L.elem) return ERROR;
	free(L.elem); 
	L.elem=NULL;
	return OK;	
}

status ClearList(SqList &L) //������Ա� 
{
	if(L.length==0||L.elem==NULL) return ERROR;
	L.length=0;
	return OK;
}

status ListEmpty(SqList L) //�ж����Ա��Ƿ�Ϊ�� 
{
	if(L.elem==NULL) return ERROR-1;
	if(L.length==0) return TRUE;
	else return FALSE;
}
int* ListLength(SqList L) //�������Ա�ĳ��� 
{
	int* p;
	p=&L.length;
	if(!L.elem) return ERROR;
	return p;
}

status GetElem(SqList L,int i,ElemType & e) //��ȡ���Ա�ĵ�i��λ���ϵ�Ԫ�ز���ֵ��e���ء� 
{
	if(!L.elem) return ERROR;
	if(L.length<i||i<=0) return ERROR-1;
	e=L.elem[i-1];
	return e;
}
status LocateElem(SqList L,ElemType e) //�ҳ�Ԫ��e�����Ա��е�һ�γ��ֵ�λ�ò���������λ�� 
{
	if(!L.elem) return ERROR;
	for(int i=0;i<L.length;i++)
	{
		if(L.elem[i]==e) return i+1;	
	}	
	return ERROR;
}
status PriorElem(SqList L,ElemType cur,ElemType & pre_e) //�ҵ����Ա��Ԫ��cur��ǰ��������ֵ��pre_e 
{
	if(!L.elem) return ERROR;
	for(int i=0;i<L.length;i++)
	{
		if(cur==L.elem[i]&&i>0) 	
		{
			pre_e=L.elem[i-1];
			return TRUE;
		}
	}
	return ERROR;
}
status NextElem(SqList L,ElemType cur,ElemType & next_e) //�ҵ�curԪ�صĺ�̣�����ֵ��next_e 
{
	if(!L.elem) return ERROR;
	for(int i=0;i<L.length;i++)
	{
		if(cur==L.elem[i]&&(i+1)!=L.length) 
		{
			next_e=L.elem[i+1];
			return TRUE;
		}
	}
	return ERROR;
}
status ListInsert(SqList & L,int i,ElemType e) //��Ԫ��e�������Ա�ĵ�i��λ�� 
{
	ElemType* newbase;
	ElemType*p;
	ElemType*q;
	if(!L.elem) return ERROR;
	if(i<1||i>L.length+1) return ERROR;
	if(L.length>=L.listsize) 
	{
		newbase=(ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase) exit(OVERFLOW);
		L.elem=newbase;
		L.listsize+=LISTINCREMENT;
	}
	q=&(L.elem[i-1]);
	for(p=&(L.elem[L.length-1]);p>=q;--p) *(p+1)=*p;
	*q=e;
	++L.length;
	return OK;
} 

status ListDelete(SqList & L,int i,ElemType & e) //ɾ��ָ��λ�õ����Ա�Ԫ�ز�����Ԫ��ͨ��e���� 
{
	ElemType*p;
	ElemType*q;
	if((i<1)||(i>L.length)) return ERROR;
	p=&(L.elem[i-1]);
	e=*p;
	q=L.elem+L.length-1;
	for(++p;p<=q;++p)
	{
		*(p-1)=*p;
	}
	--L.length;
	return OK;
}
status ListTrabverse(SqList L){
   int i;
   printf("\n-----------all elements -----------------------\n");
   for(i=0;i<L.length;i++) printf("%d ",L.elem[i]);
   printf("\n------------------ end ------------------------\n");
   return L.length;
}  
/*-----------------���ӹ���-------------------------*/
status WriteFile(SqList& L,char* filename) //�����Ա�Ԫ��д���ļ� 
{
	FILE  *fp;
	if ((fp=fopen(filename,"w"))==NULL)
	{
		printf("File open erroe\n ");
		return ERROR;
	}
	fwrite(&L.elem,sizeof(ElemType),L.length,fp);
	fclose(fp);
  	return OK;
} 
status ReadFile(SqList& L,char* filename) //���ļ���Ԫ�ض������Ա� 
{
	FILE *fp;
	L.length=0;
	if ((fp=fopen(filename,"r"))==NULL)
	{
	 printf("File open erroe\n ");
	 return 1;
	}
	while(fread(&L.elem[L.length],sizeof(ElemType),1,fp))
		L.length++;
	
	for(int i=0;i<L.length;i++)
	{
		printf("%d\t",L.elem[i]);
	}
	fclose(fp);
	return 0;
}


int main(void){
  SqList L;
  int op=1;
  int i;
  int e;
  int pre_e;
  int cur_e;
  int next_e;
  char filename[30];
  
  while(op){
	system("cls");
	printf("\n\n");
	printf("      Menu for Linear Table On Sequence Structure \n");
	printf("-------------------------------------------------\n");
	printf("    	  1. IntiaList       7. LocateElem\n");
	printf("    	  2. DestroyList     8. PriorElem\n");
	printf("    	  3. ClearList       9. NextElem \n");
	printf("    	  4. ListEmpty     10. ListInsert\n");
	printf("    	  5. ListLength     11. ListDelete\n");
	printf("    	  6. GetElem       12. ListTrabverse\n");
	printf("          13.�����б���Ԫ��д���ļ� 14.���ļ�\n");
	printf("    	  0. Exit        \n");
	printf("-------------------------------------------------\n");
	printf("    ��ѡ����Ĳ���[0~14]:");
	scanf("%d",&op);
    switch(op){
	   case 1:
		 //printf("\n----IntiaList���ܴ�ʵ�֣�\n");
		 if(IntiaList(L)==OK) printf("���Ա����ɹ���\n");
		     else printf("���Ա���ʧ�ܣ�\n");
		 getchar();getchar();
		 break;
	   case 2:
		 //printf("\n----DestroyList���ܴ�ʵ�֣�\n"); 
		 if(DestroyList(L)==OK) printf("���Ա����ٳɹ���\n");
		 else printf("���Ա����ڣ�\n");    
		 getchar();getchar();
		 break;
	   case 3:
		 //printf("\n----ClearList���ܴ�ʵ�֣�\n");   
		 if(ClearList(L)==OK) printf("���Ա�Ԫ������ɹ���\n");
		 else printf("���Ա������ǿյģ�\n");  
		 getchar();getchar();
		 break;
	   case 4:
		 //printf("\n----ListEmpty���ܴ�ʵ�֣�\n");     
		 if(ListEmpty(L)==OK) printf("���Ա�Ϊ�ձ�\n");
		 else if(ListEmpty(L)==FALSE)  printf("���Ա�Ϊ�գ�\n");
		 else if(ListEmpty(L)==ERROR-1) printf("���Ա�����\n"); 
		 getchar();getchar();
		 break;
	   case 5:
		 //printf("\n----ListLength���ܴ�ʵ�֣�\n");     
		 if(ListLength(L)) printf("���Ա���%d��Ԫ��",*(ListLength(L)));
		 else printf("���Ա����ڣ�");
		 getchar();getchar();
		 break;
	   case 6:
		 //printf("\n----GetElem���ܴ�ʵ�֣�\n"); 
		 printf("��������Ҫ�ҵ��±�������");
		 scanf("%d",&i);    
		 if(GetElem(L,i,e)==ERROR) printf("���Ա����ڣ�\n");
		 else if(GetElem(L,i,e)==ERROR-1) printf("���Ա���������±��Ԫ�أ�\n");
		 else printf("��%d��Ԫ��Ϊ%d",i,e);
		 getchar();getchar();
		 break;
	   case 7:
		 //printf("\n----LocateElem���ܴ�ʵ�֣�\n");     
		 printf("������һ���������������Ա��е�һ��������ͬ��λ��");
		 scanf("%d",&e);
		 if(LocateElem(L,e)==0) printf("������Ԫ�ز����ڣ�\n");
		 else printf("��Ԫ�ص�λ���ǣ�%d",LocateElem(L,e));
		 getchar();getchar();
		 break;
	   case 8:
		 //printf("\n----PriorElem���ܴ�ʵ�֣�\n");     
		 printf("���������ݽ����ظ����ݵ�ǰ����");
		 scanf("%d",&cur_e);
		 if(PriorElem(L,cur_e,pre_e)==ERROR) printf("����ʧ�ܣ�pre_e�޶��壡\n");
		 else printf("ǰ����%d",pre_e);
		 getchar();getchar();
		 break;
	   case 9:
		 //printf("\n----NextElem���ܴ�ʵ�֣�\n");  
		 printf("���������ݽ����ظ����ݵĺ�̣�");
		 scanf("%d",&cur_e);   
		 if(NextElem(L,cur_e,next_e)==ERROR) printf("next_e�޶��壡\n");
		 else printf("�����%d",next_e);
		 getchar();getchar();
		 break;
	   case 10:
		 //printf("\n----ListInsert���ܴ�ʵ�֣�\n");     
		 printf("����������λ��i:");
		 scanf("%d",&i);
		 printf("�����뽫��������ݣ�");
		 scanf("%d",&e);
		 if(ListInsert(L,i,e)==ERROR) printf("����λ�ô�������Ա�����\n");
		 else printf("����ɹ���\n");
		 getchar();getchar();
		 break;
	   case 11:
		 //printf("\n----ListDelete���ܴ�ʵ�֣�\n");    
		printf("������ɾ����λ��i:");
		 scanf("%d",&i);
		 if(ListDelete(L,i,e)==ERROR) printf("λ�ô�������Ա�����\n");
		 else printf("ɾ��λ��Ԫ��%d",e);
		 getchar();getchar();
		 break;
	   case 12:
		 //printf("\n----ListTrabverse���ܴ�ʵ�֣�\n");     
		 if(!ListTrabverse(L)) printf("���Ա��ǿձ�\n");
		 getchar();getchar();
		 break;
		case 13:
			printf("input file name: ");
			scanf("%s",filename);
			if(WriteFile(L,filename)) printf("�ļ�д��ɹ���\n");
			else printf("д��ʧ��");
			getchar();getchar();
			break;
		case 14:
			printf("input filename:");
			scanf("%s",&filename);
			ReadFile(L,filename);
			getchar();getchar();
			break;

	   case 0:
         break;
	}//end of switch
  }//end of while
  printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
}//end of main()






