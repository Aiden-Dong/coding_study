# include <iostream>
# include <ctime>

void sort (int * p , int n);

int main ()
{
	using namespace std ;

	int * p = new int [20];

	for (int i = 0 ; i < 20 ; i++)
		p[i] = rand()%3;


	cout <<"============================================"<< endl;
	for ( i = 0 ; i < 20 ; i++)
		cout << p[i] ;
	cout << endl <<"============================================"<< endl ;

	sort (p , 20);

	cout <<"============================================"<< endl;
	for ( i = 0 ; i < 20 ; i++)
		cout << p[i] ;
	cout << endl <<"============================================"<< endl ;


	return 0 ;
}
void sort (int * p , int n)
{
	int x ;
	int t ;
	for (int i = 0 ; i < n ; i++)
	{
		
		while (1)
		{
			if(p[i] == 0)
			{
				for (x = 0 ; x < i ; x++)
					if (p[x] != 0)
					{
						t = p[i] ; 
						p[i] = p[x];
						p[x] = t;
						break ;
					}
			}
			 if (p[i] == 2)
			{
				for (x = n-1 ; x > i ; x--)
					if (p[x] != 2)
					{
						t = p[x];
						p[x] = p[i];
						p[i] = t ;
						break;
					}
			}
			else
				 break;

			if (x == i)
				break ;

		}
	}

}