#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 用链表实现排序以及归并问题

typedef struct _Node // 接受链表的指针
{
	int data;
	struct _Node *next ;
}Node , *pNode;

void addStack (pNode *pl,int a);  // 添加新元素
void TraStack (pNode pl);         // 遍历栈区
void MerginStack (pNode p1 , pNode p2 , pNode *p3); // 合并栈

int main ()
{
	
	int i , a ;
	pNode one = NULL;
	pNode two = NULL;
	pNode zero;

	srand ((unsigned int)time(NULL));
	for (i = 0 ; i < 10 ; i++)
	{
		a = rand() %60;
		addStack(&one , a);
	}

	for (i = 0 ; i < 10 ; i++)
	{
		a = rand() %60;
		addStack(&two , a);
	}

	TraStack (one);
	TraStack (two);

	zero = (pNode)malloc(sizeof(Node));
	zero->data = 0;
	zero->next = NULL;
	MerginStack (one,two,zero);
	TraStack (zero);

	return 0;
}

void addStack (pNode *pl,int a)
{
	pNode previous=NULL ;	// 用于指向插入点的上一个结点
	pNode next ;		// 用于指向插入点的下一个结点
	pNode New ;			// 用于指向插入点的新结点

	next = (*pl);       // 将next 指向要插入链表的首位置

	while (next != NULL && a > next->data)
	{
		previous=next;
		next = next->next;
	}

	New = (pNode) malloc (sizeof(Node));
	New->data = a;
	New->next = next;

	if (previous == NULL)
		(*pl) = New;
	else
		previous->next = New;

}

void TraStack (pNode pl)
{
	while (pl != NULL)
	{
		printf ("%d -> ",pl->data);
		pl = pl->next;
	}

	printf ("End\n");
}
void MerginStack (pNode p1 , pNode p2 , pNode p3)  
// 注意指针本质之间的灵活调用 解决此类问题要站在内存本质的角度上去思考指针问题
{
	pNode one = p3 ;

	while (p1 != NULL && p2 != NULL)
	{
		if (p1->data < p2->data)
		{
			one->next = p1 ;
			p1 = p1->next;
			p3->data++;
			one = one->next;
		}
		else
		{
			one->next = p2;
			p2 = p2->next;
			p3->data++;
			one = one->next;
		}
	}

	while (p1!=NULL)
	{
		one->next = p1 ;
		p1 = p1->next;
		p3->data++;
		one = one->next;
	}
	while (p2!=NULL)
	{
		one->next = p2;
		p2 = p2->next;
		p3->data++;
		one = one->next;
	}

	one=NULL;
}