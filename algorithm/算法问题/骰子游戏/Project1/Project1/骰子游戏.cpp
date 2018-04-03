# include <iostream>
# include <ctime>
# include <cstdlib>
# include <windows.h>

using std::endl;
using std::cout;


enum Test { WON, LOST, CONTINUE };   // 用于存取游戏状态

class Dice 
{
private:

	Test gameStatus;  // 记录状态的情况
	int Sum;	// 记录第一次两个结果的总和
public:
	Dice();// 初始化状态
	Test dice_game();// 游戏具体的状态
	int dice_result(); // 制造 1-6的随机数 
	~Dice();
};

Dice::Dice() :gameStatus(CONTINUE), Sum(0)
{}

Test Dice::dice_game()
{
	int a, b;
	int Sum1;// 用来记录 CONTINUE 的情况

	a = dice_result();
	cout << "第一次投骰子的结果为 : " << a << endl;
	b = dice_result();
	cout << "第二次投骰子的结果为 : " << b << endl;

	Sum = a + b;

	cout << "总结果为 : " << Sum << endl;
	if (Sum == 7 || Sum == 11)
		gameStatus = WON;
	else if (Sum == 2 || Sum == 3 || Sum == 12)
		gameStatus = LOST;
	else
	for (int i = 0; i < 7; i++)
	{
		cout << "请继续 你还有 " << 7 - i << " 次机会 : " << endl;
		getchar();
		a = dice_result();
		cout << "第一次投骰子的结果为 : " << a << endl;
		b = dice_result();
		cout << "第二次投骰子的结果为 : " << b << endl;
		Sum1 = a + b;
		if (Sum == Sum1) // 当与第一次总和相同
		{
			gameStatus = WON;
			break;
		}
	}

	return gameStatus;
}

int Dice::dice_result()
{
	srand((unsigned)time(0));
	Sleep(1000);
	int a = rand() % 6 + 1;
	return a;
}

Dice::~Dice()
{
	cout << "Bybe......." << endl;
}


int main()
{
	Test Game;
	cout << "游戏开始" << endl;

	Dice one;

	Game = one.dice_game();  // 调出状态 并显示输赢

	if (Game == WON)
		cout << "You Win!!!" << endl;
	else
		cout << "You Fail!!!" << endl;

	return 0;
}