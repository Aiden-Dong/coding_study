#include <stdio.h>

int main ()
{
	char buf[20];
	int nlen;

	nlen = snprintf(buf, 20, "hello world\n");
	fputs(buf,stdout);
	printf("nlen = %d\n", nlen);

	return 0;
}
