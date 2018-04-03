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

typedef enum { FALSE , TRUE }GraphKind; 
// 用于标记邻接矩阵中是否有联通关系
// FALSE 说明唯有联通
// TRUE 说明存在联通关系

typedef struct _ArCell
{
	GraphKind adj ;  // 存放联通信息
}ArCell , AdjArcll[MAX_SIZE][MAX_SIZE];
// 建立矩阵信息

typedef struct _MGraph       
{
	char Vexs[MAX_SIZE] ;    // 顶点信息
	AdjArcll arcs ;          // 邻接矩阵
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

#endif