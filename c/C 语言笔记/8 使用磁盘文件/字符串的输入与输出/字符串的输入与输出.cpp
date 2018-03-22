# include <stdio.h>
# include <stdlib.h>

int main (void)
{
	FILE *fp;
	char stp[30];
	char str[20];
	int r ;

	if ((fp = fopen ("name.txt","w")) == NULL)
	{
		fprintf (stderr,"error to open file \n");
		exit (1);
	}

	puts ("请输入一组数据 :");

	fgets ( stp , 20 , stdin);

	fputs ( stp ,fp );

	flushall ();
	fread

	r = ftell(fp);
	printf ("%d\n",r);

	rewind (fp);

	r = ftell(fp);
	printf ("%d\n",r);
    
	fclose (fp);

	if ((fp = fopen ("name.txt","r")) == NULL)//------读取时要用 r 模式
	{
		fprintf (stderr,"error to open file \n");
		exit (1);
	}

	fgets ( str , 20 , fp );

	fputs ( str , stdout );
	fclose (fp);
	
	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
===========================
请输入一组数据 :
Hellow world!!!!
18
0
Hellow world!!!!
Press any key to continue
==========================
*/