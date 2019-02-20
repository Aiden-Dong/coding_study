# include <iostream>

int main (void)
{
	using namespace std;

	char str1[10] , str2[10] , ch1, ch2,ch3,ch4;
	int t;

	cout << "请输入 :"<<endl;
	cin >> t;
	cout <<"t = " << t <<endl;
	
	cout << "请输入 :" << endl;
	cin.get (ch2);
	cout << "ch2 = "<< int (ch2) <<endl;

	cout << "请输入 :"<<endl;
	cin >>ch1;
	cout << "ch = " << int (ch1) <<endl;

	cout << "请输入 :" << endl;
	cin.get (ch3);
	cout << "ch3 = "<< int (ch3) <<endl;

	cout << "请输入 :" << endl;
	cin.get (ch4);
	cout << "ch4 = "<< int (ch4) <<endl;

	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
=============================
请输入 :
12
t = 12
请输入 :
ch2 = 10
请输入 :
asaws
ch = 97
请输入 :
ch3 = 115
请输入 :
ch4 = 97
Press any key to continue
=============================
*/