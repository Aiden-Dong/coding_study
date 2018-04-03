//求非实数的算术平方根
#include<stdio.h>
#include<math.h>
int main()
{
float a,t;

do 
{
printf("为a赋值");
scanf("%f",&a);
}while(a<0);
t=sqrt(a);
printf("%f",t);
return 0;
}

