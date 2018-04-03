#include "algraph.h"
#include <stdlib.h>
#include <stdio.h>

void InitAlGraph (pVNode * one , int v)
{
	int i , j ;
	int weight ; // 存放权值
	int x ,y ;
	int num ;
	char a , b; // 存放顶点值
	pArcNode p ; //弧结点

	(*one) = (pVNode)malloc(sizeof(VNode) * v); // 初始化顶点元素
	fflush (stdin);
	puts ("请输入顶点信息 : ");
	for ( i = 0 ;i < v ; i++)
	{
		scanf("%c",&(*one)[i].data) ;
		(*one)[i].first = NULL;
		(*one)[i].num = 0;
	}
	fflush (stdin);
	puts ("请输入边的总数量 :");
	scanf ("%d", &num);

	for (i = 0 ; i < num ;i++)
	{
		puts("请输入弧信息 :");
		fflush (stdin);
		scanf ("%c%c",&a , &b);
		puts("请输入权值 :");
		scanf ("%d",&weight);
		x = SeleAlGraph(*one , v , a);
		y = SeleAlGraph(*one , v , b);
		// <x , y>
		p = (pArcNode)malloc(sizeof(ArcNode));
		p->adjvex = y;
		p->weight = weight ;
		(*one)[y].num++ ;
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

