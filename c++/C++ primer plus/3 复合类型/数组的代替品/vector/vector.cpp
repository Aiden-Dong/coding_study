# include <iostream>
# include <vector>
int main (void)
{
	using namespace std;

	vector <int>a (2); //只能建立一维式数组

	for (int r = 0 ; r < 2 ; r ++)
	{
		cout << "请输入 ：" << endl;
		cin >> a[r];
	}

	for ( r = 0 ; r < 2 ; r ++)
	{
		cout << "a[" << r << "] = " << a[r] << endl;
	}

	

	return 0;
}
/*
在 VC++ 6.0 中的输出结果是 ：
============================
请输入 ：
23
请输入 ：
45
a[0] = 23
a[1] = 45
Press any key to continue
============================
*/

