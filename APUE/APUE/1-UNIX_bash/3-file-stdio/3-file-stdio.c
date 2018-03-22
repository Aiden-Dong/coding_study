#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int c;

	while((c = getc(stdin)) != EOF)
	{
		if(putc(c, stdout) == EOF)
		{
			puts("output error");
			return 0;
		}
	}
	if(ferror(stdin)) // 检测标准输入中的错误， 如果没有错误则返回 0（false）
	{
		puts("stdin error");
		exit(0) ;
	}
	return 0;
}
