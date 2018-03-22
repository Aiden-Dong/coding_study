# include <iostream>

void arr_ang (const int * str );
void arr_ang2( const int ** str);

int main ()
{
	using namespace std;

	int str[5];
    int *str1 = str;
	const int *str2 = str;


	cout << "请输入 5 个数据" << endl;

	for ( int i = 0 ; i < 5 ; i++)
		cin >> str[i];

	arr_ang (str); 
	//arr_ang2 ( &str1 ); // error C2664: 'arr_ang2' : cannot convert parameter 1 from 'int ** ' to 'const int ** '
	arr_ang2 ( &str2 );   // 在不同级指针中  不可进行变量与常量的赋值

	return 0;
}
void arr_ang (const int * str )    //  常量指针不可以更改内部数据
{
	std :: cout << std::endl;

	for (int i = 0 ; i < 5 ; i++)
		std :: cout << str[i] << " "<<std::endl; 
	//str[2] = 89;                                error C2166: l-value specifies const object
}
void arr_ang2( const int ** str)
{
	using namespace std;

    cout << **str << endl << *str << endl << str << endl;
}
/*
在 VC++ 6.0 中的输出结果是 ：
===========================
请输入 5 个数据
12
123
1
23
54

12
123
1
23
54
12
0012FF34
0012FF2C
Press any key to continue
===========================
*/