#ifndef ALGRAPH_H_
#define ALGRAPH_H_

#define MAX_SIZE 20 // 定义结点数量上限

// 弧信息
typedef struct _AtcNode
{
	int adjvex ;               // 存放指向的顶点位置
	struct _ArcNode *nextarc ; // 存放下一条弧指针
}ArcNode , *pArcNode ;

// 顶点信息
typedef struct _VNode
{
	char data ;      // 顶点信息 
	pArcNode first ; // 指向第一条弧信息
	int num ;        // 记录此顶点的入度
} VNode , *pVNode ; 

// 队列栈
typedef struct _Stack
{
	int num ;// 记录栈中的顶点数量
	struct _Stack * next;
}Stack , *pStack ;

void InitAlGraph (pVNode * one , int v) ; 
// 初始化邻接表结构

int SeleAlGraph (pVNode one , int v ,const char ch);
// 从顶点数组中找到指定顶点的位置

// ================ 拓扑排序 ==========================/

void TopologicalSort (pVNode one , int v);
// 对顶点数组进行拓扑排序

void StackAlGraph (pStack stack , const int k);
// 将入度为0  的顶点入栈

int PopAlGraph (pStack stack);
// 将第一个顶点位置出栈

void EarseAlGraph (pVNode one , const int k);
// 删除指定顶点的一条入度

#endif  