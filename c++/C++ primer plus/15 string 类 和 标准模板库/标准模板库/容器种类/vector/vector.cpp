# include <iostream>
# include <vector>
# include <iterator>

int main ()
{
	using namespace std ;

	int s[] = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 } ;
	vector<int>one (s , s+6);

	cout<< one.front () << endl ;	//	front()
	cout << one.back () << endl ;	//  back()

	one.push_back (12) ;		//	push_back()

	copy (one.begin() , one.end () , ostream_iterator<int , char>(cout , " "));
	cout << endl ;

	one.pop_back () ;		// pop_back () 

	copy (one.begin() , one.end () , ostream_iterator<int , char>(cout , " "));
	cout << endl ;

	one.insert (one.end() , 2 , 5) ;
	one.insert (one.begin (), s+7 , s+12);  // insert ()
	
	copy (one.begin() , one.end () , ostream_iterator<int , char>(cout , " "));
	cout << endl ;

	cout << one.size () << endl ;		// size ()

	return 0 ;

}
/*
在 VC++ 6.0 中的输出结果是 ：
============================
1
6
1 2 3 4 5 6 12
1 2 3 4 5 6
8 9 10 11 12 1 2 3 4 5 6 5 5
13
Press any key to continue
============================
*/