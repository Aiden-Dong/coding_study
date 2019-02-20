# include <iostream>
# include <iterator>
# include <algorithm>
# include <vector>
# include <string>

void cout_f (int a){std::cout << a << " " ;}
 
int main ()
{
	using namespace std ;
	vector <int> one ;

	int til[] = {1 , 2 , 4 , 12 , 11 , 15 , 6 , 14};

	while (1)
	{
		int a ;
		cin >> a ;
		one.push_back (a) ;
		if (a==10)
			break ;
	}
	ostream_iterator <int> out_lod (cout , " ") ;

	copy (one.begin () , one.end() , out_lod ) ;
	cout << endl ;

	vector<int>::reverse_iterator f1 ;   // 反向迭代器

	copy(istream_iterator<int>(cin) , istream_iterator<int>() , one.begin());
	
	copy (one.rbegin () , one.rend() , out_lod ) ;

	cout << endl ;

	back_insert_iterator <vector<int> >hl1 (one) ;
	copy (til , til+ 6  , hl1) ; 

	for_each (one.begin () , one.end () , cout_f) ;
	cout << endl ;

	one.pop_back () ;

	for_each (one.begin () , one.end () , cout_f) ;	//	删除最后元素 
	cout << endl ;
	

	return 0 ;
}
/*
在 VC++ 6.0 中的输出结果是 ：
===============================
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10
10 9 8 7 6 5 4 3 2 1
1 2 3 4 5 6 7 8 9 10 1 2 4 12 11 15
1 2 3 4 5 6 7 8 9 10 1 2 4 12 11 
===============================
*/