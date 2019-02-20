# include <iostream>
# include <fstream>
# include <cstdlib>

int main (void)
{
	using namespace std;

	int str[10];
	int ant;

	ifstream fin;
	ofstream fout;
	
	fout.open ("name.txt");  //将 fout 对象与 name.txt 联系起来

	cout << "请输入 10 个数据 :" << endl;

	for (int i = 1 ; i <= 8 ; i++)
		cin >> str[i-1];

	for (i = 1 ; i <= 8 ; i++)
	{
		fout << str[i-1];     // 而后 fout 相当于 ostream 中的 cout  只是对象为 文件 name .txt
		fout << endl;
	}

	fout.close();         // fout  属于 ofstream  但可使用 ostream 中的函数

	fin.open ("name.txt");

	fin >> ant;             // fin 属于 ifstream 使用方式跟 fout 方法类似  但它的输入对象为内存

	cout << ant << endl;
	fin.close();

	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
==============================
请输入 10 个数据 :
23
12
12
12
23
34
423
23
23
Press any key to continue
==============================
*/
