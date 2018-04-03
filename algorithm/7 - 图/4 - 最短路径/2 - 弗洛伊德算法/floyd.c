#include "mgraph.h"
#include <stdio.h>

/*
** *******************************************************************************************************
 * 佛洛依德算法 核心思想:
 *
** ********************************************************************************************************
*/
void ShorttestPath_Floyd (pMGraph G , Patharc p , ShortPathTable D )
{
	// D 数组用于存储两顶点之间的 最短路径

	int v , w ;  // 用于遍历 D 数组
	int k ;  
	int i = 0;
	int a , b;
	FILE *fp = fopen ("结果分析.txt","w");

	for (v = 0 ; v < G->Vexnum ; v++)
		for (w = 0 ; w < G->Vexnum ; w++)
		{
			D[v][w] = G->arcs[v][w] ;      // 初始化为相关的边的权值
			p[v][w] = w ;
		}
		
	// 弗洛伊德算法核心
	for (k = 0 ; k < G->Vexnum ; k++)
		for (v = 0 ; v < G->Vexnum ; v++)  
			for (w = 0 ; w < G->Vexnum ; w++)	
			{
				fprintf (fp , "\n\n第 %d 组数据 : v = %d , w = %d , k = %d \n",i++ ,v , w , k);
				fprintf (fp , "D[%d][%d] = %d , D[%d][%d] = %d , D[%d][%d] = %d\n",v , w , D[v][w], v , k , D[v][k] , k , w , D[k][w]);

				fprintf (fp , "\n\n 数据组 : \n");
				for (b = 0 ; b < G->Vexnum ; b++)
				{
					for (a = 0 ; a < G->Vexnum ; a++)
					{
						if (D[b][a] == 0x0fffffff)
							fprintf (fp," %3c ",'#');
						else
							fprintf (fp , " %3d ",D[b][a]);
					}
					fprintf (fp,"\n");
				}

				if (D[v][w] > D[v][k] + D[k][w])
				{
					D[v][w] = D[v][k] + D[k][w];
					p[v][w] = p[v][k];  // 请思考 此处换成 p[k][w] 可以吗  why ??
				}
			}
	}