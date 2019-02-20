# include <iostream>

void hanno (int n , char A , char B , char C);

int main ()
{
	using namespace std;
	int n;
	char ch1= 'A', ch2 = 'B',ch3 = 'C';

	cout << "请输入总盘数 :" << endl;

	cin >> n;

	hanno (n , ch1 , ch2 , ch3);

	return 0;
}
void hanno (int n , char A , char B , char C)
{
	using namespace std;

	if (n == 1)
		cout << "编号 : " << n << "    " << A <<" -> "<< C << endl;
	else
	{
		hanno (n-1 ,A , C , B);
		cout << "编号 : " << n << "    " << A <<" -> "<< C << endl;
		hanno (n-1 , B , A , C);
	}

}