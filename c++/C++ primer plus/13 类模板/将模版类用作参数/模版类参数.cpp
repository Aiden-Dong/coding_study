# include <iostream>
# include "stack.h"

    // 只能将模版类用作参数 
class Carb									    	// 注意   这不是提供了模版 而是将模版类作为了参数
{						                            //声明出的--普通类
private:
	stack <int> s1 ;                                // 参数中  Thing 为参数模版 名
	stack <double> s2 ;
public:
	Carb() {}                                       // 调用类模板的构造函数
	void push (int a , double x){ s1.push(a);s2.push(x) ;}
	void pop (int & a , double & x ){ s1.pop(a);s2.pop(x) ;}
};

int main ()
{
	using std::cout ;
	using std::cin ;
	using std::endl ;
	
	Carb first ;
	return 0 ;
}