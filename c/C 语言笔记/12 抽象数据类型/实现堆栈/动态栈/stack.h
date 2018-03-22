# ifndef STACK_H_
# define STACK_H_

void push (int a) ;	// 压栈
void pop (void) ;	// 出栈
int full (void) ;	// 检查是否栈满
int empty (void) ;	// 检查是否栈空
int top (void) ;	// 返回栈首的内容
void create_stack (int size) ;	// 为栈区分配内存
void destroy_stack (void) ;		// 释放栈区

# endif