# include <stdlib.h>
# include <stdio.h>

int main ()
{
	FILE * fp ;
	char *a = "hellow" ;
	char b ;

	fp = fopen ("E:\\计算机编程\\c 语言\\C 语言笔记\\8 使用磁盘文件\\first.txt" , "a") ;

	while (*a != '\0')
	{
		fputc (*a , fp) ;
		a++ ;
	}

	fclose (fp);

	fp = fopen ("E:\\计算机编程\\c 语言\\C 语言笔记\\8 使用磁盘文件\\first.txt" , "r") ;

	while (!feof (fp))
	{
		b = fgetc (fp) ;
		putchar (b) ;
	}

	fclose (fp) ;

	return 0 ;
}