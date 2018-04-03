# include <iostream>
# include <ctime>
# include <iomanip>

# define M 10

int main()
{
	using std::cout;
	using std::endl;
	int a[M];

	srand((unsigned)time(NULL));
	cout << "生成随机数 : " << endl;

	for (int i = 0; i < M; i++)
	{
		a[i] = 100 + rand() % 100;
		cout << std::setw(4) << a[i];
	}
	cout << endl;
	cout << endl << "排序过程 ：" << endl;
	for (int i = 0; i < M - 1; i++)
	{
		for (int j = 0; j < M - i - 1; j++)
		{
			if (a[j]> a[j + 1])
			{
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
		for (int k = 0; k < M; k++)
			cout << std::setw(4) << a[k];
		cout << endl;
	}

	cout << endl << "排序完成后 : " << endl;
	for (int i = 0; i < M; i++)
		cout << std::setw(4) << a[i];
	cout << endl;

	system("pause");
	return 0;
}