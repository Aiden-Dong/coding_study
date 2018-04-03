#include "sstable.h"
#include <stdio.h>
#include <string.h>

void Create (int * table , int n)
{
	int i = 0 ;

	for (i = 0 ; i < n ; i++)
	{
		table[i].Market = i;
		puts ("请输入记录名 :");
		scanf("%d",&table[i]);
	}

}

int Traverse (int * table,int n , int one )
{
	int low , mid , high; // 低位 中位 高位
	low = 0 , high = n-1;

	while (low <= high)
	{
		mid = (low+high)/2;
		if(table[mid] == n)
			return mid ;
		else if (table[mid] > n)
			high = mid-1;
		else
			low = mid+1;
	}
	return low ;

}