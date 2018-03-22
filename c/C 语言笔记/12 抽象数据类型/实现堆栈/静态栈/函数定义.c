# include <stdio.h>
# include "static.h"

static int stack[Max] ;
static int top_sum = 0 ;

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