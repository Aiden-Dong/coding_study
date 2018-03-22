# include <iostream>
# include <deque>
# include <iterator>

int main ()
{
	using namespace std ;

	int a ;

	deque <int> one ;

	while (1)
	{
		cin >> a ;
		one.insert (one.end() , a) ;

		if (a == 10)
			break;
	}

	cout << one.front () << endl ;
	cout << one.back () << endl ;

	one.push_front (12) ;
	one.push_back (13) ;

	one.erase (one.begin () , one.begin()+4) ;
	copy (one.begin () , one.end () , ostream_iterator<int , char>(cout , " "));


	return 0 ;
}
/*
在 VC++ 6.0 中的输出结果是 ：
============================
1 5 12 16 8 1 41 4 18 20 10
1
10
16 8 1 41 4 18 20 10 13 
============================
*/