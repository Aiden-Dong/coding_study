# include <iostream>
# include <memory>

int main ()
{
	using namespace std ;


	string str1("hellow , world") ;

	auto_ptr<string> p1= auto_ptr<string> (new string ("hellow world") );

			// 智能指针主要是用在 栈解退时候  自动释放动态内存 


	cout << * p1 << endl ;

	return 0;
}