//计算正整数n的所有约数及约数个数
#include<stdio.h>
int main()
{
int n,i,j=0;
printf("Enter a number:");
scanf("%d",&n);
for(i=1;i<n+1;i++)
{
if(n%i==0)
{
printf("%d\n",i);
j++;
}
}
printf("约数个数为%d",j);
return 0;
}