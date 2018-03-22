#include <dirent.h>
#include <stdio.h>

int main ( int argc, char *argv[])
{
	DIR *dp;
	struct dirent *dir;
	
	if (argc != 2)
	{	
		puts("please input a lparam as ls dectoryname");
		return 0;
	}
	if((dp = opendir(argv[1])) == NULL)
	{
		printf("can't open %s", argv[1]);
		return 0;
	}
	
	while ((dir=readdir(dp)) != NULL)
		printf("%s\n", dir->d_name);

	closedir(dp);

	return 0;
}
