# include <iostream>

struct name {
	char str[10];
	int age;
	char date [40];
};

int main (void)
{
	using namespace std;

	name s[3];
	for ( int i = 0 ; i < 3 ; i ++ )
	{
		cout << "请输入姓名 :" << endl;
		cin.getline ( s[i].str , 10 );

		cout << "请输入年龄 :";
		cin >> s[i].age ;
		cin.get ();

		cout << "请填写备注 : " << endl;
		cin.getline ( s[i].date , 40 );
	}

	cout <<  endl;

	for ( i = 0 ; i < 3 ; i ++ )
	{
		cout << s[i].str << endl;
		cout << s[i].age << endl;
		cout << s[i].date << endl;
		cout <<  endl;
	}
	

	const name *arp[3] = { &s[0] , &s[1] , &s[2] };
	
	const name **ppa = arp;
	//auto ppb = arp;              // c++ 11 定义

	cout << (*ppa) ->date  << endl;
	//cout << (*(ppb+1)) -> date << endl;

	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
===========================
请输入姓名 :
saligia
请输入年龄 :20
请填写备注 :
perfect and very good!!!!
请输入姓名 :
clifdsh
请输入年龄 :20
请填写备注 :
平常 一般般 。。。。。。。
请输入姓名 :
sdlhfa
请输入年龄 :20
请填写备注 :
蠢货一只 不思进取！！！！！

saligia
20
perfect and very good!!!!

clifdsh
20
平常 一般般 。。。。。。。

sdlhfa
20
蠢货一只 不思进取！！！！！

perfect and very good!!!!
Press any key to continue
===========================
*/