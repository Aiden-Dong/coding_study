#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

ofstream fout("八皇后.txt",ios::out);

void eight_q(int(*p)[8], int *r, int *b ,int a = 0);

int main()
{
	

	int p[8][8] = { 0 };
	int Sum = 0;
	int one = 0;

	fout << "八皇后列举 : " << endl << endl;
	eight_q(p, &Sum , &one);

	fout << "八皇后总共有 :  " << Sum << "  种可能!!" << endl;
	fout << "八皇后总共计算 :  " << one << "  步" << endl;

	return 0;
}

void eight_q(int(*p)[8], int *r , int *b , int a)
{

	int q[8][8] = { 0 };		// 标记内存
	int x, y, i, j;

	(*b)++;
	if (a == 8)
	{
	
		(*r)++;
		for (y = 0; y < 8; y++)
		{
			for (x = 0; x < 8; x++)
			{
				if (p[y][x] == 1)
					fout << setw(2) << "●";
				else
					fout << setw(2) << "○";
			}
			fout << endl;
		}
		fout << endl << endl;
	}
	if (a < 8)
	{

		int num[8][8];

		for (y = 0; y < 8; y++)
		for (x = 0; x < 8; x++)
			num[y][x] = p[y][x];

		// ========最新数据的存储
		for (j = 0; j < 8; j++)
		for (i = 0; i < 8; i++)
		{
			if (num[j][i] == 1)
			{
				int s = j + i;
				int d = j - i;

				for (y = 0; y < 8; y++)
				for (x = 0; x < 8; x++)
				if (x == i || y == j || y - x == d || y + x == s)
					q[y][x] = 1;
			}

		}// ======================辅助内存的标记工作

		for (i = 0; i < 8; i++)
		{
			if (q[a][i] == 0)
			{
			
				num[a][i] = 1;
			eight_q(num, r, b , a + 1);
			num[a][i] = 0; // 回归
			}
		}
	}

}
