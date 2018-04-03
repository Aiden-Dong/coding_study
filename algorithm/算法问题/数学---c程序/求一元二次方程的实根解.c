//求一元二次方程的实根解
#include<stdio.h>
#include<math.h>
int main()
{
float a,b,c;
float t,m,n,x1,x2;
printf("Enter three numbers:");
scanf("%f%f%f",&a,&b,&c);
t=b*b-4*a*c;
if(t<0)
printf("无实根");
else
{
m=sqrt(t)/(2*a);
n=-b/(2*a);
x1=n+m;
x2=n-m;
printf("x1=%f,x2=%f",x1,x2);
}
return 0;
}
