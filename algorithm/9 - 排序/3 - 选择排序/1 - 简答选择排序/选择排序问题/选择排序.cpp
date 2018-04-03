# include <iostream>
# include <iomanip>
# include <ctime>

//============================选择排序======================================================= 

int main()
{
	using std::cout;
	using std::time;
	using std::endl;
	

	int a[10];
	time_t in;
	srand((unsigned int)time(&in));
	for (int i = 0; i < 10; i++)
	{
		a[i] =100+rand()%100;	// 生成从100到200的随机数
		cout << std::setw(4) << a[i];
	}
	cout << endl;

	int X = 0;
/*                                
	for (int i = 0; i < 10; i++)	// 核心算法问题
	{								// 查找最大值
		if (a[i] > a[X])
			X = i;
	}
*/

	cout << endl << "排序过程 : " << endl;

	for (int i = 0; i < 10; i++)
	{
		int min = i ;
		for (int j = i + 1; j < 10; j++) // 此法为向前标记法
		{
			if (a[min] > a[j])
				min = j;		//标记最小值
		}
		if (i != min)
		{
			int t;
			t = a[min];
			a[min] = a[i];
			a[i] = t;
		}

		for (int k = 0; k < 10; k++)
			cout << std::setw(4) << a[k];
		cout << endl;
	}
	cout << "排序后 : " << endl;


	for (int i = 0; i < 10; i++)
		cout << std::setw(4) << a[i] ;
	cout << endl;
	

	system("pause");
	return 0;
}