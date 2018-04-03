//计算s=求和a(形如a(5)=aaaaaa)
#include<stdio.h>
int main()
{
int a,i,n,t=0;
int s=0;
do
{
printf("请输入a在1-9之间:");
scanf("%d",&a);
}while(a<1||a>9);
printf("请为n赋值:");
scanf("%d",&n);
for(i=1;i<n+1;i++)
{
t=10*t+a;
s+=t;
printf("a(%d)为%d\n",i,t);
}
printf("他们的总和为%d\n",s);
return 0;
}