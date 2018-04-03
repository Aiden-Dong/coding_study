//aabb型的完全平方数13
#include<stdio.h>
int main()
{
int N,x;
int N1,N2,N3,N4;
for(x=32;x<100;x++)
{
N=x*x;
N1=N/1000;
N2=N%1000/100;
N3=N%100/10;
N4=N%10;
if(N1==N2&&N3==N4)
printf("%d为完全平方数\n",N);
}
return 0;
}