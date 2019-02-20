# include <iostream>
# include "name.h"

int main ()
{
	using std::cout ;
	using std::endl ;

	stock popins(9 , 2.8);
	double p_t = popins;            // 当存在多个转换方式时 应该与类型相对应  （不可类型转换的暂不考虑） 

//	long ar = popins;              // 由于存在 int 跟 double 两种转换方式所以编译器不进行揣测到底使用
								   // 哪种方式

	cout << "p_t = " << p_t << endl ;
	cout << "popins = " << popins.show_stn  << endl;

	popins = 23;                // 类型转换

	double New = popins + 24 ;           // 由于存在 友元函数 跟 转换函数 具有二义性 (3种转换方式) 

	cout << "points = " <<int (popins) << endl;    // 二义性问题

	return 0;
}