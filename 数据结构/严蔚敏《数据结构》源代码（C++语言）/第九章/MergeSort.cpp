/*
 ******************************************
 * ע�� ����
 *
 * ������ҳ http://591881218.qzone.qq.com/
 ******************************************
*/

//MergeSort.cpp

#include <iostream.h>
#include <conio.h>
#define MAXSIZE 20

#define LENGTH 7

typedef int RedType;

typedef struct		         //SqList structure
{   /* �������� */
	RedType	r[MAXSIZE+1];    //Records Type
    int length; // ����
}SqList;

typedef SqList RcdType;

/* �������SR[i...m]��SR[m+1...n]�鲢Ϊ�����TR[i...n] */
void Merge(RcdType SR,RcdType &TR,int i,int m,int n)       //Merge() function
{   
	int j,k;
    for(j=m+1,k=i;i<=m&&j<=n;++k) // ��SR�м�¼��С������TR
    {   
		if(SR.r[i]<=SR.r[j])
			TR.r[k]=SR.r[i++];
	    else
			TR.r[k]=SR.r[j++];
    }
    while(i<=m)
        TR.r[k++]=SR.r[i++]; // ��ʣ���SR[i...m]���Ƶ�TR
    while(j<=n)
        TR.r[k++]=SR.r[j++]; // ��ʣ���SR[j...n]���Ƶ�TR
}//end of Merge() function 

/* ��SR[s...t]�鲢����ΪTR1[s...t] */
void MSort(RcdType SR,RcdType &TR1,int s, int t)           //MSort() function     
{  
	int m;
    RcdType TR2;//[LENGTH];
    if(s==t)
		TR1.r[s]=SR.r[t]; // ��������
    else
    {  
		/* �����⵽һ��Ĺ���˼ά */
		m=(s+t)/2; // ��SR[s...t]ƽ��ΪSR[s...m]��SR[m+1...t]
        MSort(SR,TR2,s,m); // �ݹ�ؽ�SR[s...m]�鲢Ϊ�����TR2[s...m]
        MSort(SR,TR2,m+1,t); // �ݹ�ؽ�SR[m+1...t]�鲢Ϊ�����TR2[m+1...t]
        Merge(TR2,TR1,s,m,t); // ��TR2[s...m]��TR2[m+1...t]�鲢��TR1[s...t]
    }//end of else
}//end of MSort() function

/* ��˳���L���鲢���� */
void MergeSort(SqList &L)	//MergeSort() function
{
    MSort(L,L,1,L.length);
}//end of MergeSort() function

void main()		            //main function
{  
	int i;
    SqList L;//={{0,49,38,65,97,76,13,27,},LENGTH};
    cout<<"MergeSort.cpp"<<endl<<"============="<<endl<<endl;
    cout<<"Please input the length of SqList L: <eg. 7> ";
    cin>>L.length;

    cout<<"Please input the disordered array L.r: <eg. {49,38,65,97,76,13,27,...}>"<<endl;
    for(i=1;i<=L.length;i++)
		cin>>L.r[i];
    MergeSort(L);
    cout<<endl<<"The sorted array L.r:  ";
    for(i=1;i<=L.length;i++)
		cout<<L.r[i]<<"  ";
    cout<<endl;
    cout<<"...OK!..."<<endl;
    getch();
}//end of main() function