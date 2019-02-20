# include <stack>
# include <iostream>

int main ()
{
	using namespace std ;

	stack<int>one ;

	while (1)
	{
		int a ;
		cin >> a;
		one.push (a);
		if (a == 10)
			break ;
	}

	while (!one.empty ())  // empty ()
	{
		cout << one.size () << " " << one.top ()<< endl ;
		one.pop () ;
	}

	return 0 ;
}
/*
在 VC++ 6.0 中的输出结果是 ：
===========================
2 4 15 4 8 6 9 2 4 3 10
11 10
10 3
9 4
8 2
7 9
6 6
5 8
4 4
3 15
2 4
1 2
Press any key to continue
===========================
*/