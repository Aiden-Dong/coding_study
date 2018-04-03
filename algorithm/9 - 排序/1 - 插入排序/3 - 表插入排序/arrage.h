#ifndef ARRAGE_H_
#define ARRAGE_H_

#define SIZE 20
#define MAX_SIZE 2000

// 表结构
typedef struct _SLNode
{
	int rc ;   // 记录项
	int next ; // 指针项
}SLNode , *pSLNode ;

// 静态链表的类型
typedef struct _SLinkType
{
	SLNode r[SIZE]; // 0 号结点为表头结点
	int length ;	// 表的当前长度
}SLinkType , *pSLinkType;

// 将数组 D 建立的 n 个元素的表插入到排序的静态链表 SL 
void TableInsert (pSLinkType SL , int * d , int n);

// 对静态链表进行有序排列 
void Arrange (pSLinkType SL);
void swap (int *a , int *b );

#endif