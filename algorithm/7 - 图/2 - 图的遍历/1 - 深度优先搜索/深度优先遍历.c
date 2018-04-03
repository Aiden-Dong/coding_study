#include <stdio.h>
#include <stdlib.h>
#include "mgraph.h"

int main ()
{
	MGraph one ;
	int a , b ;

	puts ("请输入邻接矩阵的顶点数跟边数 :");
	scanf ("%d%d",&a,&b);

	InitMgraph (a , b , &one); // 构造邻接矩阵
	PrintMgraph (&one);        // 打印邻接矩阵

	system ("cls");
	DFSTravel (&one);			// 深度优先遍历
	
	return 0;
}