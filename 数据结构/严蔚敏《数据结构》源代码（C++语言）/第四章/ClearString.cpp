/*
 ******************************************
 * ע�� ����
 *
 * ������ҳ http://591881218.qzone.qq.com/
 ******************************************
*/

//ClearString.cpp
//Clear the String

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <iostream.h>
#include <stdlib.h>

#define MAXSIZE_S 40
#define OK 1
#define ERROR 0

typedef struct
{	
	char * ch; // ����ͷָ��
	int length; // ���ĳ���
}HString;

/* ��մ� */
int ClearString(HString &S)         //ClearString() function
{   //To clear the string S to be empty
    if (S.ch) // �ͷŴ�
    {free(S.ch); S.ch=NULL;}       //if S.ch !=NULL then free it
    S.length =0; // ��������
    return(OK);                      //success to clear the string S
}//end of clearString

/* ��ʼ���� */
int StrAssign(HString &S,char * chars)               //StrAssign() function
{                                                    //create a string T=chars
	int i=0,j;
	char *c;
	/********************************
	 ԭ������ղ���ʧ�ܣ�����Ϊʲô��
	********************************/
	// ����Ϊ�գ���մ�
	//if(S.ch) free(S.ch);                             //dispose(T)
	for(c=chars;c[i]!='\0';i=i+1);// ���㴮�ĳ���
                         							 //i get the length of chars
	if(!i) // ����Ϊ��
	{S.ch=NULL;S.length=0;}                          //if i==0 then set String T NULL
    else // ���Ȳ�Ϊ��
	{
		if(!(S.ch=(char *)malloc(i*sizeof(char)))) // Ϊ������ռ�
		{ 
			cout<<"OVERFLOW!"<<endl;
		    return (ERROR);
		}//end of if
		else // ����ռ�ɹ���Ϊ����ֵ
		{  
			for(j=0;j<=i-1;j++)
				S.ch[j]=chars[j];
			/* ԭ������һ������ */
			//S.ch[j]='\0'; // �˳����У����ӽ�����λ�þ�Ȼ��һ��
			S.ch[j-1]='\0'; // �����÷����������ǵ���ͨ���ռ��ͷ�ʧ��
		    S.length=i; 
		}//end of else                                        
	}//end of else        
	printf("S.ch = %s\n",S.ch);
	return(OK);
}//end of StrAssign() function

void main()                                              //main() function
{
    char charsS[MAXSIZE_S];                               //user define here
    HString S;
    cout<<"ClearString.cpp"<<endl<<"================"<<endl;
    cout<<"Please input the string S: ";
    cin>>charsS;
    StrAssign(S,charsS);
    cout<<"Clear String result: "<<ClearString(S)<<endl;
    cout<<"...OK!"<<endl;
    getch();
}


