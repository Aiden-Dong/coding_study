#include <stdio.h>
#include "mgraph.h"

void InitMgraph (int Vex , int Arc , pMGraph  Graph)
{
	int i , j;   // 遍历邻接矩阵
	char a , b ; // 存放顶点
	int x , y ;

	if (Vex > 20 || Arc > ((Vex*Vex-Vex)/2))
	{
		puts ("边或者顶点数量错误 !!!");
		return ;
	}

	Graph->arcnum = Arc ; // 存放边的数量
	Graph->Vexnum = Vex ; // 存放顶点数量

	puts ("请输入顶点信息 :");
	fflush (stdin);
	for (i = 0 ; i < Graph->Vexnum ; i++)
	{
		scanf ("%c",&Graph->Vexs[i]);
		for (j=0 ; j < Graph->Vexnum ; j++)
			Graph->arcs[i][j].adj = FALSE;
	}

	fflush (stdin);
	puts("请输入存在联通的位置 :");

	for ( i = 0 ; i < Graph->arcnum ; i++)
	{
		scanf("%c%c",&a , &b);

		SeleMgraph (Graph , a , b , &x , &y);
		if (x == -1 || y == -1)
		{
			puts("输入错误 !!");
			return ;
		}
		Graph->arcs[y][x].adj = TRUE;
		Graph->arcs[x][y].adj = TRUE;
		fflush (stdin);
	}
}

void SeleMgraph (pMGraph Graph ,char a , char b , int * line , int * high)
{
	int i ;
	int x = -1 , y = -1;
	for (i = 0 ; i < Graph->Vexnum ; i++)
	{
		if (a == Graph->Vexs[i] && x==-1)
			x = i ;
		if (b == Graph->Vexs[i] && y==-1)
			y = i ;
	}

	if (x == y || x == -1 || y == -1 || Graph->arcs[y][x].adj==TRUE)
		(*line) =(*high) = -1 ;
	else
	{
		(*line) = x ;
		(*high) = y ;
	}
}


void PrintMgraph (pMGraph Graph)
{
	FILE * fout = fopen("邻接矩阵.txt","w");
	int i , j ;

	fprintf (fout , "   ");
	for (i = 0 ; i < Graph->Vexnum ; i++)
		fprintf (fout , " %c ",Graph->Vexs[i]);
	fprintf (fout , "\n");

	for (j = 0 ; j < Graph->Vexnum ; j++)
	{
		fprintf (fout , " %c ",Graph->Vexs[j]);
		for (i = 0 ; i < Graph->Vexnum ; i++)
		{
			fprintf (fout , " %d ",Graph->arcs[j][i].adj);
		}
		fprintf (fout , "\n");
	}
}