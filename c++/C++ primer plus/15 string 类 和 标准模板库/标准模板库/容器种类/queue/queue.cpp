// queue 要求不能遍历成员 ， 只能查看首部和尾部 , 更不可能实现随机插入和删除（只能从首部删除）
// 典型的队列模型
 
# include <iostream>
# include <queue>
# include <iterator>

int main ()
{
	using namespace std ;

	queue <int>one ;

	while (1)
	{
		int a ;
		cin >> a ;
		one.push (a) ;	// push ()
		if (a == 10 )
			break ;
	}

	cout << one.front () << " " << one.back () << endl ;
	
	while (one.front () != one.back())
	{		
		one.pop () ;	// pop()
		cout << one.size ()<< " " ;  // size () 
		cout << one.front () << " " << one.back () << endl ;
	}

	return 0 ;
}
/*
在 VC++ 6.0 中的输出结果是 ：
============================
4 6 8 12 6 7 9 3 4 9 52 4 16 3 517 24 16 28 37 46 10
4 10
20 6 10
19 8 10
18 12 10
17 6 10
16 7 10
15 9 10
14 3 10
13 4 10
12 9 10
11 52 10
10 4 10
9 16 10
8 3 10
7 517 10
6 24 10
5 16 10
4 28 10
3 37 10
2 46 10
1 10 10
Press any key to continue
============================
*/