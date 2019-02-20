# include <iostream>

class Base
{
private:
	int a ; 
	double b ;
public:
	Base (int x = 0 , double y = 0 ) : a(x) , b(y) {}
	int term1 () {return a;}
	double term2 () {return b ;}
};
									// 从某种程度上来说 ， 派生类与基类是采取了一种 相对彼此半封闭式的链接关系
class One : private Base				// 代码代码对于彼此在封闭式的基础上建立开放关系
{
private:
	int a ;                                                            // 可以定义相同的标志符
public:
	One (int x = 0 , int y = 0 , double z = 0) : a(x) , Base (y , z) {}
	int term1 () {return a ;}
	double sum () {return term1() + Base::term1 () + term2 () ;}
};

int main ()
{
	using std::cout ;
	using std::endl ;

	One example ( 1 , 2 , 3.3 );
	
	cout << "term1 = " << example.term1()  << endl ;
	cout << "term2 = " << example.term2() << endl ;

	cout << "term1 = " <<example.Base::term1 () << endl ;  // 基类方法并未被消去掉
	cout << "sum = " << example.sum () << endl ;
	
	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
=============================
term1 = 1
term2 = 3.3
term1 = 2
sum = 6.3
Press any key to continue
=============================
*/