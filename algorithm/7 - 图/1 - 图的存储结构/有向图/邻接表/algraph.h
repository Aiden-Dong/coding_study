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
	char data ;  // 顶点信息 
	pArcNode first ; // 指向第一条弧信息
} VNode , *pVNode ; 

void InitAlGraph (pVNode * one , int v) ; // 初始化邻接表结构
int SeleAlGraph (pVNode one , int v ,const char ch);

#endif  