#include <stdio.h>


/************ 函数声明 *************************/

// 对顺序表中的子序列 a[low，high] 做快速排序 
void QSort (int k[] , int low , int high);

void QuickSort (int k[] , int n);

// 核心算法
int Partition (int k[] , int low , int high );

// 用于交换两个元素的值
void swap (int k[] , int low , int high );



/************** 函数实现 *********************/

void QuickSort (int k[] , int n)
{
	QSort (k , 0 , n-1);
}


void QSort (int k[] , int low , int high)
{
	int point ; // 基准点

	if (low < high && low >=0) 
	{
		point = Partition (k , low , high);       // 计算基准点 
		QSort (k , low , point-1);  // 对左边进行递归调用
		QSort (k , point-1 , high); // 对右边进行递归调用
	}

}
int Partition (int k[] , int low , int high )
{

	int point ;
	point = k[low] ;    // 中枢轴记录关键字

	while (low < high)  // 从表的两端交替向中间扫描
	{
		// 比中枢轴记录小的记录移到低端
		while (low < high && k[high] >= point ) // 中枢轴位于 low 的标记处 不可以用大于
			high --;
		swap (k , low , high);


		// 比中枢轴记录大的记录移到高端
		while (low < high && k[low] <= point)  // 中枢轴位于 high 的标记处
			low++;
		swap (k , low , high);
	}

	return low ;
}

void swap (int k[] , int low , int high )
{
     int n ;
	 n = k[low];
	 k[low] = k[high];
	 k[high] = n;
}