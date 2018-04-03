#include <stdio.h>

void initTriplet (int**T , int v1 , int v2 , int v3);  // 初始化3元数组
void DestroyTriplet (int ** T);      // 释放掉数组
void Get (int *T,int i , int * e);   // 得到某下标处的值
void Put (int **T, int i, int e);    // 将某下标的值修改
void IsAscending (int *T);           // 三元组按照升序排列
void IsDescending (int *T);          // 三元组按照降序排列
void Max (int * T, int * e);         // 返回三元组中的最大值
void Min (int * T, int * e);		 // 返回三元组中的最小值

int main ()
{
	int * arry , a ,b ,c;
	int i;
	int e;

	puts ("请输入初始化的数值:");
	scanf ("%d%d%d",&a,&b,&c);
	fflush (stdin);
	initTriplet (&arry , a , b , c);
	puts ("请输入要查看的下标:");
	scanf ("%d",&i);
	fflush (stdin);
	Get (arry , i , &e);
	printf ("第 %d 处的值为 %d\n",i,e);
	puts ("请输入要修改的下标及值:");
	scanf ("%d%d",&i,&e);
	fflush (stdin);
	Put (&arry , i , e);
	for (i = 0 ; i < 3 ; i++)
		printf (" %d ",arry[i]);
	printf ("\n");

	IsAscending(arry);
	for (i = 0 ; i < 3 ; i++)
		printf (" %d ",arry[i]);
	printf ("\n");

	IsDescending(arry);
	for (i = 0 ; i < 3 ; i++)
		printf (" %d ",arry[i]);
	printf ("\n");

	DestroyTriplet (&arry);

	return 0;
}

void initTriplet (int**T , int v1 , int v2 , int v3)
{
	(*T) = (int *) malloc (sizeof(int) * 3);
	(*T)[0] = v1;
	(*T)[1] = v2;
	(*T)[2] = v3;
}
void DestroyTriplet (int ** T)
{
	free(*T);
}

void Get (int *T,int i , int * e)
{
	if ( i<1 || i>3 )
	{
		puts ("检索错误!!!");
		return ;
	}
	else
		(*e) = T[i-1];
}

void Put (int **T, int i, int e)
{
	if ( i<1 || i>3 )
	{
		puts ("检索错误!!!");
		return ;
	}
	else
		(*T)[i-1] = e;
}

void IsAscending (int *T)
{
	int i , j , t ;
	for (i = 0 ; i < 2 ; i++)
		for (j = 0 ; j < 3-i-1;j++)
			if (T[j] > T[j+1])
			{
				t = T[j];
				T[j] = T[j+1];
				T[j+1] = t;
			}
}

void IsDescending (int *T)
{
	int i , j , t ;
	for (i = 0 ; i < 2 ; i++)
		for (j = 0 ; j < 3-i-1;j++)
			if (T[j] < T[j+1])
			{
				t = T[j];
				T[j] = T[j+1];
				T[j+1] = t;
			}
}
void Max (int * T, int * e)
{
	int i ;
	(*e) = T[0];
	for (i = 1 ; i < 3 ; i++)
	{
		if ((*e) < T[i])
			(*e) = T[i];
	}
}

void Min (int * T, int * e)
{
	int i ;
	(*e) = T[0];
	for (i = 1 ; i < 3 ; i++)
	{
		if ((*e) > T[i])
			(*e) = T[i];
	}
}
