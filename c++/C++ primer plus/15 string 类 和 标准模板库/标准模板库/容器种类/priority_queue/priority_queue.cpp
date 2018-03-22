# include <iostream>
# include <queue>

int main ()
{
	using namespace std ;
	
	priority_queue <int>one ;

	while (1)
	{
		int a ;
		cin >> a ;
		one.push (a) ;	// push ()
		if (a == 10 )
			break ;
	}

	cout << one.top()  << endl ;
	
	while (!one.empty ())
	{		
		one.pop () ;	// pop()
		cout << one.size ()<< " " ;  // size () 
		cout << one.top () << endl ;
	}

	return 0 ;
}
/*
===============================
9 4 6 2 7 12 16 4 7 6 3 10
16
11 12
10 10
9 9
8 7
7 7
6 6
5 6
4 4
3 4
2 3
1 2
0 2
Press any key to continue
===========================
*/