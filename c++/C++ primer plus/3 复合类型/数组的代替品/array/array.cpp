# include <iostream>
//# include <array>

int main (void)
{
	array <int * , 3> arr;

	for (i = 1 ; i <= 3; i++)
		arr[i-1] = new int [3];
	int x, y;

	for (y = 1 ; y <= 3 ; y ++)
		for (x = 1 ; x <= 3 ; x ++)
			cin >> arr[y-1][x-1];

	cout << "=========================================" << endl;

	for (y = 1 ; y <= 3 ; y ++)
	{
		for (x = 1 ; x <= 3 ; x ++)
			cout >> arr[y-1][x-1];
		cout << endl;
	}

	cout << "=========================================" << endl;

	cout << " arr = " << &arr;

	return 0;
}