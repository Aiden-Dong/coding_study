#include <stdio.h>
#include <sys/resource.h>
#include <unistd.h>

int main()
{
	struct rlimit rlim;

	getrlimit(RLIMIT_AS, &rlim);
	printf("soft : %d, hard : %d\n", rlim.rlim_cur, rlim.rlim_max);
	getrlimit(RLIMIT_NICE, &rlim);
	printf("soft : %d, hard : %d\n", rlim.rlim_cur, rlim.rlim_max);	

	return 0;
}
