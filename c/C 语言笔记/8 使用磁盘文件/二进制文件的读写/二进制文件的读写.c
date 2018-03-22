# include <stdio.h>

typedef struct one
{
	char name[10] ;
	int a ;
	int b ;
	char c ;
} first , *pfirst ;

int main ()
{
	FILE *fp ;
	int i ;
	first table[2] = {
		{"saligia" , 12 , 30 ,'A'} ,
		{"fing" , 14 , 21 , 'D'} 
	} ;

	first tak[2] ;

	strcpy (table[0].name , "saligia") ;
	strcpy (table[1].name , "jin") ;

	fp = fopen ("E:/计算机编程/c 语言/C 语言笔记/8 使用磁盘文件/one.dat" , "ab");

	for (i = 0 ; i < 2 ; i++)
		fwrite (&table[i] , sizeof(table[i]) , 1 , fp) ;

	fclose (fp) ;

	fp = fopen ("E:/计算机编程/c 语言/C 语言笔记/8 使用磁盘文件/one.dat" , "rb");

	for (i = 0 ; i < 2 ; i++)
		fread (&tak[i] , sizeof(table[i]) , 1 , fp) ;

	for (i = 0 ; i < 2 ; i++)
	{
		puts (tak[i].name) ;
		printf ("%d\n",tak[i].a ) ;
		printf ("%d\n",tak[i].b ) ;
		printf ("%c\n",tak[i].c ) ;
	}

	return 0 ;
}
/*
在 VC++6.0 的运行环境中 :
============================
saligia
12
30
A
jin
14
21
D
============================
*/
