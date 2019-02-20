# include <iostream>
# include "nameig.h"
# include <windows.h>
# include <ctime>
# include <fstream>

int main ()
{
	using namespace std;
	
	int a;
	Pcard news;
	char str[15];
	ofstream fout;
	
	fout.open ("数据汇总.txt");


	student student0;
	while (1)
	{
	
		cout << "请选择 :" << endl;
		cout << "1. 加入新名单 : "<< endl ;
		cout << "2. 删除名单 :" << endl ;
		cout << "3. 显示名单 :" << endl ;
		
		
		cin >> a ;
		system ("cls");
		
		switch (a)
		{
		case 1:
			
			news = new Card;
			student0.z_zhan  (news);
			break;
		case 2:
			cout << "请输入要删除的对象名称 : " << endl;
			cin >> str ;
			student0.j_zhan  (str);  // 出现错误
			break;
		case 3:
			cout << "1. 打印 " << endl;
			cout << "否则.在显示屏上显示" << endl;
			cin >> a ;
			if (a == 1)
				fout << student0;
			else
				cout << student0;

			break;
		default:
			cout << "输入有误 , 重新输入 : " << endl;
			if (!cin )
			{
				cin.clear ();
				while (cin.get () != '\n');
			}
	
			
			
		}
		
	}


	
	return 0;
} 
