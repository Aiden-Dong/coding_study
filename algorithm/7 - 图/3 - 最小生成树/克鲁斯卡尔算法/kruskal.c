#include "mgraph.h"
#include <stdio.h>

/*
** ************************************************************************************************************************
 * 克鲁斯卡尔算法 核心思想 ：
 *			相对于普里姆算法 ，克鲁斯卡尔算法是建立在边的基础上实现的 ，以边为单位将所用顶点分成若干个分支， 当只有一个分支的时候则
 *			说明树已经建好 ；
 *				
 *			克鲁斯卡尔算法的核心思想有两个方面来使其得以实现 ：
 *
 *			方面一 ： 将所有的边进行递增排序 ，然后从小到大挑选边
 *          方面二 ： 避免在挑选边的时候出现了环结构
 *
 *			为了解决环路问题 ， 定义了一个parent数组来判断图中是否有环的出现 , 没每次都从parents 数组中遍历 ，如果是离散顶点
 *								返回顶点的下标 如果是位于分支中的顶点 返回分支的首部下标 并将分支的首部处添加新的首部下标
 *								如果边的两端点在 parents 遍历出结果相同说明 位于同一分支不可取边
 *
** ************************************************************************************************************************
*/

Edge edges[MAX_SIZE];
// 定义边的集合数组


// 以边为重点的遍历方式  查看边是否合适作为树的链接点
// 重点是如何避免出现环的情况  
// 解决办法是将所有的子树的收尾处都串成一个串 *****同一棵树一个终点*****  重点相同不可链接边 否则出现 环的情况
void MinisapnTree_kruskal (pMGraph G)  
{
	int i , n , m;
	int k ;
	int parent[MAX_SIZE]; // 定义parent数组用来判断边与边是否形成环路

	InitEdge (G , edges) ; // 初始化边集合数组

	for (i = 0 ; i < G->Vexnum ; i++)  // 初始化边为0 ;
		parent[i] = -1;

	for (i = 0 ; i < G->arcnum ; i++)
	{
		n = Find (parent, edges[i].begin);   // 尾结点分量的分量子树的终点  // 并将终点延长
		m = Find (parent, edges[i].end);	 // 头结点分量的分量子树的终点  // 并将终点延长	

		if (n != m)  // 如果 n = m 则构成环路 不满足条件
		{
			parent[n] = m;  // n -> m ;
			printf ("(%d , %d) %d \n" , edges[i].begin , edges[i].end , edges[i].weight);

		}

	}  // 最终所有的终点结点都集中与一点 则 结束
}

// 将所有的顶点都最终集中到一点上 这样标志这
int Find (int *parent , int f)
{
	while (parent[f] != -1) // 说明已经到达分支的顶部
		f = parent[f];
	return f;
}

void InitEdge (pMGraph G , pEdge edgets)
{
	int i , j , a;
	int k = 0;
	Edge one ;

	// 初始化 edges结构
	for (j = 0 ; j < G->Vexnum ; j++)
		for (i = j+1 ; i < G->Vexnum ; i++)
		{
			if (G->arcs[j][i] > 0 && G->arcs[j][i] != 0x7fffffff)
			{
				edgets[k].begin = j ;
				edgets[k].end = i ;
				edgets[k].weight = G->arcs[j][i];
				k++;
			}
		}
	// 对edges结构按照 权值 递增 的顺序进行排序
	for ( j = 0 ; j < G->arcnum-1 ; j++)
		for (i = 0 ; i < G->arcnum - j-1 ; i++)
			if (edgets[i].weight > edgets[i+1].weight)
			{
				one = edgets[i];
				edgets[i] = edgets[i+1];
				edgets[i+1] = one;
			}
	
}



