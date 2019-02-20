# include <iostream>
# include "arrayTP.h"

int main ()
{
	using std::cout ;
	using std::cin ;
	using std::endl ;

	ArrayTP <int , 10>one ;
	ArrayTP<double , 10>two ;
	ArrayTP < ArrayTP<int , 5> , 10> first ;   // 声明了一个 类型为 ArrayTP<int,5>(类型为int 长度为5 数组)
											   // 长度为 10 的数组 （二维数组概念）

	int i , j ;

	for (i = 0 ; i < 10 ; i++)
	{
		one [i] = i ;   // 调用非 const 的重载运算符

		for (j = 0 ; j < 5 ; j++)
		{
			first [i][j] = i + j ;   // 此处的 first[i][j] 为多重调用 现调用了第一层 first[i] 为第 i 的
		}							 // ArrayTP<int,5> 对象 然后调用 <j> 为第 i 的ArrayTP<int,5> 对象 
									 // 的第 j 个 ar 值
		two[i] = (double)one[i] / 10 ;

	}

	for (i = 0 ; i < 10 ; i++)
	{
		cout << "one : " << one[i] <<"     ";
		cout << "two : " << two[i] << endl ;
	}

	for (i = 0 ; i < 10 ; i++)
		for (j = 0 ; j < 5 ; j ++)
			cout << "first : " << first[i][j] << endl ;

		return 0 ;
		
}
/*
在 VC++ 6.0 中的输出结果是 ：
==============================
one : 0     two : 0
one : 1     two : 0.1
one : 2     two : 0.2
one : 3     two : 0.3
one : 4     two : 0.4
one : 5     two : 0.5
one : 6     two : 0.6
one : 7     two : 0.7
one : 8     two : 0.8
one : 9     two : 0.9
first : 0
first : 1
first : 2
first : 3
first : 4
first : 1
first : 2
first : 3
first : 4
first : 5
first : 2
first : 3
first : 4
first : 5
first : 6
first : 3
first : 4
first : 5
first : 6
first : 7
first : 4
first : 5
first : 6
first : 7
first : 8
first : 5
first : 6
first : 7
first : 8
first : 9
first : 6
first : 7
first : 8
first : 9
first : 10
first : 7
first : 8
first : 9
first : 10
first : 11
first : 8
first : 9
first : 10
first : 11
first : 12
first : 9
first : 10
first : 11
first : 12
first : 13
Press any key to continue
==============================
*/