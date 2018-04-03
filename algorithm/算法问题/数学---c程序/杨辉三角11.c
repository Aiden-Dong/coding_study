//杨辉三角11
#include<stdio.h>
# define N 8
int main()
{
	int i, j;
	int a[N][N];
	for (i = 1; i < N; i++)//比你输入的行数少一行(忽略了a[0][])
	{
		a[i][1] = a[i][i] = 1;
		for (j = 2; j < i; j++)//第一列与最后一列都已确定好
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];//中间元素是上一行对应位置及左边位置之和
	}
	printf("杨辉三角\n");
	for (i = 1; i < N; i++)//打印输出
	{
		for (j = 1; j < i + 1; j++)
			printf("%-5d", a[i][j]);
		printf("\n\n");
	}

	return 0;
}