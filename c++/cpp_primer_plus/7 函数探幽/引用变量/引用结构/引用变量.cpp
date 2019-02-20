# include <iostream>

struct name {
	char str[20];
	char name1[20];
};

void srt_pc ( name &a );

int main ()
{
	name a;

	srt_pc (a);

	std::cout << "姓名 : " << a.str <<std::endl;
	std::cout << "学号 : " << a.name1 << std::endl;

	return 0;
}
void srt_pc ( name &a )           //变量引用  节省内存
{
	using namespace std;

	cout << "请输入姓名 :" << endl;

	cin >> a.str;

	cout << "请输入学号 :" << endl;

	cin >> a.name1;
}
/*
在 VC++ 6.0 中的输出结果是 ：
============================
请输入姓名 :
saligia
请输入学号 :
2013201890
姓名 : saligia
学号 : 2013201890
Press any key to continue
============================
*/
