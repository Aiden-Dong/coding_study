# include <stdio.h>
# include <stdlib.h>

int main (void)
{
	FILE *fp;
	char stp[30];
	char str[10];
	int r ;

	if ((fp = fopen ("name.txt","w")) == NULL)
	{
		fprintf (stderr,"error to open file \n");
		exit (1);
	}

	puts ("请输入一组数据 :");

	fgets ( stp , 10 , stdin );

	fputs ( stp , fp );

	fflush (fp);
	            //--------------注意在两次存取数据与读取之间要先 fclose() 关闭文件

	fgets ( str , 10 , fp );

	fputs ( str , fp );
	fclose (fp);
	
	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
===========================
请输入一组数据 :
afasf
afasf
Press any key to continue
==========================
*/