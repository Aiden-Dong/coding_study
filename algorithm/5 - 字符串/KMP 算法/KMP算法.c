#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct _Kmp
{
	char ch;
	int next ;
} Kmp , *pKmp;

void InitKmp (pKmp * kmp , char * str);
int KmpAL (char * Mainstr , pKmp one);

int main ()
{
	int i , a;
	int first;
	pKmp one ; // 存放模式串
	char str[10];
	char sl[301];
	int *l;

	srand ((unsigned int)time(NULL));
	for (i = 0 ; i < 300 ; i++)
	{
		a = rand()%5+97;
		sl[i]=a;
	}
	sl[i]='\0';
	printf ("%s\n",sl);

	puts ("请输入要匹配的模式串 : ");
	gets(str);
	InitKmp (&one , str);

	first = KmpAL (sl,one);

	if (first == -1)
		puts ("不存在匹配项目!!");
	else
	{
		printf ("你要查找的第一点位于 %d 处\n",first);
		l = &sl[first];
		puts(l);
	}

	return 0;
}

void InitKmp (pKmp * kmp , char * str)
{
	int x , y ;
	int i = strlen(str);
	(*kmp) = (pKmp) malloc (sizeof(Kmp)*(i+1));

	for (x = 1 ; x < i+1 ; x++)
	{
		(*kmp)[x].ch = *(str);
		str++;
	}

	x = 0 , y = 1;
	(*kmp)[0].next = i+1;
	(*kmp)[1].next = 0;

	while (y != i)   // next 数组的核心算法
	{
		if( x==0 || (*kmp)[x].ch==(*kmp)[y].ch)
		{
			x++;
			y++;
			(*kmp)[y].next = x;
		}
		else
			x = (*kmp)[x].next;
	}

}

int KmpAL (char * Mainstr , pKmp one)
{
	int first  = strlen (Mainstr);
	int second = one[0].next;

	int i = 0;
	int j = 1;
	int on = 0;

	while (j < second && i < first)
	{
		if (j == 0)
		{
			i++;
			j++;
			on = i;
		}
		if (Mainstr[i] == one[j].ch)
		{
			i++;
			j++;
		}
		else
		{
			j = one[j].next;
			
		}
	}
	
	if (i < first)
		return on;
	else
		return -1;
}