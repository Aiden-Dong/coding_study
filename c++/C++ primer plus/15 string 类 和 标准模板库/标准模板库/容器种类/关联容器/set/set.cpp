# include <iostream>
# include <set>
# include <iterator>
# include <algorithm>

int main ()
{
	using namespace std ;

	set<int>one ;
	set<int>two ;

	while (1)
	{
		int a , b ;
		cin >> a >> b ;
		one.insert (a);
		two.insert (b) ;
		if (a==10 || b == 10)
			break ;
	}

	copy (one.begin () , one.end () , ostream_iterator<int , char>(cout , " "));
	cout << endl ;

	copy (two.begin () , two.end () , ostream_iterator<int , char>(cout , " "));
	cout << endl ;

	cout << "set_union : " << endl ;
	set_union (one.begin () , one.end () , two.begin () , two.end () , ostream_iterator<int , char>(cout , " "));
	cout << endl ;

	cout << "set_intersection : " << endl ;
	set_intersection (one.begin () , one.end () , two.begin () , two.end () , ostream_iterator<int , char>(cout , " "));
	cout << endl ;

	cout << "set_difference: " << endl ;
	set_difference (one.begin () , one.end () , two.begin () , two.end () , ostream_iterator<int , char>(cout , " "));
	cout << endl ;

	cout << *one.lower_bound (5) << endl ;
	cout << *one.upper_bound (5) << endl ;

	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
===============================
4 5 3 2 7 8 9 6 4 1 2 4 6 14 2 3 6 8 4 6 7 9 7 4 5 2 10 10

2 3 4 5 6 7 9 10
1 2 3 4 5 6 8 9 10 14
set_union :
1 2 3 4 5 6 7 8 9 10 14
set_intersection :
2 3 4 5 6 9 10
set_difference:
7
5
6
Press any key to continue
=============================
*/