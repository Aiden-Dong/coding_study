# include <iostream>
# include <cstring>

typedef struct{
	char a[10] ;
	int b ;
}NOTE , *PNOTE ;

template <typename T >
void c_cout (T & a ) ;	//  函数模版

template<> void c_cout<NOTE> (NOTE & a ) ;	// 模板显示具体化 
template void c_cout <int> (int &a);		// 模板显式实例化
template void c_cout <char*>(char * (&a));	// 模板显式实例化 2

void c_cout (int a) ;	// 非模版函数

int main ()
{
	using namespace std ;
	NOTE NAME ;
	
	cout << "please input your name : " << endl; 
	cin >> NAME.a  ;
	cout << "please input your age : " << endl ;
	cin >> NAME.b  ;

	char exam [10] ;

	strcpy (exam , NAME.a) ;

	int a = NAME.b ;

	c_cout (NAME) ;
	c_cout (exam) ;	// 此处注意下 ，这个地方引用的意义在于 引用的是exam变量(即字符串的首地址 ， 注意此处是引用) ;
					// 引用详情请看 模版实例化 2 
	c_cout (a) ;

	return 0 ;
}

template <typename T >
void c_cout (T & a ) 
{
	using std::cout ;
	using std::endl ;

	cout << "a = " << a << endl ;

}

template<>void c_cout <NOTE>(NOTE & a ) 
{
	using std::cout ;
	using std::endl ;

	cout << "name : " << a.a << endl ;
	cout << "age : " << a.b << endl ;

}
void c_cout (int a) 
{
	using std::cout ;
	using std::endl ;
	cout << "此处非模版" << endl ;
}
/*
在 VC++ 6.0 中的输出结果是 ：
=============================
please input your name :
saligia
please input your age :
20
name : saligia
age : 20
a = saligia
此处非模版
Press any key to continue
=============================
*/