#include <stdio.h>

int x=0;
int a[5];
int y=0;

int main(int argc, char* argv[])
{
    int i;
    for (i=0;i<=5;i++)
	    a[i]=i;
    printf("%d %d\n",x,y);
    return 0;
}
































/*
��ַ����	ʵ�ʵ�ַ			��ʼ����		���н��
&x				0x004235bc		0						0
&y				0x004235c0		0						0
a[0]			0x004237c0		?						0
a[1]			0x004237c4		?						1
a[2]			0x004237c8		?						2
a[3]			0x004237cc		?						3
a[4]			0x004237d0		?						4
*/