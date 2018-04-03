#include <stdio.h>
#include <stdlib.h>
#include "mgraph.h"

int main ()
{
	MGraph one ;
	Patharc arc ;            // 最短路径下标的数组
	ShortPathTable Table ;   // 存取到各个顶点的最短路径的权值大小

	int a , b ;

	puts ("请输入邻接矩阵的顶点数跟边数 :");
	scanf ("%d%d",&a,&b);

	InitMgraph (a , b , &one); // 构造邻接矩阵
	PrintMgraph (&one);        // 打印邻接矩阵
	system ("cls");

	ShorttestPath_Floyd (&one , arc , Table);

	puts ("p 数组 :");

	for (a = 0 ; a < one.Vexnum ;a++)
	{
		for (b = 0 ; b < one.Vexnum ; b++)
			printf (" %d ",arc[a][b]);
		printf ("\n");
	}
	puts("D 数组 :");

	for (a = 0 ; a < one.Vexnum ;a++)
	{
		for (b = 0 ; b < one.Vexnum ; b++)
			printf (" %d ",Table[a][b]);
		printf ("\n");
	}

	return 0;
}