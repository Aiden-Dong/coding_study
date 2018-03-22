# include <iostream>
# include "name.h"

void call1 (Stringbad & s1);
void call2 (Stringbad s2);

int main ()
{
	using std::cout ;
	using std::endl ;
	{
		cout << "开始构造对象 : " << endl ;
		Stringbad one1 ("First word!!");
		Stringbad one2 = "Secound world !!!";  //  此处没有出错的原因是因为构造函数是复制了一个副本（对于 new 来说）
		Stringbad one3 ("Third world !!!");

		cout << "one1 = " << one1 ;
		cout << "one2 = " << one2 ;
		cout << "one3 = " << one3 ;


		call1 (one1);
		call2 (one3);
	}
	return 0;
}

void call1 (Stringbad & s1)
{
	std::cout << s1 ;
}

void call2 (Stringbad s2)
{
	std::cout << s2 ;
}
/*
在 VC++ 6.0 中的输出结果是 ：
===========================
开始构造对象 :
1产生了一个新的对象 :First word!!
2产生了一个新的对象 :Secound world !!!
3产生了一个新的对象 :Third world !!!
one1 = First word!!
one2 = Secound world !!!
one3 = Third world !!!
First word!!
Third world !!!
2释放掉一个空间 : Third world !!!
1释放掉一个空间 : 葺葺葺葺葺葺葺葺葺葺葺葺葺葺葺葺.
Press any key to continue
===========================
*/