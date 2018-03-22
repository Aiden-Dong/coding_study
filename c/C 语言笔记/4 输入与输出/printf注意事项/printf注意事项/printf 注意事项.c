# include <stdio.h>
# include <stdlib.h>

int main()
{
	printf("%d , %d , %d, %d, %d, %d\n", 1);// 1 , 0 , 0, 2147328000, -858993460, -858993460 
											// 当符号超过后面的变量时 ，其后面的值将是不确定的 

	printf("%d\n", 1, 1);					// 当变量超过转换符时候 后面的将被忽略

	system("pause");

	return 0;
}