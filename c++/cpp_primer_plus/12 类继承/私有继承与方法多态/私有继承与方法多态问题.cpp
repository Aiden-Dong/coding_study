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
class One : private Base					// 代码代码对于彼此在封闭式的基础上建立开放关系
{	
private:
	int a ;                                                            // 可以定义相同的标志符
public:
	One (int x = 0 , int y = 0 , double z = 0) : a(x) , Base (y , z) {}
	int term1 () {return a ;}
	double sum () {return term1() + Base::term1 () + term2 () ;}        //  私有继承与共有继承对派生类本身来说 无影响
	Base & Num (){return ( Base &) *this ;}							//  可以通过强制类型转换来访问基类
};

int main ()
{
	using std::cout ;
	using std::endl ;

	One example ( 1 , 2 , 3.3 );

	cout << example.Num ().term2 () << endl ;	// 从外部调用 私有继承部分的方法 !!!

//	(Base & ) example.term2  ();				// 不能在派生类外引用
	
	cout << "term1 = " << example.term1()  << endl ;


	cout << "sum = " << example.sum () << endl ;
	
	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
===========================
3.3
term1 = 1
sum = 6.3
Press any key to continue
===========================
*/