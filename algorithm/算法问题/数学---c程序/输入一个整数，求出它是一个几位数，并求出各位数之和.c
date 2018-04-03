//输入一个整数，求出它是一个几位数，并求出各位数之和
#include<stdio.h>
#include<math.h>
int main()
{
int k,t,n,a,i,s=0,b;
printf("请输入一个整数");
scanf("%d",&n);
for(k=1;;k++)
{
t=pow(10,k);
if(n/t==0)
break;
}
printf("%d是一个%d位数\n",n,k);
for(i=1;i<k+1;i++)
{
b=n%10;
n=n/10;
s+=b;
}
printf("各位之和为%d\n",s);
return 0;
}
