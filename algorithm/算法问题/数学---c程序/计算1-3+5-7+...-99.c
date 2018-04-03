/*计算1-3+5-7+...-99*/
#include<stdio.h>
int main()
{
int i,s=0;
for(i=1;i<101;i+=2)
{
if(i%4==1)
	s=s+i;
else
s-=i;
}
printf("%d\n",s);
return 0;
}