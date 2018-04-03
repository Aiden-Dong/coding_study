//aabb型的完全平方数12
#include<stdio.h>
#include<math.h>
int main()
{
int a,b,n,x;
for(a=1;a<10;a++)
 for(b=0;b<10;b++)
 {
 n=1100*a+11*b;
 x=sqrt(n);
 if(n==x*x)
 printf("%d为完全平方数\n",n);
 }
 return 0;
 }