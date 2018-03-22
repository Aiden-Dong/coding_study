# include <iostream>

int main (void)
{
	using namespace std;

	bool is_ready;

	cout << "is_reade 的内存空间为 : " << sizeof (is_ready) << endl;
	cin >> is_ready;
	cout << "is_ready = " << is_ready << endl;

	return 0;
}