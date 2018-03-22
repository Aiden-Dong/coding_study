//测指针大小和数组长度
# include <stdio.h>

void memory (int a[10]) ;

int main ()
{
int a[20] ;
int i ;

for ( i = 0 ; i < 10 ; i ++)
a[i] = i ;
//printf("数组长度为%d\n",sizeof(a));//a代表这个数组
memory (a) ;

return 0 ;
}
void memory (int a[10])
{
	
//测数组长度
printf ("%d\n",a);
printf ("%d\n",&a);
printf("数组长度为%d\n",sizeof(a));//a代表这个数组
printf ("a 的大小 : %d\n" , sizeof (a[10])); // 即使形参为 a[10]  编译器 也会自动的转化为 指针 
printf("a[9] = %d\n" , a[9]) ;  // a[9] = 9
}