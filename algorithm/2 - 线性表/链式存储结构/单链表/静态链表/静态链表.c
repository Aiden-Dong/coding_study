#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MaxSize 20
typedef struct _SlinkList
{
	int data; // 存放数据
	int cur ; // 存放游标
}SlinkList , *pSlinkList ;

void InitList (pSlinkList pl);                   // 初始化静态链表
int MallocSL (pSlinkList pl);                    // 从备用链表中获取结点
void FreeSL (pSlinkList pl , int i );            // 将指定的结点回收到备用链表
void AddData (pSlinkList pl , int data ,int e);  // 将数据添加到指定位置
void TravelSL (pSlinkList pl);                   // 遍历静态链表区
void Adddata (pSlinkList pl , int data);         // 将数据初始化

int main ()
{
	int i;
	int a;
	SlinkList one[MaxSize];

	InitList (one); // 初始化静态链表

	srand ((unsigned int)time(NULL));
	for (i = 0 ; i < 15 ; i++)
	{
		a = rand()%50;
		Adddata (one,a);
	}

	TravelSL (one);

	AddData (one , 12 , 3);
	AddData (one , 11 , 1);


	TravelSL (one);

	return 0;
}

void InitList (pSlinkList pl)
{
	int i ;
	for (i = 0 ; i < MaxSize-1 ; i++)
		pl[i].cur = i+1;
	pl[i].cur = 0 ; // 最后一个游标存放第一个有数据的位置
					// 如果是 0 则说明没有任何数据

}

int MallocSL (pSlinkList pl)
{
	int i = pl[0].cur;   // 返回备用链表首结点的位置

	if (i == MaxSize-1)
		return 0;
	pl[0].cur=pl[i].cur;  // 重置备用链表首结点
	return i;

}

void AddData (pSlinkList pl , int data ,int e)
{
	int i ;
	int x = MaxSize-1 , y;
	int a ;

	if (!(a = MallocSL(pl))) // 为新的结点分配内存
	{
		puts ("error to malloc");
		return ;
	}
	pl[a].data = data;

	for (i = 0 ; i < e; i++)
	{
		y = x;        // 指向前一个
		x = pl[x].cur ;// 指向下一个
		if (y == 0)
		{
			puts ("error to insert");
			return ;
		}
	}

	pl[y].cur = a ;
	pl[a].cur = x ;    // 链接工作
	
}

void Adddata (pSlinkList pl , int data)
{
	int x = MaxSize-1;
	int a = MallocSL (pl);

	pl[a].cur = 0;
	pl[a].data = data;
	if (pl[MaxSize-1].cur==0)
		pl[MaxSize-1].cur = a;
	
	else
	{
		while (pl[x].cur != 0)
			x = pl[x].cur;
		pl[x].cur = a;
	}

}

void TravelSL (pSlinkList pl)
{
	int x = MaxSize-1;

	while (pl[x].cur != 0)
	{
		x = pl[x].cur;
		printf (" %d ->",pl[x].data);
	}

	printf (" End\n");
}