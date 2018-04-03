//水仙花数xyz=x^3+y^3+z^3的所有整数解
#include<stdio.h>
#include<math.h>
int main()
{
int x,y,z,m,n;
for(x=1;x<10;x++)//三重循环从100到999
 for(y=0;y<10;y++)//中间数可以为零
  for(z=0;z<10;z++)
  {
  m=100*x+10*y+z;
  n=pow(x,3)+pow(y,3)+pow(z,3);
  if(m==n)//左右相等
  printf("%d\n",m);
  }
  return 0;
 }