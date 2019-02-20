# include <iostream>

using namespace std;

struct student{
	char name[20];
	int date;
	int age;
};
int main (void)
{
	student mode[2];
	int r;
	
	for ( r = 0 ; r < 2 ; r++)
	{
		cout << "请输入姓名 :" << endl;
		cin.getline ( mode[r].name , 20 );
		
		cout << "请输入出生 : " << endl;
		cin >> mode[r].date;

		cin.get ();

		mode[r].age = 2014 -mode[r].date;

	}

	for ( r = 0 ; r < 2 ; r++)
	{
		cout << mode[r].name << endl;
		cout << mode[r].date << endl;
		cout << mode[r].age << endl;
		cout << endl << endl;
	}
	
	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
==========================
请输入姓名 :
Jim aime
请输入出生 :
1994
请输入姓名 :
Sum husl
请输入出生 :
1984
Jim aime
1994
20


Sum husl
1984
30


Press any key to continue
===========================
*/