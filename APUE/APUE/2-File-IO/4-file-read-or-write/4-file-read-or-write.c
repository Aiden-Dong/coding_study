#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define BUFFSIZE 4096

int main()
{	
	int n;
	char buf[BUFFSIZE];

	printf("error initialize : %s\n", strerror(errno));

	while((n = read(STDIN_FILENO, buf, BUFFSIZE)) != -1)
	{
		if(write(STDOUT_FILENO, buf, n) != n)
			{
				printf("write error : %s\n", strerror(errno));
				return 0;
			}
	}
		
	if (n == -1)
		printf("read error : %s", strerror(errno)); 
	
	return 0;
}
