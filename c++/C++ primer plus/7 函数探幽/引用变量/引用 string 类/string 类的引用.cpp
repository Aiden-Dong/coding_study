# include <iostream>
# include <string>

using namespace std;
void card1 (const string &name , const string &ad , const string &eag);

int main ()
{
	

	string name , ID , eag;

	cout << "请输入你的姓名 :" << endl;

	cin >> name;

	cout << "请输入你的学号 : " << endl;

	cin >> ID;

	cout << "请输入你的年龄 : " << endl;

	cin >> eag;

	card1 ( name , ID , eag );

	return 0;
}
void card1 (const string &name , const string &ID, const string &eag)
{
	using std::cout;
	using std::endl;

    cout <<"======= ID card============"<< endl;
	cout << "姓名 : " << name << endl;
	cout << "学号 : " << ID << endl;
	cout << "年龄 : " << eag << endl;
}
/*
在 VC++ 6.0 中的输出结果是 ：
============================
请输入你的姓名 :
saligia
请输入你的学号 :
2013201890
请输入你的年龄 :
20
======= ID card============
姓名 : saligia
学号 : 2013201890
年龄 : 20
Press any key to continue
============================
*/