/*
 ******************************************
 * ע�� ����
 *
 * ������ҳ http://591881218.qzone.qq.com/
 ******************************************
*/

//DubSqStack.cpp

#include <stdlib.h>
#include <iostream.h>
#include <conio.h>
#include <stdio.h>

#define MAXSIZE  10
#define DUSTACKSIZE MAXSIZE

typedef int SElemType ;
typedef struct DuSqStack
{	
	SElemType  data[MAXSIZE-1];                   //array[0..MAXSIZE-1] for the DuSqStack
	int top1;                                     //top1 is the pointer of  DuSqStack S1
	int top2;                                     //top2 is the pointer of  DuSqStack S2
	int flag;                                     //if flag variable=1 then operate S1                                                 
}DuSqStack;                                       //else if flag=2 then operate S2

void InitDuSqStack(DuSqStack &S)                  //InitDuSqStack() function
{ 	
	S.top1=1;// ջ��1
	S.top2=MAXSIZE-2; // ջ��2                            //Initialize the Pointers of DuSqStack
}//end of InitDuSqStack() function

/* ��ջ */
int DuSqStackPush(DuSqStack &S,SElemType x)        //DuSqStackPush() function
{   //S is a shared stack this function will push x into stack S  
	cout<<"Please input the element x: <eg. 2001> ";
    cin>>x; 
	if(S.top1+1==S.top2)                           //if the two stack are full, then return error    
	{  
		cout<<endl<<"The DuSqStack is full!"<<endl;
	    return (0);
	}
	else
	{ 
		cout<<"Select the stack S1 or S2 to push ? <1 or 2>: ";
	    cin>>S.flag;
	    if ((S.flag!=1)&&(S.flag!=2))              //flag == 1 or 2 ? otherwise return 0
		{
			cout<<endl<<"Error!"<<endl<<"the stack needs to be '1' or '2'!"<<endl;
	        return(0);
		}
		else
		{  
			switch(S.flag)
			{ 
			    case 1:/* ѹ��ջ1 */
					S.data[S.top1]=x;
				    S.top1++; // �������ɣ�ע��ջ��ָ����һ��λ��
				    break;
			    case 2:/* ѹ��ջ2 */
					S.data[S.top2]=x;
				    S.top2--; // �������ɣ�ע��ջ��ָ����һ��λ��						 						 
					break;
			}//end of switch                                    
		    cout<<"'"<<x<<"'"<<" has been pushed into DuSqStack successfully!"<<endl<<endl;
			return (1);
		}//end of else                                        
	}//end of else									         
}//end of DuSqStackPush() function    

/* ��ջ */
int DuSqStackPop(DuSqStack &S,SElemType &x)
{                                                    //S is a shared stack 
                                                     //this function will pop the top element
	                                                 //from S.top1 or S.top2 by x 
    cout<<endl<<"Select the stack S1 or S2 to POP ? (1,2): ";
	cin>>S.flag;
	if((S.flag!=1)&&(S.flag!=2))                     //if S.flag!=1,2 then ERROR
	{ 
		cout<<endl<<"The DuSqStack is full!"<<endl;
	    return (0);
	}
    else
	{
		switch(S.flag)
		{
		    case 1:/* ����ջ1 */
	            if(S.top1>1)                     //if S1 is not empty then operate S1
				{
					S.top1--;                   //modify stack top pointer S.top1
					x=S.data[S.top1];           //pop x
				}//end of if                            
				else // ջ1Ϊ��
				{
					cout<<"S1 is an empty stack,failure to POP element from it!"<<endl;
					return(0);
				}
				break;
			 case 2:/* ����ջ2 */
				if(S.top2<MAXSIZE-2)
				{
					S.top2++;
					x=S.data[S.top2];
				}//end of if                            
				else // ջ2Ϊ��
				{
					cout<<"S2 is an empty stack,failure to POP element from it!"<<endl;
					return(0);
				}
				break;
		}//end of switch                                         
	    cout<<"Success to POP the element "<<"from DuSqStack!: "<<x<<endl<<"...OK...!"<<endl;
	    return (1);
	}//end of else                                                
}//end of DuSqStackPop() function                                                     
	
void main()                                          //main() function
{  
    DuSqStack S;                                       
    SElemType x=2000;                                 //push x into DuSqStack S
    cout<<"DuSqStack.cpp"<<endl<<"============="<<endl<<endl;
    InitDuSqStack(S);                                 //To Initilaize DuSqStack
   
    DuSqStackPush(S,x);                               //Test DuSqStackPush function twice
    DuSqStackPush(S,x);                               //for example to push two element into DuSqStack    
    DuSqStackPop(S,x);                                //Test DuSqStackPop function
                                                     //and return by x
    getch();
}
