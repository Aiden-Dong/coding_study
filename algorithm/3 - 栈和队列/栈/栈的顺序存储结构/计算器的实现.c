#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MaxSize 20

typedef struct _Stack 
{
	char * top; // 栈首指针
	char * end; // 栈尾指针
}Stack , *pStack;

// ====================顺序栈的功能封装=====================================
void InitStack (pStack *p);          // 初始化指针        
void PushStack (pStack , char ch); // 压栈 
void PopStack (pStack p , char *ch);//出栈
int LenStack (pStack p );           // 栈的长度
void TraStack (pStack p);           // 遍历栈区
void DestroyStack (pStack p);       // 释放栈区

int main ()
{
	pStack one = (pStack) malloc (sizeof(Stack));
	InitStack (one);


	DestroyStack (one);
	return 0;
}


void InitStack (pStack *p )
{
	(*p)->top = (char *)malloc(sizeof(char)*MaxSize);
	(*p)->end = (*p)->top;
}



void PushStack (pStack p , char ch)
{
	*(p->end) = ch;
	p->end++;
}

void PopStack (pStack p , char *ch)
{
	p->end--;
	(*ch)=*(p->end);
}



int LenStack (pStack p )
{
	int i=0 ;
	char * pl=p->top;
	while (pl!=p->end)
	{
		pl++;
		i++;
	}

	return i;
}

void TraStack (pStack p)
{
	char * str;
	str = p->top;

	while (str != p->end)
	{
		printf ("%c -> " , *str);
		str++;
	}
	printf ("End\n");
}

void DestroyStack (pStack p)
{
	free (p->top);
}