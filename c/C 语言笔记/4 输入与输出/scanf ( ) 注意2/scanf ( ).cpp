# include <stdio.h>

int main( void )
{
	int a;
	char c; do
	{
		printf ("请输入 :\n");
		scanf("%d",&a);

		scanf("%c",&c);

		printf("a=%d c=%c\n",a,c);
		printf("c=%d\n",c);
	}while(c!='N');
}
