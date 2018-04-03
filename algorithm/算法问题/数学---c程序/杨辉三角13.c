//杨辉三角13
#include<stdio.h>
#define N 8
int main()
{
int i,j,d[N];
d[1]=1;//预置第一行
printf("杨辉三角\n");
printf("1\n");
for(i=2;i<N;i++)
{
d[i]=1;//第i行的最后一个数
for(j=i-1;j>1;j--)
d[j]=d[j]+d[j-1];
for(j=1;j<i+1;j++)
printf("%-5d",d[j]);
printf("\n");
}
return 0;
}
