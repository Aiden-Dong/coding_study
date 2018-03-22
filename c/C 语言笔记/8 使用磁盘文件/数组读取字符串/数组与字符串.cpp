# include <stdio.h>
# include <stdlib.h>

int main (void)
{
	FILE *fp;
	char stp[2][30];
	char str[2][20];
	int r ;
	int i;
	
	if ((fp = fopen ("name.txt","w+")) == NULL)
	{
		fprintf (stderr,"error to open file \n");
		exit (1);
	}
	
	puts ("请输入一组数据 :");
	
	for ( i = 0 ; i <= 1 ; i ++ )
	{
		
		fgets ( stp[i] , 20 , stdin);
		
		fputs ( stp[i] ,fp );
	}
	
	flushall ();
	
	
	r = ftell(fp);
	printf ("%d\n",r);
	
	rewind (fp);
	
	r = ftell(fp);
	printf ("%d\n",r);
    
	for ( i = 0 ; i <= 1 ; i ++ )
	{	
		fgets ( str[i] , 20 , fp );
		
		fputs ( str[i] , stdout );
	}

	fclose (fp);
	
	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
===========================
请输入一组数据 :
Hellow world!!!!
I will hold on !
36
0
Hellow world!!!!
I will hold on !
Press any key to continue
==========================
*/