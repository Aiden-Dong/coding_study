#include "mgraph.h"
#include <stdio.h>

Visited visited;    
// 访问标志数组

// 对图结构 G 进行深度优先遍历
void DFSTravel (pMGraph G)
{
	int i  ;
	
	
	for (i = 0 ; i < MAX_SIZE ; i++)
		visited[i] = FALSE ;        // 初始化为未访问状态

	for (i = 0 ; i < G->Vexnum ; i++)
	{
		if (visited[i])  // 如果处于已访问状态 则查看下一个顶点
			continue;
						 // 如果处于未访问状态
		DFS (G , i);     // 递归遍历 顶点元素
	}

	printf ("End\n");
}

// 递归实现深度优先搜索
void  DFS (pMGraph G , int v)
{
	int i;

	printf ("%c -> ",G->Vexs[v]);
	visited[v] = TRUE;  // 标志已经访问过

	for (i = 0 ; i < G->Vexnum ; i++)
	{
		if(G->arcs[v][i].adj==TRUE && visited[i]==FALSE)
			DFS(G,i);
	}

}