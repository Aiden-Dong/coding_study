#include<stdio.h>

void jiaohuan(int *,int *,int *);

int main()
{
	int a = 0 ,b = 0 ,c =0 ;

	
	printf("之前%d %d %d\n:",a,b,c);
	jiaohuan(&a,&b,&c);
	printf("之后%d %d %d\n:",a,b,c);
	return 0;
}
void jiaohuan(int *x,int *y,int *z)
{
	
	*x=*y;//将y赋给x
	*y=*z;//将z赋给y
	++(*z);//[同级，且从右向左，(即z+1后取地址？？？)为什么与*z++效果一样???]
}