#include "algraph.h"
#include <stdlib.h>
#include <stdio.h>

/* 
** ************************************************************************************
 *	 数组作用 ：
 *				etv :  每个顶点的最早发生时间  （方法 : 所有路径完成的最大时间）
 *				ltv :  每个顶点的最晚发生时间  （方法 : 所有从此该顶点开始的多需开始时间的最小值）
 *
 *   关键路径的求解过程 ：
 *				首先利用拓扑排序求解 etv 数组 : 求解过程是利用拓扑排序时候， 每次出栈的顶点都访问自己的邻接点的开始时间
 *                                             （自己的开始+邻接点权值）最后取最大值 ， 这样所有没有入度的顶点都已求的最早开始时间
 *												然后将没有入度的顶点依次入栈stack1 为下次求得最晚开始时间做准备！！！
 *
 *				求解 ltv 数组然后利用 etv 数组跟 ltv 数组 ， 求解关键路径 ：
 *												当顶点的最早发生时间等于顶点的最晚开始时间的时候 此顶点即为关键路径所经过的关键
** ************************************************************************************
*/

int *etv ;  // 事件最早发生的时间
int *ltv ;	// 活动最晚发生的时间

Stack stack = {0 , NULL};  // 存放用于拓扑排序的队列区
Stack stack1 = {0 , NULL}; // 存放用于关键路径的栈区

// 对顶点数组进行拓扑排序
void TopologicalSort (pVNode one , int v)
{
	int i ;								// 用于遍历顶点
	Stack stack ={0 , NULL} ;			// 用于存放顶点为 0 的栈区
	pArcNode p;
	int Market[MAX_SIZE]  = {0};        // 声明一个标记数组 将所有访问过的顶点都置为1
	int k , m;							// 入度为 0 的顶点下标
	int sum = 0;

	etv = (int *)malloc(sizeof(int)*v);

	// 将数组 etv 初始化为 0 
	for (i = 0 ; i < v ;i++)
		etv[i] = 0 ;

	// 遍历顶点数组 将入度为 0 的顶点 执行进栈操作
	for (i = 0 ; i < v ; i++)
	{
		if (one[i].num == 0)  
		{
			StackAlGraph (&stack , i);
			Market[i] = 1;
		}
	}	
	
	// 遍历栈区 依次对入度为 0 的顶点进行入栈操作
	while (stack.num != 0)
	{

		k = PopAlGraph (&stack);
		PushStack (&stack1 , k);
		//printf ("%c -> ",one[k].data);
		sum++;
		EarseAlGraph (one , k);
		for (p = one[k].first ; p!= NULL ; p=p->nextarc)
		{
			m = p->adjvex ;
			if (etv[m] < etv[k]+p->weight)
				etv[m] = etv[k]+p->weight;
		}
		for (i = 0 ; i < v ; i++)
		{
			if (one[i].num == 0 && Market[i]==0)
			{
				StackAlGraph (&stack , i);
				Market[i] = 1;
			}
		}
	}

	if (sum != v)
	{
		puts("有向图中存在有环 : ");
		for (i = 0 ; i< v; i++)
		{
			if(Market[i] == 0)
				printf(" %c ",one[i].data);
		}
		printf ("\n");
	}

}

// 求解关键路径
void CriticalPath (pVNode one , const int v)
{
	int i , k , m , j ;
	int ete , lte ;
	pStack next = &stack1;
	pArcNode p;

	// 首先进行 拓扑排序 求出 etv 跟 stack2 的值
	TopologicalSort (one , v);

	ltv = (int *) malloc (sizeof(int) * v);

	// 初始化 ltv 都为汇点的时间
	for ( i = 0 ; i < v ; i++)
		ltv[i] = etv[v-1];

	// 从汇点开始逐个计算 ltv 
	
	while(stack1.num != 0)
	{

		k = PopAlGraph (&stack1); 

		for (p = one[k].first ; p != NULL ; p=p->nextarc)
		{
			m = p->adjvex ;
			if (ltv[k] > ltv[m] - p->weight)
				ltv[k] = ltv[m] - p->weight;
		}

	}

	for ( i = 0 ; i < v ; i++)
	{
		for (p = one[i].first ; p != NULL ; p = p->nextarc)
		{
			k = p->adjvex ;
			ete=etv[i];
			lte = ltv[k]-p->weight;	
			// 结点时问题 为了找到最早从结点出发的 顶点
			if (ete == lte)           // ltv[i] == etv[i] 
			printf (" <v%c , v%c> length : %d ",one[i].data  , one[k].data ,p->weight);
			// 打印出所有的关键路径 
			// 可能存在多条 则同时打印
		}	
	}

	printf ("\n");

}

// 将入度为0  的顶点入栈
void StackAlGraph (pStack stack , const int k)
{
	pStack  val = stack;		// 插入工具
	pStack  New ;			    // 加入新元素
	int i ;						// 遍历栈区

	val = stack;
	// 将val指针移到栈区最后
	while (val->next != NULL)
		val = val->next ; 
	
	// 为新元素分配空间
	New = (pStack)malloc(sizeof(Stack)); 
	New->num = k ;					// 保存要访问的顶点元素下标
	New->next = NULL;

	val->next  = New ;				/******* 此处又有心得 *********/
	stack->num++;

						// 栈区元素加一
}

// 将第一个顶点位置出栈
int PopAlGraph (pStack stack)
{
	int a ;
	pStack front , next ;
	pStack val ;

	if (stack->num == 0)
	{
		puts("栈中已经没有顶点元素 .....");
		return -1;
	}

	front = stack ;
	next = front->next;
	a = next->num;
	front->next = next->next;
	free(next);

	stack->num--;

	return a ;
}

// 删除指定顶点的一条入度
void EarseAlGraph (pVNode one , const int k)
{
	pArcNode node ;

	node = one[k].first;

	while (node != NULL)
	{
		one[node->adjvex].num--;
		node = node->nextarc;
	}


}

// 栈区模型
void PushStack (pStack stack , const int k)
{
	pStack sl = (pStack)malloc(sizeof(Stack));

	sl->num = k;
	sl->next = stack->next;
	stack->next = sl ;
	stack->num++;
}

