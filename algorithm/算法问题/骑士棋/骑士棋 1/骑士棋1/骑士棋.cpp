# include <iostream>
# include <cstring>
# include <iomanip>
# include <time.h>

void qi_shi(int (*p)[5] ,int*sum , int x, int y , int and= 1 );


int main()
{
	
	using std::cout;
	using std::cin;
	using std::endl;
	time_t btime, etime;	// 用来记录计算的时间
	btime = time(0);	// 记录初始时间
	int  x, y; // 用作迭代器
	int sum = 0;	// 记录总共有多少中走法
	int p[5][5]; // 用来存取数据
	int a, b;	// 记录起始位置
	
	

	memset(p, 0, sizeof(p));

	for (y = 0; y < 5; y++)
	{
		for (x = 0; x < 5; x++)
			cout << std::setw(2) << p[y][x];
		cout << endl;
	}
	cout << "请输入骑士棋的起点 : " << endl;
	cout << "请输入 x 坐标 : " << endl;
	cin >> a;
	cout << "请输入 y 坐标 ：" << endl;
	cin >> b;
	cout << endl << endl;

	p[b - 1][a - 1] = 1;
	qi_shi(p, &sum, a-1, b-1);
	etime = time(0);

	if (sum == 0)
		cout << "此处为死路 ， 没有一个结果 !!" << endl;
	else
		cout << "总共有 === " << sum << " === 种结果" << endl;
	cout << "总共用时 === " << etime-btime << " === 秒" << endl;

	system("pause");
	return 0;
}

void qi_shi(int(*p)[5],int*sum ,int x, int y, int and)
{
	using std::cout;
	using std::endl;
	int a, b;


	if (p[y][x] == 25)
	{
		for (b = 0; b < 5; b++)
		{
			for (a = 0; a < 5; a++)
				cout << std::setw(3) << p[b][a];
			cout << endl;
		}
		cout << endl;
		cout << "=====================================" << endl ;
		(*sum)++;
	}

	
	if ( y - 2 >= 0 && x - 1 >= 0 && p[y-2][x-1] == 0)
	{

		p[y-2][x-1] = and + 1;
		qi_shi(p ,sum , x - 1, y - 2 , and+1);
		p[y - 2][x - 1] = 0;
	}
		

	if ( y - 2 >= 0 && x + 1 < 5 && p[y - 2][x + 1] == 0)
	{
	
		p[y - 2][x + 1] = and + 1;
		qi_shi(p, sum, x + 1, y - 2, and + 1);
		p[y - 2][x + 1] = 0;
	}

	if ( y - 1 >= 0 && x - 2 >= 0 && p[y - 1][x - 2] == 0)
	{

		p[y - 1][x - 2] = and + 1;
		qi_shi(p, sum, x - 2, y - 1, and + 1);
		p[y - 1][x - 2] = 0;
	}

	if ( y - 1 >= 0 && x + 2 < 5 && p[y - 1][x + 2] == 0)
	{

		p[y - 1][x + 2] = and + 1;
		qi_shi(p, sum, x + 2, y - 1, and + 1);
		p[y - 1][x + 2] = 0;
	}

	if ( y + 1 < 5 && x + 2 < 5 && p[y + 1][x + 2] == 0)
	{

		p[y + 1][x + 2] = and + 1;
		qi_shi(p, sum, x + 2, y + 1, and + 1);
		p[y + 1][x + 2] = 0;
	}

	if ( y + 1 < 5 && x - 2 >= 0 && p[y + 1][x - 2] == 0)
	{

		p[y + 1][x - 2] = and + 1;
		qi_shi(p, sum, x - 2, y + 1, and + 1);
		p[y + 1][x - 2] = 0;
	}

	if ( y + 2 < 5 && x - 1 >= 0 && p[y + 2][x - 1] == 0)
	{

		p[y + 2][x - 1] = and + 1;
		qi_shi(p, sum, x - 1, y + 2, and + 1);
		p[y + 2][x - 1] = 0;
	}

	if ( y + 2 < 5 && x + 1 < 5 && p[y + 2][x + 1] == 0)
	{
	
		p[y + 2][x + 1] = and + 1;
		qi_shi(p, sum, x + 1, y + 2, and + 1);
		p[y + 2][x + 1] = 0;
	}

}
