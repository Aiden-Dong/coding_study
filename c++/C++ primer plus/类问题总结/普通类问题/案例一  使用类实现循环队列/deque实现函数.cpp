# include <iostream>
# include "deques.h"
# include <iomanip>

deque_s::deque_s () : front(0), rear (0) , sum (0) {}	// 成员初始化列表

bool deque_s::push_deque (int a)
{
	if (fill_deque ())
		return false ;

	Gether[rear] = a ;
	rear = (rear + 1) % SUM ;
	sum ++ ;
	return true ;
}

bool deque_s::pop_deque (int &a)
{
	if (empty_deque())
		return false ;
	
	a = Gether[front] ;	// 取值
	front = (front+1) %SUM ;
	sum -- ;
	return true ;
}

void deque_s::show_deque (void) 
{
	int i ;
	int Sum = 1 ;

	std::cout << "队列元素 : "  << " " ;

	for (i = front ; Sum <= sum ; i = (i+1)%SUM )
	{
		std::cout << Gether [i]  << " -> " ;
		Sum ++ ;
	}

	std::cout << " End" << std::endl ;

	std::cout << "front = " << front << std::endl ;
	std::cout << "rear = " << rear << std::endl ;
	std::cout << "sum = "  << sum  << std::endl ;
}


