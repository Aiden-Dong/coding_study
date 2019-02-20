# include <iostream>
# include <iterator>  
# include <vector>
# include <algorithm>

void c_out (int a) ;
bool gin (const int r1 , const int r2) ;

int main ()
{
	using namespace std ;
	
	vector <int> one ;
	vector <int>::iterator go ;			// 位于头文件 iterator中

	while (1)
	{
		int a ;
		cin >> a ;
		one.push_back (a) ;
		if (a == 10)
			break ;
	}

	for_each (one.begin () , one.end () , c_out ) ; // 调用 for_each () 的用法 ； // 需使用头文件 algorithm
	cout << endl ;

	random_shuffle (one.begin () , one.end ()) ;	// random_shuffle () 随机排序

	for_each (one.begin () , one.end () , c_out ) ;
	cout << endl ;

	sort(one.begin () , one.end ()) ;			//一般是按照升序进行排序 但可以使用谓词 

	for_each (one.begin () , one.end () , c_out ) ;
	cout << endl ;

	sort(one.begin () , one.end () , gin );		// gin 二元谓词 ; 
	
	for_each (one.begin () , one.end () , c_out ) ;
	cout << endl ;

	return 0 ;
}
void c_out (int a)
{
	std::cout << a << " "  ;
}
bool gin (const int r1 , const int r2) 
{
	if (r1 > r2)
		return true ;
	return false ;
}
/*
在 VC++ 6.0 中的输出结果是 ：
===========================
2
13
2
432
5
45
65
76
32
14
32
25
154
13
12
10
2 13 2 432 5 45 65 76 32 14 32 25 154 13 12 10
5 10 2 2 32 154 32 25 45 13 65 13 76 12 14 432
2 2 5 10 12 13 13 14 25 32 32 45 65 76 154 432
432 154 76 65 45 32 32 25 14 13 13 12 10 5 2 2
Press any key to continue
===========================
*/