/*aabb型的完全平方数11*/
#include<stdio.h>
#include<math.h>
int main()
{
int a,b,n,k;
float m;
for(a=1;a<10;a++)
 for(b=0;b<10;b++)
{
k=1100*a+11*b;
m=(float)sqrt(k);
n=sqrt(k);
if(m==n)
printf("%d为完全平方数\n",k);
}
return 0;
}