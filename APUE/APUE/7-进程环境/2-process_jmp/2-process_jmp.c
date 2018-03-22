#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

void show_test();

// 为了实现非局部跳跃， 所以一般将 jmpbuffer 变量设置为全局
jmp_buf jmpbuffer;

int main()
{
	volatile int one = 5; // 易失变量
	int a = 5;	// 自动变量
	int i = 0;
	
	if(setjmp(jmpbuffer) != 0)// 如果是直接调用 则返回 0
	{	i = 1;
		
		puts("after longjmp:");
		printf("one = %d\na = %d\n", one, a);
	}

	if(i == 0)
	{
		one = 10;
		a = 10;
		puts("before longjmp:");
		printf("one = %d\na = %d\n", one, a);
		show_test();
	}

	return 0;
}

void show_test()
{
	
	longjmp(jmpbuffer, 2);
}
