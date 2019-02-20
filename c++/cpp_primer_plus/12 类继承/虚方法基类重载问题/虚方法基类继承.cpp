# include <iostream>

class Base 
{
private:
	int a ; 
	double b ; 
	int c ;
public:
	Base (int x = 0  , double y = 0, int z = 0) : a (x) , b (y) , c (z) {}

	virtual double sum (int i) ;         // 将被隐藏  不能使用
	virtual double sum () ;
	int ram () {return a ;}
};

class Test : public Base
{
public:
	Test (int x = 0  , double y = 0, int z = 0) : Base (x, y, z){}

	virtual double sum ();               // 只重新定义了一个重载方法
};

double Base::sum (int i) 
{
	return (double)i /10 ;
}
double Base::sum ()
{
	return a + b + c ;
}

double Test::sum ()
{
	return 12.3 ;
}

int main ()
{
	using std::cout ;
	using std::endl ;

	Test kin (2.5) ;							// 会强制转化为 int 型
	
	Base & object  = kin ; 							

	cout << object.ram () << endl ;

	cout << object.Base::sum (34) << endl ;    // 此方法被隐藏  // 只能用此方法调用

	cout << object.sum () << endl ;

	cout << object.Base::sum () << endl ;

	return 0 ;
}
/*
在 VC++ 6.0 中的输出结果是 ：
============================
2
3.4
12.3
2
Press any key to continue
===========================
*/


