# include <iostream>

void arr_ang1 (int * str);
void arr_ang2 (int * const* str);
void arr_ang3 ( int const *str);

int main ()
{
	using namespace std;

	int str[5] = {1 , 2 , 3 , 4 , 5};
	int str2[2][5] =
	{
		{1 , 2 , 3 , 4 , 5},
		{6 , 7 , 8 , 9 , 10}
	};
	 int * const str1 = str;
	 int const * str3 = str;

	arr_ang1 (str1);
	cout << endl;
	
	//arr_ang1 (str3);      // int const 等价于 const int 
	cout << endl;



	arr_ang3 (str);

	arr_ang2 (&str1);                  //   在不等级的传递中 要有一定的对应性； 
	//arr_ang2 (str2);                 // 二维数组不能用二维指针传递
	
	return 0;
}
void arr_ang1 (int *  str)
{
	for (int i = 0 ; i < 5; i++)
		std::cout << str[i] << std::endl ;
	for (int j = 0 ; j < 5; j++)
		std::cout << &str[j] << std::endl ;
	//str++;                                       //error C2166: l-value specifies const object
}
void arr_ang2 (int * const* str1)
{
	for (int i = 0 ; i < 5; i++)
		std::cout << str1[i] << std::endl ;
	for (int j = 0 ; j < 5; j++)
		std::cout << (*str1)[j] << std::endl ;
}
void arr_ang3 ( int const *str)
{
	std::cout <<"str = "<< str << std::endl;
}
/*
在 VC++ 6.0 中的输出结果是 ：
==============================
1
2
3
4
5
0012FF34
0012FF38
0012FF3C
0012FF40
0012FF44

0012FF34
00000001
00000002
00000003
00000004
1
2
3
4
5
Press any key to continue
==============================
*/