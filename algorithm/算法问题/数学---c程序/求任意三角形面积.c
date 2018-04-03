/*求任意三角形面积*/
#include<stdio.h>
#include<math.h>
int main()
{
float a,b,c,d,t;
float S;
printf("Enter three numbers:");
scanf("%f%f%f",&a,&b,&c);//输入三个数
d=(a+b+c)/2;//三边之和的一半
t=d*(d-a)*(d-b)*(d-c);
S=sqrt(t);//海伦公式
printf("S=%f",S);
return 0;
}