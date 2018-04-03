# include <iostream>
#include <stdlib.h>
# include <fstream>
# include <windows.h>
# include <ctime>

void gotoxy(int a, int b);
void zhibiao(int n);
void number_game(int(*p)[9], int(*q)[9] , long long * sum, int x = 0, int y = 1);

int main()
{
	using std::cout;
	using std::endl;
	using std::ifstream;
	using std::ios_base;

	time_t time1 = std::time(0);

	ifstream fin("E:/计算机编程/7 - 数据结构/算法问题/数独问题/数独原始数据.txt", ios_base::in);

	if (!fin.is_open())
	{
		cout << "error to open it" << endl;
		system("pause");
		exit(-1);
	}

	long long sum = 0;
	int p[9][9];

	int  x, y;
	int i;

	for (y = 0; y < 9; y++)
	for (x = 0; x < 9; x++)
		fin >> p[y][x];
	// 此处为数独的判读做记录 ， 记录所有可插电位置  

	cout << "数独的初始数据为 : " << endl;
	zhibiao(18);

	for (y = 0; y < 9; y++)
	for (x = 0; x < 9; x++)
	{
		gotoxy(4 * x + 2, 2 * y + 2);
		if (p[y][x] != 0)
			cout << p[y][x];
	}

	cout << endl << endl << endl;
	//打印出原始数据 
	number_game(p , p, &sum);
	time_t time2 = std::time(0);
	cout << "经过 ==== " << sum << " ====  次运算 后" << endl << endl;
	cout << " 经过 == == "<< time2-time1 <<"  == == 秒后" << endl;
	zhibiao(18);

	for (int y = 0; y < 9; y++)
	for (int x = 0; x < 9; x++)
	{
		gotoxy(4 * x + 2, 2 * y + 25);
		if (p[y][x] != 0)
			cout << p[y][x];
	}



	getchar();
	return 0;
}
void gotoxy(int a, int b)                         //================坐标函数
{
	HANDLE hOutput;

	COORD loc;
	loc.X = a, loc.Y = b;

	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(hOutput, loc);

}
void zhibiao(int n)                  //=================  制表函数
{
	int x, y;
	for (y = 0; y <= n; y++)
	for (x = 0; x <= n; x++)
	{
		if (y == 0)
		{
			if (x == 0)
				printf("┏");
			else if (x == n)
				printf("┓");
			else if (x % 2 == 1)
				printf("━");
			else if (x % 2 == 0)
				printf("┯");
		}
		else if (y == n)
		{
			if (x == 0)
				printf("┗");
			else if (x == n)
				printf("┛");
			else if (x % 2 == 1)
				printf("━");
			else if (x % 2 == 0)
				printf("┷");
		}
		else if (y % 2 == 1)
		{
			if (x == 0)
				printf("┃");
			else if (x == n)
				printf("┃");
			else if (x % 2 == 1)
				printf("  ");
			else if (x % 2 == 0)
				printf("│");
		}
		else if (y % 2 == 0)
		{
			if (x == 0)
				printf("┠");
			else if (x == n)
				printf("┨");
			else if (x % 2 == 1)
				printf("─");
			else if (x % 2 == 0)
				printf("┼");
		}

		if (x == n)
			printf("\n");
	}
}

/*	 r 为记录 数独空间的指针 ， q 为进行 运算的空间区 ， sum 代表这经历过的运算次数
x 代表这每一个数字的每一列写入的过程 ， y 代表写入的数字
*/
void number_game(int(*p)[9],int(*q)[9], long long * sum, int x, int y)
{

	int i, j;
	int a, b;
	static int r1 = 0;

	if (x == 9)
	{
		x = 0;
		y++;
	}

		if (y == 10)
		{
			for (j = 0; j < 9; j++)
			for (i = 0; i < 9; i++)
				q[j][i] = p[j][i];

			r1 = 1;
		}


	if (r1 == 0)
	{

		int num[9][9];

		for (b = 0; b < 9; b++)
		for (a = 0; a < 9; a++)
			num[b][a] = p[b][a];

		// 因为需要遇到后面错误时的递回问题 ， 所以要分派新的局部变量 ， 使得递回到此处时 ， 原始空间没有发生变化



		// 为每一次的递回处理好 行数跟填充数据的关系 

		int g[9][9] = { 0 };// 为标记做准备

		// 以下进入对应特定行 ， 特定数字的运算 

		for (b = 0; b < 9; b++)		
		for (a = 0; a < 9; a++)// 这里是进行每一个内存空间的测试  （对 num 的测试）
		{
			if (num[b][a] == y)  // 就是说 如果这个 数独矩阵中有我们要填充的数字 ， 标记
			{
				for (j = 0; j < 9; j++)
				for (i = 0; i < 9; i++)
				{
					if (j == b || i == a)
						g[j][i] = y;	// 标记的第一步
				}

				if (b < 3)
				{
					if (a < 3)
					{
						for (j = 0; j < 3; j++)
						for (i = 0; i < 3; i++)
							g[j][i] = y;
					}
					else if (a < 6)
					{
						for (j = 0; j < 3; j++)
						for (i = 3; i < 6; i++)
							g[j][i] = y;
					}
					else
					{
						for (j = 0; j < 3; j++)
						for (i = 6; i < 9; i++)
							g[j][i] = y;
					}
				}
				else if (b < 6)
				{
					if (a < 3)
					{
						for (j = 3; j < 6; j++)
						for (i = 0; i < 3; i++)
							g[j][i] = y;
					}
					else if (a < 6)
					{
						for (j = 3; j < 6; j++)
						for (i = 3; i < 6; i++)
							g[j][i] = y;
					}
					else
					{
						for (j = 3; j < 6; j++)
						for (i = 6; i < 9; i++)
							g[j][i] = y;
					}
				}
				else
				{
					if (a < 3)
					{
						for (j = 6; j < 9; j++)
						for (i = 0; i < 3; i++)
							g[j][i] = y;
					}
					else if (a < 6)
					{
						for (j = 6; j < 9; j++)
						for (i = 3; i < 6; i++)
							g[j][i] = y;
					}
					else
					{
						for (j = 6; j < 9; j++)
						for (i = 6; i < 9; i++)
							g[j][i] = y;
					}
				}
			} // 标记第二部 
		// 在此处添加标记   // ======  此处用来检测 辅助数组中的数据变化 即标记的情况====
		

		}  // 标记完成  

		int k = 0; // 记录此列中的情况 为整体的递回考虑
		for (i = 0; i < 9; i++)
		if (num[x][i] == y && r1 == 0)
		{
			(*sum)++;
			k = 1;	// 表明此列中已有一个数据 ， 不必在进行查找
			number_game(num,q, sum, x + 1, y);	// 检查此列中是否已有此数据
		}


		if (k == 0) // 表示此列中没有此数据 , 要进行查找
		{
			for (i = 0; i < 9; i++)
			{
				if (g[x][i] == 0 && num[x][i] == 0 && r1 == 0) // 表明此地方无同行同列数据
				{
					(*sum)++;
					num[x][i] = y;
					number_game(num,q, sum, x + 1, y);
					num[x][i] = 0;	// 回归  为下次递归做准备
				}
			}
		}
	}
}
