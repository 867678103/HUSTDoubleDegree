/*
 ******************************************
 * ���ݹ���á�ʵ������ Copyleft @ ����
 *
 * ������ҳ http://591881218.qzone.qq.com/
 ******************************************
*/

#include <stdio.h>

#define OK 1
#define ERROR 0

int func(int Cnt,int fre, ...);

/* �ݹ飺�����ã���㷵�أ����ص��ϵ� */
int func(int Cnt,int fre, ...)
{	/* �����⵽һ��Ĺ���˼ά */
	printf("Cnt = %d\n",Cnt); // Cnt

	fre++;

	if(Cnt==1)
		return OK; // One return value if Everything is Ok.
	else if(Cnt>1)
		/************************************************************************************************************
		 �����������ִ�е����ս��һ��������func(--Cnt,fre);��ͬʱ��ִ�����Ρ�printf("func(%d) is over!\n",fre);��
		 ���(����)���������������棺��'func' : not all control paths return a value�������б����ú����ķ���ֵ��
		 ��ͨ��ĳһ��(��)����Ĵ������ݣ���������汻���ú�����������ʧ��
		************************************************************************************************************/
		/*��*/func(--Cnt,fre); // ��ջ��Ȼ��Ϊ����ֵ׼���ռ�
		/*��*///return func(--Cnt,fre); // �淶�÷�
	else 
		return ERROR;

	/********************************************************** 
	 fre��ֵ��һ����˵��ÿ�������ú��������Լ������Ķ�ջ�ռ䣬
	 ע�⣬���û������ġ�return OK;������������ֵ�������쳣��
	**********************************************************/
	//printf("func(%d) is over!\n",fre); // Cnt-1

	//return OK; // ƥ�䡰func(--Cnt,fre);����䣬�߼����г��룬����ȥ��
}

int main()
{
	int num=0,fre=0,tmp=0;
	
	printf("Enter a valid positive number: ");
	scanf("%d",&num);
	tmp=func(num,fre);

	if(OK==tmp)
		printf("Everything is Ok!\n\n");
	else if(ERROR==tmp)
		printf("Please input a valid positive number!\n\n");
	else 
		printf("Something is Error!\n\n");

	return OK;
}
