#include <stdio.h>

// 直接插入排序法
void InsertSort (int *num , int n);

int main ()
{
	return  0;
}

void InsertSort (int *num , int n)
{
	int i ; j ;

	// 将第 0 位看作是一个缓冲位用于存储带插入数据
	// 将每次遍历时候的比前面小的值放到缓冲区中
	// j 标记位之前的序列为已经排序完成的序列
	for (j = 2 ; j < n ; j++) 
	{
		if (num[j] < num[j-1])
		{
			num[0] = num[j];
			num[j] = num[j-1];
		}

		// 将凡是比 num[0] 大的数据后移
		for (i = j-2 ; num[i] > num[0] ; i--) 
			num[i+1] = num[i];
		num[i] = num[0] ; // 将带插入数据移动到合适位置
	}
}