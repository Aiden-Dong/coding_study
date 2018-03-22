#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	if(execl("5-process-uid.out", NULL) == -1)
	{
		puts("execl error");
		exit(0);
	}

	return 0;
}
