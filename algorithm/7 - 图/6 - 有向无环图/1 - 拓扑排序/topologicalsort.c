#include "algraph.h"
#include <stdlib.h>
#include <stdio.h>

// 对顶点数组进行拓扑排序
void TopologicalSort (pVNode one , int v)
{
	int i ;								// 用于遍历顶点
	Stack stack ={0 , NULL} ;			// 用于存放顶点为 0 的栈区
	pStack p;
	int Market[MAX_SIZE]  = {0};        // 声明一个标记数组 将所有访问过的顶点都置为1
	int k ;								// 入度为 0 的顶点下标
	int sum = 0;

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
		printf ("%c -> ",one[k].data);
		sum++;
		EarseAlGraph (one , k);
		for (i = 0 ; i < v ; i++)
		{
			if (one[i].num == 0 && Market[i]==0)
			{
				StackAlGraph (&stack , i);
				Market[i] = 1;
			}
		}
	}

	printf ("End\n");

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