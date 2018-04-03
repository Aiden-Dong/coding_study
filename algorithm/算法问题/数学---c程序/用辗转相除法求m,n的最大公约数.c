//用辗转相除法求m,n的最大公约数
#include<stdio.h>
int main()
{
int m,n,j;
printf("enter two numbers:");
scanf("%d%d",&m,&n);
if(!m||!n)
exit(0);
j=m%n;//取余
while(j)
{
m=n;
n=j;
j=m%n;
printf("j=%d\n",j);
}
printf("最大公约数为%d\n",n);
return 0;
}
/*思考为什么一开始不用比较m,n大小？
例如28 35 （j=7 j=0） 和35 28(j=0) 的区别
28%35==28;m=35,n=28回到正确的大小位置（m>n）
补充：所以m,n的大小不用提前比较（若m<n只是比m>n多一交换位置步）*/