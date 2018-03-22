#include <stdio.h>
#include <string.h>

int main ()
{
	FILE *fp1 ;
	FILE *fp2 ;

	char namep[30];
	char nameg[30];

	puts ("请输入要复制的文件路径及具体文件");
	gets(namep);
	puts ("请输入要复制的文件路径");

	int len = strlen (namep);
	char names[10];
	char *p;
	int i;
	for (i = len-1 ; i > 0 ; i--)
	{
		if(namep[i-1] == '/')
		{
			p = &namep[i];
			break; 
		}
	}
	if (i==0)
	{
		puts ("文件输入 : E:/file1/file......");
		return 0;
	}

	strcpy (names , p);
	strcat (nameg , names);

	fp1 = fopen (namep , "rb");
	fp2 = fopen (nameg , "wb");

	char buf[1000];
	memset (buf , 0 , sizeof (buf));
	int num ;
	while ((num = fread (buf , sizeof(buf) , 1 , fb1)) >0 )
	{
		fwrite (buf , num , 1 , fb2);
		memset (buf , 0 , sizeof (buf));
	}

	fclose (fb1);
	fclose (fb2);

	return 0 ;
}