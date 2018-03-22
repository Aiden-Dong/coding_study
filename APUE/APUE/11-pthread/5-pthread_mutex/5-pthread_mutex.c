#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>

inline void err_sys(const char *msg, int err)
{
	printf("%s : %s\n", msg, strerror(err));
	exit(0);
}

int main()
{
	return 0;
}
