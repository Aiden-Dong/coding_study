# include <iostream>
# include <string>
# include "work.h"

using std::cout ;
using std::cin ;
using std::endl;
using std::string;


void worker::Date () const
{
	cout << "姓名 : " << fullname << endl ;
	cout << "ID : " << id << endl ;
}

void worker::Get ()
{
	cout << "请输入姓名 : " << endl ;
	cin >> fullname ;

	cout << "请输入你的 ID : " << endl ;
	cin >> id ;
}

void waiter::Date () const 
{
	cout << "panache : " << panache << endl ;
}
void waiter::Get ()
{
	cout << "请输入你的 panache " << endl ;
	cin >> panache ;
}
void waiter::set ()
{
	worker::Get ();
	Get();
}
void waiter::show () const
{
	worker::Date ();
	Date();
}

char *singer::pv[singer::Vt] = {"other" , "alto" , "contualto" , "aoprato" , "bass" , "baritual" , "tenor"} ;  
							            	// 声明时 需使用作用域解析运算符 调用 静态变量 ， 注意不可调用普通变量

void singer::set ()
{
	worker::Get ();
	Get();
}
void singer::show () const
{
	worker::Date ();
	Date();
}

void singer::Date () const 
{
	cout << "选项 : " << pv[voice] << endl ;
}
void singer::Get ()
{
	cout << "请随便选择一组数据 : " << endl ;
	cin >> voice ;
}

void singwaiter::Get ()
{
	worker::Get () ;
	singer::Get () ;
}
void singwaiter::show () const
{
	worker::Date ();
	Date () ;
} 
void singwaiter::set ()
{
	worker::Get () ;
	Get();
}

void singwaiter::Date () const 
{
	worker::Date () ;
	singer::Date () ;
}