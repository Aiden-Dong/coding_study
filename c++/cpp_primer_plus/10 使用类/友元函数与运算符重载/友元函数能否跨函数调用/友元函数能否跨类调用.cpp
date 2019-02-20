# include <iostream>

class One
{
private:
	int a ;
public:
	One (int x = 0):a(x){}	
	int ture () {return a ;}
};

class two
{
private :
	int b ;
public:
	two (int x = 0):b(x){}
	friend std::ostream operator<< (std::ostream & os , two & b) ;
	friend int fable (One & a  , two & b)
	{
		return a.ture () +b.b ;                 // 友元函数不能跨类调用 私有成员  只能调用本类私有成员即其他类接口         
	}
};
std::ostream operator<< (std::ostream & os , two & b)
{
	os << b.b << std::endl ;
	return os ;
}



int main ()
{
	using std::cout ; 
	using std::endl ;

	One a (12) ;
	two b (3) ;
	two c ;

	c = fable (a , b);


	//cout<< a  << " " << b << " " << c << endl ;

	//c = a+b ; 
	cout << "c = " << c << endl;

	return 0 ;
}
/*
在 VC++ 6.0 中的输出结果是 ：
===============================
 3 0
c = 0
Press any key to continue
==============================
*/