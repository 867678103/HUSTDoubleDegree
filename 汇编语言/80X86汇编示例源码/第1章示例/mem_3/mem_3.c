#include <stdio.h>

int main(int argc, char* argv[])
{
	/* �����˳������е��ڴ�ռ䣬����ϵͳ�ڴ汣�� */
	int x=0;
	int a[5];
	int y=0;
	int i;
	for (i=0;i<=7;i++)
		a[i]=i;
	printf("%d %d\n",x,y);
	return 0;
}







































/*
��ַ����	ʵ�ʵ�ַ			��ʼ����		���н��
&y				0x0012ff64		0						0
a[0]			0x0012ff68		?						0
a[1]			0x0012ff6c		?						1
a[2]			0x0012ff70		?						2
a[3]			0x0012ff74		?						3
a[4]			0x0012ff78		?						4
&x				0x0012ff7c		0						5
*/
