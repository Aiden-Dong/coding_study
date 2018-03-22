# include <iostream>

void a (int i) ;
void b (int j) ;

int main ()
{
	using namespace std ;

	int i ;

	cin >> i ;

	try {
		a(i);
	}
	catch (int j) // 说明 如果在下一层栈中找不到这个 找不到这个异常捕获则去上一层寻求捕获
	{
		cout << "errror to input !" << endl ;
		cout << j << endl ;
	}

	return 0 ;
}
void a (int i ) 
{
	try {
		b (i) ;
	}
	catch (char a) 
	{
		std::cout << "sorry !!" <<std::endl ;
		std::cout << a << std::endl ;
	}
	std::cout << "saligia !!" << std::endl ;
}
void b (int j) 
{
	if (j == 1)
		throw 90 ;
}
/*
在 VC++6.0 的运行环境中 :
=========================
1
errror to input !
90
Press any key to continue
==========================
*/
