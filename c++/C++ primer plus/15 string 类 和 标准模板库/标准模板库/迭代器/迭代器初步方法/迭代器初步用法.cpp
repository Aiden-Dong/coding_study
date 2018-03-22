# include <iostream>
# include <vector>

int main ()
{
	using namespace std ;

	vector <int> one;
	vector <int>two ;

	vector <int>::iterator go ;	// 迭代器声明 

	int first [20] = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15 , 16 , 17 , 18 , 19 , 20 };

	one.push_back (int(0) ) ; 

	cout << "push_back : " << endl ;				   //	push_back 用法
	for (go = one.begin () ; go != one.end () ; go++ ) // 迭代器条件
		cout << * go << endl ;
	
	one.insert (one.end () , first , first + 20) ;      // insert () 用法  // 不包含最后一个 元素 
	
	cout << "insert : " << endl ;
	for (go = one.begin () ; go != one.end () ; go++ ) 
		cout << * go << endl ;

	cout << "erase : " << endl ;
	one.erase (one.begin () + 10 , one.end()) ;      // erase () 的用法 ； 此处要注意
	for (go = one.begin () ; go != one.end () ; go++ ) 
		cout << * go << endl ;

	cout << "one.size = " << one.size () << endl ; 

	one.swap (two) ;								// swap () 的用法 

	for (go = one.begin () ; go != one.end () ; go++ ) 
		cout << * go << endl ;

	cout << "show ： " << endl ;
	for (go = two.begin () ; go != two.end () ; go++ ) 
		cout << * go << endl ;

	return 0 ;
}
/*
在 VC++ 6.0 中的输出结果是 ：
===========================
push_back :
0
insert :
0
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
erase :
0
1
2
3
4
5
6
7
8
9
one.size = 10
show ：
0
1
2
3
4
5
6
7
8
9
Press any key to continue
===========================