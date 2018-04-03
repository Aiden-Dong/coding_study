#include "olgraph.h"
#include <stdio.h>
#include <stdlib.h>

void CreateDG (pOLGraph G)
{
	int vex, arc;  // 存放有向图的顶点数跟弧数
	int i , x , y;
	char vexout , vexin ;
	pArcBox arcbox;

	puts("请输入有向图的顶点数跟弧数 :");
	scanf ("%d%d",&vex , &arc );
	if (vex < 0 || arc > (vex)*(vex-1))
	{
		puts ("顶点数量或者弧数量错误 !!!");
		return ;
	}

	// 初始化有向图
	G->vexnum = vex , G->arcnum=arc ;
	G->xlist = (pVexNode)malloc(sizeof(VexNode)*G->vexnum);
	fflush (stdin);
	puts ("请依次输入各定点信息 :");
	for (i = 0 ; i < G->vexnum ; i++)
	{
		G->xlist[i].data = getchar();
		G->xlist[i].firstin = NULL;
		G->xlist[i].firstout = NULL;
	}
	fflush (stdin);
	for (i = 0 ; i < G->arcnum ; i++)
	{
		puts ("请输入入弧跟出弧 :");
		scanf("%c%c",&vexout , &vexin);
		x = SeleDG (G,vexout), y = SeleDG (G,vexin);
		arcbox = (pArcBox)malloc (sizeof(ArcBox));
		arcbox->tailVex = x , arcbox->headVex = y ;
		arcbox->tlink = G->xlist[x].firstout , arcbox->hlink = G->xlist[y].firstin;
		// 构造一个弧结点 x->y ;
		G->xlist[x].firstout = G->xlist[x].firstin = arcbox;
		fflush (stdin);
	}

}

int SeleDG(pOLGraph G , const char ch)
{
	int i ;
	for (i = 0 ; i < G->vexnum ; i++)
		if (ch == G->xlist[i].data)
			return i;
	return -1;
}

void PrintDG(pOLGraph G)
{
	int i ;
	pArcBox arcbox , arcbox2 ; 

	FILE * fp = fopen("有向图.txt","w");

	for (i = 0 ; i < G->vexnum ; i++)
	{
		fprintf (fp , "%c -> ",G->xlist[i].data);
		arcbox = G->xlist[i].firstout;
		while (arcbox != NULL)
		{
			fprintf (fp , "| %d | %d | ->",arcbox->tailVex , arcbox->headVex);// , *(arcbox->hlink).data , *(arcbox->tlink).data);
			arcbox2 = arcbox ;
			arcbox = arcbox->tlink;
			free (arcbox2);
		}

		fprintf (fp , "End\n");
	}
}