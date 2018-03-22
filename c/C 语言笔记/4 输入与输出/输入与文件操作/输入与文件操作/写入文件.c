# define _CRT_SECURE_NO_DEPRECATE

# include <stdio.h>
# include <stdlib.h>

// cd 路径 1.exe<intput.txt>output.txt
int main()
{
	char str[10];

	scanf("%s", str);

	system(str);
	
	return 0;
}