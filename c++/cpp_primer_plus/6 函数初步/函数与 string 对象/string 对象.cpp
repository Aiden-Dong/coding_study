# include <iostream>
# include <string>

using namespace std;

void str_arry1 ( string * str);
void str_arry2 ( string *str);

int main ()
{
	

	string str[2];
	str_arry1(str);
	str_arry2(str);

	return 0;
}
void str_arry1 ( string * str)
{
	std::cout << "请输入两组字符串 :"<< std::endl;
	std::cin >> str[0];
	std::cin >> str[1];

}
void str_arry2 ( string *str)
{
	std::cout << str[0] << std::endl;
	std::cout << str[1] << std::endl;
	std::cout << sizeof(str[0]) << std::endl;
	std::cout << sizeof(str[1]) << std::endl;
	std::cout << str[0].size() << std::endl;
	std::cout << str[1].size() << std::endl;
}
/*
在 VC++ 6.0 中的输出结果是 ：
=============================
请输入两组字符串 :
hellow
world
hellow
world
16
16
6
5
Press any key to continue
=============================
*/