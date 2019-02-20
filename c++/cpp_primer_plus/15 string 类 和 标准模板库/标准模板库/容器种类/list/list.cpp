# include <iostream>
# include <list>
# include <iterator>

int main ()
{
	using namespace std ;
	list<int> one ;
	list<int> two ;

	int a , b ;

	while(1)
	{
		cin >> a >> b ;
		one.push_front (a) ;
		two.push_back (b) ;
		if (a== 10)
			break ;
	}
	cout << "one 的初始值 : " << endl ;
	copy (one.begin() , one.end() , ostream_iterator<int , char>(cout , " "));  // 允许遍历栈
	cout << endl ;
	cout << "two 的初始值 : " << endl ;
	copy (two.begin() , two.end() , ostream_iterator<int , char>(cout , " "));
	cout << endl ;

	one.sort () ;		// sort()  // 排序
	two.sort () ;

	cout << "one.sort : " << endl ;
	copy (one.begin() , one.end() , ostream_iterator<int , char>(cout , " "));
	cout << endl ;

	one.merge(two);			//merge()  // 合并

	cout << "one.merge : " << endl ;
	copy (one.begin() , one.end() , ostream_iterator<int , char>(cout , " "));
	cout << endl ;

	one.remove (1) ;	//remove() // 删除实例
	cout << "one.remove : " << endl ;
	copy (one.begin() , one.end() , ostream_iterator<int , char>(cout , " "));
	cout << endl ;

	one.unique () ;			//unique() // 合并相同元素
	cout << "one.unique : " << endl ;
	copy (one.begin() , one.end() , ostream_iterator<int , char>(cout , " "));
	cout << endl ;

	return 0 ;
}
/*
在 VC++ 6.0 中的输出结果是 ：
==========================
2 13 15 1 8 4 6 9 4 2 14 13 6 9 7 5 2 9 8 1 3 5 4 8 10 10
one 的初始值 :
10 4 3 8 2 7 6 14 4 6 8 15 2
two 的初始值 :
13 1 4 9 2 13 9 5 9 1 5 8 10
one.sort :
2 2 3 4 4 6 6 7 8 8 10 14 15
one.merge :
1 1 2 2 2 3 4 4 4 5 5 6 6 7 8 8 8 9 9 9 10 10 13 13 14 15
one.unique :
1 2 3 4 5 6 7 8 9 10 13 14 15
Press any key to continue
==========================
*/