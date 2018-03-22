# include <iostream>
# include <vector>

int main (void)
{
	using namespace std;

	cout << "请输入要创建的二维数组的大小 :\n";
	
	int n;
	cin >> n;

	vector <int *> str(n);

	for (int i = 1 ; i <= n ; i++)
		str[i-1] = (int *) malloc (sizeof(int) *n);

	int x , y;

	for (y = 1 ; y <= n ; y ++)
		for ( x = 1 ; x <= n ; x ++)
			cin >> str[y-1][x-1];
	cout << "===================================" << endl;

	for (y = 1 ; y <= n ; y ++)
	{
		for ( x = 1 ; x <= n ; x ++)
			cout << str [y-1][x-1]  << "  ";
		cout << endl;
	}
	cout << "===================================" << endl;

	cout << "str = " << &str << endl;
	cout << "===================================" << endl;
	for ( i = 1 ; i <= n ; i ++)
		printf ("str[%d] = %#X\n",i, &str[i]);
	cout << "===================================" << endl;


	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
=======================================
请输入要创建的二维数组的大小 :
3
1
2
3
4
5
6
7
8
9
===================================
1  2  3
4  5  6
7  8  9
===================================
str = 0012FF28
===================================
str[1] = 0X642DD4
str[2] = 0X642DD8
str[3] = 0X642DDC
===================================
Press any key to continue

=======================================
*/