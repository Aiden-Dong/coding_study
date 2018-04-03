#include<stdio.h>
int main()
{
int n,i,j,k;
do
{
printf("请输入一个正整数");
scanf("%d",&n);
}
while(n<0||n==0);
for(i=1;i<n+1;i++)
{
 for(k=n-i;k>0;k--)
 printf("  ");
 for(j=0;j<2*i-1;j++)
 {
 printf(" *");
 }
 printf("\n");
 }
 return 0;
 }
