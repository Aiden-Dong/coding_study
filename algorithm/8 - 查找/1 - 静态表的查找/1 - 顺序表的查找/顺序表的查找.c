#include "sstable.h"

int main ()
{
	int a ;
	pssTable one ;
	char name[10];
	printf ("请输入表的大小 : \n");
	scanf ("%d",a);
	
	Create (one , a);
	puts ("请输入要查找的信息");
	gets (one,a,name);

	return 0;
}