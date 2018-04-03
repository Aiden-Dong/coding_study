#include "algraph.h"
#include <stdlib.h>
#include <stdio.h>

void InitAlGraph (pVNode * one , int v)
{
	int i , j ;
	int x ,y ;
	int num ;
	char a , b; // 存放顶点值
	pArcNode p ; //弧结点

	(*one) = (pVNode)malloc(sizeof(VNode) * v); // 初始化顶点元素
	
	puts ("请输入顶点信息 : ");
	for ( i = 0 ;i < v ; i++)
	{
		scanf("%c",&(*one)[i].data) ;
		(*one)[i].first = NULL;
	}
	fflush (stdin);
	puts ("请输入边的总数量 :");
	scanf ("%d", &num);

	for (i = 0 ; i < num ;i++)
	{
		puts("请输入弧信息 :");
		fflush (stdin);
		scanf ("%c%c",&a , &b);
		x = SeleAlGraph(*one , v , a);
		y = SeleAlGraph(*one , v , b);
		printf ("x = %d\n",x);
		printf ("y = %d\n",y);

		p = (pArcNode)malloc(sizeof(ArcNode));
		p->adjvex = y;
		p->nextarc = (*one)[x].first;
		(*one)[x].first=p ;

	}

}

int SeleAlGraph (pVNode one ,int v , const char ch)
{
	int i ;
	for (i =0 ; i < v ; i++)
	{
		if (one[i].data==ch)
			return i;
	}
	return -1;
}