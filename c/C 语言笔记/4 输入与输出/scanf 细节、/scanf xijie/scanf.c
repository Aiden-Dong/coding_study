# define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include <stdlib.h>

int main()
{
	double a = 10;
	long long ll;
	int d , b, c;

	scanf("%d", &ll);
	printf("%d", ll);
	scanf("%d		%d", &b, &c);	//	后面加 %3d 就是要求使用最大宽度为 3
	printf("b = %d , c = %d\n", b, c);

	scanf("%d%*d%d", &d, &b, &c);	//	d = 12, b = 14, C = -858993460	// 将忽略中间的一个数值的输入
	printf("d = %d , b = %d , C = %d\n", d, b, c);

	scanf("%lf", &a);
	printf("a = %lf\n", a);	// double 使用 %lf 接收字符
	system("pause");
	return 0;
}
