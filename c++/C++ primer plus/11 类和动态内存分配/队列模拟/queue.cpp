# include <cstdlib>
# include "name.h"

Queue::Queue (int qs) : qsize (qs)
{
	items = 0 ;
	Link.p1 = Link.p2 = NULL ; 
}

Queue::~Queue ()
{
	PNODE temp ;
	while (Link.p1 != NULL)
	{
		temp = Link.p1 ;
		Link.p1 = Link.p1 -> next ;
		delete temp ;
	}
}

bool Queue::isempty () const                //  检查是否为空队列 
{
	return items == 0 ;
}

bool Queue::isful () const                 // 检查是否队列满
{
	return items == Q ;
}

int Queue::queuecount () const                       // 调出队列中对象个数
{
	return items ;
}

bool Queue::enqueue (const Item & item )
{
	if ( isful () )
		return false ;                               // 满队列处理方式

	PNODE add = new NODE ;
	add->item = item ;                               // 创造一个副本 
	add->next  = NULL;
	items ++ ; 

	if (Link.p1 == NULL)                            // 空队列处理
		Link.p1 = add ;
	else
		Link.p2 ->next = add ; 

	Link.p2 = add;

	return true ;

}

bool Queue::dequeue (Item & item)      //删掉一个队列
{
	if (Link.p1 == NULL)
		return false ;
	item = Link.p1->item ;
	items -- ; 

	PNODE temp = Link.p1;
	Link.p1 = Link.p1->next ;
	delete temp ;

	if (temp == 0 )
		return false ;

	return true ;
}

void Customer::set ( long when )
{
	process = rand()% 3 +1 ;
	arrive = when;
}