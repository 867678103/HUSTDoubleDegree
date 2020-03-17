#include<stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASTABLE -1
#define OVERFLOW -2
typedef int ElemType;
typedef int status;

typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode, *LinkList;

status InitaList(LinkList &L) //��ʼ�������� 
{
	L=(LinkList)malloc(sizeof(LNode));
	if(!L)
	{
		return ERROR;	
	}	
	L->next=NULL;
	return TRUE;
}

status DestroyList(LinkList&L) //���ٵ����� 
{
	LinkList p;
	p=L;
	if(!L) return ERROR;
	while(L)
	{
		p=L->next;
		free(L);
		L=p;		
	} 
	return OK;
}

status ClearList (LinkList&L) //��յ����� 
{
	LinkList p,q;
	if(!L) return ERROR;
	p=L->next;
	while(p)
	{
		q=p->next;
		free(p);
		p=q;
	}
	L->next=NULL;
	return OK;
}
status ListEmpty(LinkList L) //�ж������Ƿ�Ϊ�� 
{
	if(!L) return ERROR;
	if(L->next==NULL) return OK;
	else return ERROR;
}

status ListLength(LinkList L)	//���������� 
{
	int count=0;
	if(!L) return ERROR;
	while(L->next)
	{
		count++;
		L=L->next;
	}
	return count;
}

status GetElem(LinkList L,ElemType i,ElemType &e) //��ȡiλ�õ�Ԫ�� 
{
	if(!L) return ERROR;
	int c=1;
	LinkList p;
	p=L->next;
	while(c<i&&p)
	{
		p=p->next;
		c++;
	} 
	if(c<i) return ERROR;
	e=p->data;
	return OK;
}

status LocateElem(LinkList L,ElemType e) //����Ԫ�ص�λ�� 
{
	if(!L) return ERROR;
	LinkList p;
	p=L;
	int count=0;
	while(p->next)
	{
		p=p->next;
		count++;
		if(p->data==e) return count; 
	}
	return ERROR;
}

status PriorElem(LinkList L,ElemType cur_e,ElemType& pre_e) //����Ԫ�ص�ǰ�� 
{
	if(!L) return ERROR;
	LinkList p,q;
	p=L->next;
	q=L;
	while(p->next)
	{
		if((p->data==cur_e)&&q!=L) 
		{
			pre_e=q->data;
			return OK;
		}
		p=p->next;
		q=q->next;
	}
	if(p->data==cur_e) 
	{
		pre_e=q->data;
		return OK;
	}
	return ERROR;
}

status NextElem(LinkList L,ElemType cur_e,ElemType& next_e) //����Ԫ�صĺ�� 
{
	if(!L) return ERROR;
	LinkList p;
	p=L;
	while(p->next)
	{
		p=p->next;
		if(p->data==cur_e)
		{
			if(p->next)
			{
				next_e=p->next->data;
				return OK;
			}
			else return ERROR;
		}
	}
	return ERROR;
}

status ListInsert(LinkList &L,ElemType i,ElemType e) //��ָ��λ�ò���Ԫ�� 
{
	if(!L) return ERROR;
	LinkList p,s;
	p=L;
	int c=0;
	while(p&&c<i-1)
	{
		p=p->next;
		c++;	
	} 
	if(!p||c>i-1) return ERROR;
	s=(LinkList)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return OK;
}

status ListDelete(LinkList &L,ElemType i,ElemType& e) //ɾ���������ָ��λ��Ԫ�� 
{
	if(!L) return ERROR;
	LinkList p,q;
	p=L;
	int j=0;
	while(p->next&&j<i-1)
	{
		p=p->next;++j;
	}
	if(!(p->next)||j>i-1) return ERROR;
	q=p->next;
	p->next=q->next;
	e=q->data;
	free(q);
	return OK;
	
}
status ListTraverse(LinkList L) //���������� 
{
	if(!L)
	{
		printf("���������ڡ�");
		return ERROR;
	}
	LinkList p;
	p=L;
	printf("\n-----------all elements -----------------------\n");
	while(p->next)
	{
		p=p->next;
		printf("%d ",p->data);
	}
	printf("\n------------------ end ------------------------\n");
	return OK;
}


int main()
{
	LinkList L=NULL;
	int op=1; 
	int i,e;
	ElemType cur_e,pre_e,next_e; 
	while(op){
		system("cls");
		printf("\n\n");
		printf("      Menu for Linear Table On LinkList Structure \n");
		printf("-------------------------------------------------\n");
		printf("    	  1. InitaList       7. LocateElem\n");
		printf("    	  2. DestroyList     8. PriorElem\n");
		printf("    	  3. ClearList       9. NextElem \n");
		printf("    	  4. ListEmpty     10. ListInsert\n");
		printf("    	  5. ListLength     11. ListDelete\n");
		printf("    	  6. GetElem       12. ListTrabverse\n");
		printf("    	  0. Exit        \n");
		printf("-------------------------------------------------\n");
		printf("    ��ѡ����Ĳ���[0~12]:");
		scanf("%d",&op);
   		switch(op){
		   	case 1:
			 	if(InitaList(L)==OK) printf("���������ɹ���\n");
		     	else printf("��������ʧ�ܣ�\n");
			 	getchar();getchar();
		 		break;
			case 2:
				if(DestroyList(L)==OK) printf("���������ٳɹ���\n");
		     	else printf("�����Ͳ����ڵ�����\n");
			 	getchar();getchar();
				break;
			case 3:
				if(ClearList(L)==OK) printf("��������ճɹ���\n");
		     	else printf("�����ڵ�����\n");
			 	getchar();getchar();
				break;
			case 4:
				if(ListEmpty(L)==OK) printf("�������ǿյģ�\n");
		     	else printf("�������ǿյĻ򲻴��ڣ�\n");
			 	getchar();getchar();
				break;
			case 5:
				if(ListLength(L)) printf("��������Ϊ%d\n",ListLength(L));
		     	else printf("���������ڻ򳤶�Ϊ0��\n");
			 	getchar();getchar();
				break;
			case 6:
				printf("������Ҫ���ҵ�Ԫ��λ�ã�");
				scanf("%d",&i);
				if(GetElem(L,i,e)==OK) printf("��%d��Ԫ����%d\n",i,e);
		     	else printf("���������ڻ���û�����λ�ã�\n");
			 	getchar();getchar();
				break;
			case 7:
				printf("������������ҵ�Ԫ��ֵ��");
				scanf("%d",&e);
				if(LocateElem(L,e)) printf("Ԫ��%d��λ����%d\n",e,LocateElem(L,e));
		     	else printf("���������ڻ򲻴������Ԫ�أ�\n");
			 	getchar();getchar();
				break;
			case 8:
				printf("������Ԫ�ؽ�������ǰһ��Ԫ�أ�");
				scanf("%d",&cur_e);
				if(PriorElem(L,cur_e,pre_e)==OK) printf("Ԫ��%d��ǰһ��Ԫ����%d\n",cur_e,pre_e);
		     	else printf("���������ڻ򲻴���ǰһ��Ԫ�أ�\n");
			 	getchar();getchar();
				break;
			case 9:
				printf("������һ��Ԫ��ֵ����������һ��Ԫ�أ�");
				scanf("%d",&cur_e);
				if(NextElem(L,cur_e,next_e)==OK) printf("Ԫ��%d�ĺ�һ��Ԫ����%d\n",cur_e,next_e);
		     	else printf("���������ڻ�Ԫ�ز����ڣ�\n");
			 	getchar();getchar();
				break;
			case 10:
				printf("���������Ԫ�ص�λ��:");
				scanf("%d",&i);
				printf("���������Ԫ�ص�ֵ��");
				scanf("%d",&e);
				if(ListInsert(L,i,e)==OK) printf("Ԫ�ز���ɹ���\n");
		     	else printf("ʧ�ܣ�\n");
			 	getchar();getchar();
				break;
			case 11:
				printf("������ɾ��Ԫ�ص�λ��:");
				scanf("%d",&i);
				if(ListDelete(L,i,e)==OK) printf("Ԫ��ɾ���ɹ���ɾ��Ԫ��Ϊ%d\n",e);
		     	else printf("ʧ�ܣ�\n");
			 	getchar();getchar();
				break;
			case 12:
				ListTraverse(L);
			 	getchar();getchar();
				break;
	   		case 0:
         		break;
	}//end of switch
  }//end of while
  printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
	return 0;
}

