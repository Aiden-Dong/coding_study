# include <iostream>

int main (void)
{
	using namespace std;
	
	int * p;
	
	cout << "请输入要创建的数组 : " << endl;
	
	int n;
	cin >> n;
	cin.get ();
	
	p = new int [n][n];
	cout << "请输入 : " << endl;
	int r , i;
	for ( r = 0 ; r < n ; r ++)
		for ( i = 0 ; i < n ; i ++)
			cin >> p[r][i];
		
	for ( r = 0 ; r < n ; r ++)
	{	for ( i = 0 ; i < n ; i ++)
			cout << p[r][i] << " ";
		cout << endl;
	}
		
		return 0;
}