# include <stdio.h>
# include "stack.h"

int * stack ;
int top_sum = 0 ; 
int	Max = 0 ;
 
void create_stack (int size)
{
	if (Max == 0)
	{
		stack = (int *) malloc (size * sizeof(int)) ;
		Max = size ;
	}
	else
		puts ("已经为栈区分配内存 !!!!") ;

}


void destroy_stack (void) 
{
	free (stack);
}

void push (int a)
{
	if (full())
		printf ("已经满栈 !!!\n") ;
	else 
	{
		stack[top_sum] = a ;
		top_sum++ ;
	}
}
void pop (void) 
{
	if (is_empty())
		puts ("这是个空栈!!!");
	else
		top_sum-- ;
}
int top (void)
{
	if (is_empty())
	{
		puts ("这是个空栈!!!");
		return 0 ;
	}

	else
		return stack[top_sum-1] ;
}

int is_empty (void)
{
	return top_sum == 0 ;
}
int full (void)
{
	return top_sum == Max ; 
}