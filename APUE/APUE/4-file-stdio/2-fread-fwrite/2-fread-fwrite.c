#include <stdio.h>
#include <string.h>

int main (int argc, char *argv)
{
	int nlen;
	char buf[20];

	memset(buf, 0, sizeof(buf));

	fprintf(stdout, "please input a string\n");
	int n = fread(buf, sizeof(buf), 1, stdin);

	fputs("====================================\n", stdout);
	nlen=strlen(buf);

	fputs(buf, stdout);

	fputs("\n====================================\n", stdout);

	printf("n = %d\n", n);
	printf("nlen = %d\n", nlen);

	return 0;	
}
