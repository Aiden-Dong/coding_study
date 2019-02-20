# include <iostream>
# include <algorithm>	// 算法
# include <iterator>	// 迭代器 
# include <vector>	    // vector   序列模型 ， 循序双向遍历列表 随机访问 虽然在首部插入与删除是线性的 ， 但允许这种方式 插入 ；
# include <deque>	    // deque	 双端队列 ， 与 vector 的区别是 它在首部跟尾部插入与删除都是 固定时间 ;
# include <queue>	    // queue	 队列模型 ， 不允许遍历队列 ，允许将元素添加到队尾 ， 并允许删除队首元素 
# include <list>	    // list	     双向链表 ， 不支持随机访问 ， 允许双向遍历链表
# include <stack>	    // stack    标准链表（栈的实现） ， 不允许随机访问栈空间 ， 甚至不允许遍历栈 ，允许形式类似于队列模型

bool sort_two (int x1 ,int x2) ;	// 二元谓词
void for_cout (int a) ;			// 一元 函数  

int main ()
{
	using std::vector ;	// STL 中的 vector 容器 
	using std::deque ;	// STL 中的 deque 容器
	using std::list ;	// STL 中的 list 容器
	using std::queue ;  // STL 中的 queue 容器
	using std::stack ;	// STL 中的 stack 容器 
	
	using std::cin ;
	using std::cout ;
	using std::endl ;

	using std::copy ;		    // 使用 STL 算法 copy	复制
	using std::sort ;			// 使用 STL 算法 sort	排序
	using std::random_shuffle ; // 使用 STL 算法 random_shuffle 随机排序 
	using std::for_each ;		// 使用 STL 算法 for_each 遍历容器

	using std::reverse_iterator	;	// 反向迭代器 
	using std::iterator ;			// 普通的正向迭代器
	using std::ostream_iterator ;	// 使用预定义迭代器 : ostream_iterator 
	

	vector<int> one ;	// 申请容器 vector 空间
	int a ;

	cout << "请为 vector 进行初始化 : " << endl ;

	a = 1 ; 
	while (a!=10)		// vector 初始化
	{
		cin >> a ;
		if (a != 10)
			one.insert (one.begin(), a) ;	// 调用 insert 方法 ; 插入
	}

	a = 1 ; 
	deque <int> two ;	// 申请 deque 空间 

	cout << "请为 deque 进行 初始化 : " << endl ;
	while (a!=10) // deque 初始化
	{
		cin >> a ;
		if (a!=10)
			two.push_front (a) ;
	}



	a = 1 ; 
	list<int> three ;	// 申请 list 空间

	cout << "初始化 list : " << endl ;
	while (a != 10)
	{
		cin >> a ;
		if (a != 10)
			three.push_front (a) ;
	}


	a = 1 ; 
	queue<int> four ;	// 申请 queue 空间

	cout << "queue 初始化 : " << endl ;

	while (a!=10)
	{
		cin >> a ;
		if (a!=10)
			four.push (a) ;	// queue 的压入方法是保守型的 ， 并不同与 list vector deque  ;
		//four.push_front () ;  这种方法是不可行的 ；

	}

	a = 1 ; 
	stack<int> five ;

	cout << "stack 初始化 : " << endl ;

	while (a != 10)
	{
		cin >> a ; 
		if (a != 10)
			five.push (a) ;	// 标准压栈方式 ； 与队列模型的区别就是 它在 “压栈” ;

	}

	// 各类初始化完毕 

	// vector(one) deque (two) list (three)  queue (four) stack (five)

	cout << "vector 容器中的原始数据 : " << endl ;

	copy (one.begin () , one.end() , ostream_iterator <int , char> (cout , " ")) ;
	sort (one.begin () , one.end ())  ;	// sort () 排序形式 法 1 
	cout << "排序之后 : " << endl ;
	copy (one.begin () , one.end() , ostream_iterator <int , char> (cout , " ")) ;

	cout << "deque 容器中的原始数据 : " << endl ;
	for_each (one.begin () , one.end() , for_cout) ;
	cout << endl ;
	random_shuffle (one.begin () , one.end() ) ;	// 调用 容器算法 random_shuffle 
	cout << "排序之后 : " << endl ;
	for_each (one.begin () , one.end() , for_cout) ;
	cout << endl ;


	cout << "list 容器中的原始数据  : " << endl ;
	//list<int>::iterator go ; 不支持随机访问 
	
	copy (three.begin () , three.end () , ostream_iterator<int , char> (cout , " ")) ; // 可以使用 容器算法 ； 
			// 允许双向遍历链表

	//sort (three.begin () , three.end () , sort_two) ;	// sort () 算法二 ；
			// 不能使用标准容器算法的原因是 : list 容器限制 ， 不允许遍历

	three.sort () ;

	cout << "list 容器排序后 : " << endl ;

	three.remove (4) ;	// 删除所有 4 的元素 ；
	cout << "remove () : " << endl ;
	copy (three.begin () , three.end () , ostream_iterator<int , char> (cout , " ")) ;
	three.unique () ;
	cout << "unique : " << endl ;
	copy (three.begin () , three.end () , ostream_iterator<int , char> (cout , " ")) ;

	cout << "queue 是 队列模型  : "  << endl ;
	while (!four.empty())
	{
		cout << four.front () << " " << four.back () << endl ;
		four.pop () ;
		// four.push ()  添加元素到队首 
	}

	cout << "stack : 链表栈  " << endl ;
	while (!five.empty ())
	{
		cout << five.top () << endl; // 只能查看栈首元素 
		five.pop() ;	// 出栈
		//five.push ()  // 压栈
	}



	return 0 ;
}

bool sort_two (int x1 ,int x2)
{
	if (x1 > x2)
		return true ;
	return false ;
}
void for_cout (int a)
{
	std::cout << a << " " ;
}
/*
在 VC++6.0 的运行环境中:
==========================
请为 vector 进行初始化 :
4 5 8 7 6 3 2 1 9 4 6 8 2 3 1 10
请为 deque 进行 初始化 :
7 8 9 4 5 3 2 1 6 3 2 4 7 9 0 4 10
初始化 list :
5 7 9 4 3 5 6 1 4 7 8 9 3 2 4 8 1 4 6 3 7  5 6 4 3 10
queue 初始化 :
4 6 8 7 9 2 1 4 6 32 8 7 5 62 4 2 5 6 41 4 3 46 4 1 10
stack 初始化 :
2 8 9 4 5 6 5 4 3 1 2 5 7 8 9 5 4  6 4 52 2 1 3 56 4 10
vector 容器中的原始数据 :
1 3 2 8 6 4 9 1 2 3 6 7 8 5 4 排序之后 :
1 1 2 2 3 3 4 4 5 6 6 7 8 8 9 deque 容器中的原始数据 :
1 1 2 2 3 3 4 4 5 6 6 7 8 8 9
排序之后 :
3 2 1 2 6 8 5 7 3 1 4 8 4 9 6
list 容器中的原始数据  :
3 4 6 5 7 3 6 4 1 8 4 2 3 9 8 7 4 1 6 5 3 4 9 7 5 list 容器排序后 :
remove () :
1 1 2 3 3 3 3 5 5 5 6 6 6 7 7 7 8 8 9 9 unique :
1 2 3 5 6 7 8 9 queue 是 队列模型  :
4 1
6 1
8 1
7 1
9 1
2 1
1 1
4 1
6 1
32 1
8 1
7 1
5 1
62 1
4 1
2 1
5 1
6 1
41 1
4 1
3 1
46 1
4 1
1 1
stack : 链表栈
4
56
3
1
2
52
4
6
4
5
9
8
7
5
2
1
3
4
5
6
5
4
9
8
2
Press any key to continue
=============================
*/