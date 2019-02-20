# include <iostream>

void test () ;

int main ()
{
	using std::cout ;
	using std::endl ;

	test () ;

	return 0 ;

}
void test ()
{
	try {
		throw 23 ;
	}
	catch (int a)
	{
		std::cout << "出现异常现象" << std::endl ;
		std::cout << a << std::endl ;
	}
	std::cout << "并未有栈解退现象 " << std::endl ;
}
/*
在 VC++6.0 的运行环境中 :
=============================
出现异常现象
23
并未有栈解退现象
Press any key to continue
=============================
*/
