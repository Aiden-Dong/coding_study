#include "arrage.h"
#include <stdio.h>

// 表的插入排序

// 建立表结构 在静态循环链表中插入值
void TableInsert (pSLinkType SL , int *d , int n)
{
	int i , p , q ;

	// 初始化表头结构
	SL->r[0].rc = MAX_SIZE;
	SL->r[0].next = 0;

	for (i = 0 ; i < n ; i++)
	{
		SL->r[i+1].rc = d[i]; // 将数组中的值依次赋给表结构

		// 静态链表后移
		q = 0;
		p = SL->r[0].next ;
		while (SL->r[p].rc <= SL->r[i+1].rc ) 
		{
			q = p ;
			p = SL->r[p].next;
		}

		// q 指向以排好的链表中的比要插入值小的值中的最大值
		// p 指向已排好的链表中的比要插入值大的值中的最小值
		SL->r[i+1].next = p ;
		SL->r[q].next = i+1;
	}	
	SL->length = n;
}
	
// 对表进行排序
void Arrange (pSLinkType SL)
{
	
	int q;
	int i ;
	int p = SL->r[0].next;  // p 初始化为指向第一个最小的值

	for (i = 1 ; i < SL->length ; i++)
	{
		
		while (p < i)    // 找到第 i 个记录 ， 并用p 指示起当前的位置
			p = SL->r[p].next;
		q = SL->r[p].next; // q 指向有序数列中的下一个值
		if (p !=i)
		{
			// 将第 p 个值与第 i 个交换 
			SLNode one = SL->r[p];
			SL->r[p] = SL->r[i];
			SL->r[i]=one;

			SL->r[i].next = p; // 并且使得第i 个值的下一个指向 现在的 p 
		}

		p = q ;
	}
}

void swap (int *a , int *b )
{
	int t = *a;
	*a = *b;
	*b = t; 
}