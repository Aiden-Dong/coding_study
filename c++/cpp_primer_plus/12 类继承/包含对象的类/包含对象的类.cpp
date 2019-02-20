# include <iostream>
# include <string>

using std::string ;
using std::cout ;
using std::endl ;

class Test 
{
private:
	string name ;
public:
	Test (const char * s ) {name = s ;}              // 对类对象可以不使用初始化列表
	void show ()const {cout << "name = " << name << endl ;}
};

int main ()
{
	Test first ("jin");

	first.show () ;

	return 0;
} 
/*
在 VC++ 6.0 中的输出结果是 ：
===========================
name = jin
Press any key to continue
===========================
*/