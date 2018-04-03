#ifndef MGRAPH_H_
#define MGRAPH_H_

/*
******************************************************
 * 无向图的邻接矩阵问题
 * 
 *  建立一个 N*N 的矩阵而且每一行每一列对应一个顶点
 *  如果顶点之间存在有边则用 1 表示 
 *  如果顶点之间未存在有边用 0 表示 
******************************************************
*/

#define MAX_SIZE 20    //  最大顶点数

typedef struct _MGraph       
{
	char Vexs[MAX_SIZE] ;    // 顶点信息
	int arcs[MAX_SIZE][MAX_SIZE] ;          // 邻接矩阵
	int Vexnum ;			 // 图的顶点数
	int arcnum ;			 // 图的边数
}MGraph , *pMGraph;
// 使用邻接矩阵来表示顶点之间的联通关系

void InitMgraph (int Vex , int Arc , pMGraph Graph);
// 初始化邻接矩阵信息 Vex 代表的是顶点数量 
//                    Arc 代表的是边的数量

void PrintMgraph (pMGraph Graph);
// 打印出 邻接矩阵信息 

void SeleMgraph (pMGraph Graph ,char a , char b , int * line , int * high);
// 选出位置 如果是 -1 则说明 查找失败 

/***********************  克鲁斯卡尔算法 ******************/

typedef struct _Edge
{
	int begin , end ; // 存放边的两个顶点
	int weight ;	  // 存放边的权值
} Edge , *pEdge;
// 存放所有边得信息

void InitEdge (pMGraph G , pEdge edgets);
// 初始化边集合结构

void MinisapnTree_kruskal ( pMGraph G );
// 生成最小生成树
int Find (int *parent , int f);

#endif