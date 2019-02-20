# include <iostream>
# include <ctime>

int main (void)
{
	using namespace std;

	cout << "请输入要等待的秒数 : " << endl;

	int t;
	cin >> t;

	clock_t delay = t * CLOCKS_PER_SEC;
	cout << "starting ............\a\n";

	clock_t start = clock();
	while (clock () - start < t)
		;
	cout << "done  !!!!\a\n";

	return 0;
}