#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void show_one();
void show_two();
void show_three();

int main()
{
	/*
         * 清理程序是按照压栈方式存储的	 	
	 */

	atexit(show_one);
	atexit(show_two);
	atexit(show_three);

	return 0;
}
void show_one()
{
	printf("one ...\n");
}
void show_two()
{
	printf("two ...\n");
}
void show_three()
{
	printf("three ...\n");
}
