#include <stdio.h>

int main()
{
	int a = 5;
	printf("%#x\n", &a);
	printf("%d", a);
	printf("%d", sizeof(a));
	int b = 10;
	int c;

	return 0;
}