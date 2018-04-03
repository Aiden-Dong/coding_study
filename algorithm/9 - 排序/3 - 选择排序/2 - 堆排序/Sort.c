
#include <stdio.h>

/************* 函数声明 **********************/

// 堆排序
void HeapSort (int K[] , int n );

// 交换数据
void swap (int k[] , int i , int j);

// 大顶堆构造
void HeapAdjust (int k[] , int s , int n); 


/*************** 函数实现 ******************/


// 交换两个空间的值
void swap (int k[] , int i , int j)
{
	int a = k[i];
	k[i] = k[j];
	k[j] = a ;
}

// k 数组看作是一个完全二叉树结构 
// s 为双亲结点
// n 为最大的顶点
void HeapAdjust (int k[] , int s , int n)
{
	int i ;          // 记录子节点
	int temp = k[s]; // 记录双亲节点

	// i 为双亲节点的子节点
	for (i = s*2 ; i <= n ; i=i*2)
	{
		if (i < n && k[i+1] > k[i])
			i++;   // 记录子节点中最大的结点

		// 父结点如果最大 直接退出
		if(temp >= k[i]) 
			break;
		// 否则将大的子节点的值上浮给父结点
		// 子节点成为下一个父结点 进入下次比
		k[s] = k[i];
		s = i;
	}
	// 本质是最大值无限上浮 ， 使得顶点结点下浮
	k[s] = temp;  
}

void HeapSort (int k[] , int n )
{
	int i;
	int a;

	// 从底部开始向上堆排序 然后最大值自然会浮到顶点处
	for (i = n/2 ; i > 0 ; i--)
		HeapAdjust (k , i , n);
	for (i = n ; i > 1 ; i--)
	{
		swap (k , 1 , i);
		HeapAdjust (k , 1 , i-1);
		
	}
}