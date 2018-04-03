# include <iostream>

const int Q = 12;

int combi (int r , int n);

int main ()
{
	using namespace std ;

	int y , x , i ;
	int sum ;



	for (y = 0 ; y <= Q ; y++)
	{
		for (i = 1 ; i <= Q - y ; i++)
			cout << "   " ;
		for (x = 0 ; x <= y ; x++)
		{
			sum = combi (x , y);

			if (sum < 10 )
				cout << " " << sum << " ";

			else if (sum <100 && sum >= 10 )
				cout << sum/10 << " " << sum%10 ;

			else 
				cout << sum ; 

			cout << "   ";
		}
		cout << endl ;
	}

	getchar();

	return 0;
}

int combi (int r , int n )
{
	int i;
	int p=1;
	for(i=1;i<=r;i++)
	{
	p=p*(n-i+1)/i;//这里没有采用斯巴卡三角形的特性，即下数等于上面两数之和，而是通过行列的关系推出。
	}
	return p;
}