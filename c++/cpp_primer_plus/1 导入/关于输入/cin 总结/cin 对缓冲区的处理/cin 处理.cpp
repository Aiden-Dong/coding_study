# include <iostream>

int main (void)
{
	using namespace std;
	
	char ch , a[20] , b [10];

	cout <<"请输入 :" <<endl;

	cin.get ( a , 5 );   //--------------------当输入超出范围 则将剩下的留在 缓冲区（流） 内，只读取 n-1 个字符;
	//cin.getline ( b , 5);  //   -------------当输入超出范围 ， 只读取 n-1 个字符，并停止后面的输入函数运行;
                                               //解决办法 : cin.clear ();   
	cin >> ch;

	cout << "a = " << a << endl;
	cout << ch <<endl;
	cout << (int) ch <<endl;
	
	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
============================
请输入 :
hellow
a = hell
o
111
Press any key to continue
===========================
*/
