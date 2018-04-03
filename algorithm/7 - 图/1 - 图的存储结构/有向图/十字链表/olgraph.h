#ifndef OLGRAPH_H_
#define OLGRAPH_H_

/*
 *********************************************************
 * 十字链表的建造模型 ：
 *
 *	 1. 弧结点： 尾结点 | 头结点 | 同一尾结点的下一条弧 | 同一头结点的下一条弧 | 弧信息
 *
 *   2. 顶点结点 ： 顶点信息 | 第一条入弧 | 第一条出弧
 *
 **********************************************************
*/
// 弧结点信息
typedef struct _ArcBox 
{
	int tailVex , headVex;					// 该弧的尾和头顶点的位置
	struct _ArcBox *hlink , *tlink ;        // 分别为弧头相同或者弧尾相同的链域
}ArcBox , *pArcBox ;

// 顶点信息
typedef struct _VexNode
{
	char data ;                     // 顶点标志
	pArcBox firstin , firstout ;	// 指向第一条入弧跟第一条出弧
} VexNode , *pVexNode ;

typedef struct _OLGraph
{
	pVexNode xlist ; // 顶点向量 
	int vexnum ; // 顶点数
	int arcnum;  //弧数
}OLGraph , *pOLGraph;

// 采用十字链表的存储表示构造有向图 G 
void CreateDG (pOLGraph G);

// 查找指定的顶点所在位置
int SeleDG(pOLGraph G , const char ch);

// 打印有向图G
void PrintDG(pOLGraph G);

#endif