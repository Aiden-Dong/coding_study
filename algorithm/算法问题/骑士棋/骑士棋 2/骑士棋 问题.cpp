# include <iostream>
# include <windows.h>

typedef struct QI_PAN {
	int x ;
	int y ; 
}QI ,* PQI ;

int qi_shi (int **q , PQI p , int and , int x , int y , int &r , int t);
void gotoxy ( int a , int b ) ;
void zhibiao ( int n ) ;

int main ()
{
	using std::cout;
	using std::cin;
	using std::endl;
	int i = 0 ; 
	int y = 0 ;
	int x = 0 ;
	int and = 0;
	int sum = 0 ;
	int r = 0;
	int t = 0 ;

	cout << "请输入要求的方阵数目 : " << endl ;

	cin >> t ;

	system("cls");

	

	int ** q = new int * [t];

	for (i = 0 ; i < t ; i++)
		q[i] = new int [t] ;

	for (y = 0 ; y < t ; y ++)
		for (x = 0 ; x < t ; x++)
			q[y][x] = 0;

               // 全部初始化为 0 ； 

	PQI p = new QI [t*t] ;

	for (i = 0 ; i <t*t ; i++)
		p[i].x = p[i].y  = 0;

	zhibiao (2*t);
	for (y = 0 ; y < t ; y ++)
		for (x = 0 ; x < t ; x++)
		{
			r = 0 ;
			sum = qi_shi (q , p , and , x, y , r , t);
			gotoxy (4*x+2, 2*y+1);
			cout << sum ;
		}



	gotoxy (1 , 15 );	
	
	getchar();

	delete [] p;

	delete [] q ;

	
	return 0;
}

int qi_shi (int **w , PQI p , int and , int x , int y , int & r , int t)
{
	using std::cout;
	using std::endl ;
	int a , b;

	int ** q  = new int *[t];
	for (b = 0 ; b < t ; b++)
		q[b] = new int [t];



	for (b = 0 ; b < t ; b++)
		for (a = 0 ; a < t ; a++)
			q[b][a] = w[b][a];

	q[y][x] = 1 ;  // 表示已经走过的点
	p[and].x = x , p[and].y = y ; // 记录已走过的路径

	and ++ ;

//	cout << and << endl ;

	if( and == t*t )
	{
		r = 1 ;
	}

	if (r == 0 && y-2 >= 0 && x-1 >= 0 && q[y-2][x-1] == 0 )
		qi_shi (q , p , and , x-1 , y-2 , r , t);

	if (r == 0 && y-2 >= 0 && x+1 < t && q[y-2][x+1] == 0 )
		qi_shi (q , p , and , x+1 , y-2 , r , t);

	if (r == 0 && y-1 >= 0 && x-2 >= 0 && q[y-1][x-2] == 0 )
		qi_shi (q , p , and , x-2 , y-1 , r , t);

	if (r == 0 && y-1 >= 0 && x+2 < t && q[y-1][x+2] == 0 )
		qi_shi (q , p , and , x+2 , y-1 , r , t);

	if (r == 0 && y+1 < t && x+2 < t && q[y+1][x+2] == 0 )
		qi_shi (q , p , and , x+2 , y+1 , r , t);

	if (r == 0 && y+1 < t && x-2 >= 0 && q[y+1][x-2] == 0 )
		qi_shi (q , p , and , x-2 , y+1 , r , t);

	if (r == 0 && y+2 < t && x-1 >= 0 && q[y+2][x-1] == 0)
		qi_shi (q , p , and , x-1 , y+2 , r , t);

	if (r == 0 && y+2 < t && x+1 < t && q[y+2][x+1] == 0 )
		qi_shi (q , p , and , x+1 , y+2 , r , t);

	for (b = 0 ; b < t ; b++)
		delete[] q[b] ;
	delete [] q;

	return r;


}
void gotoxy ( int a , int b )                       
{
	HANDLE hOutput;
	
	COORD loc;
	loc.X = a , loc.Y = b;
	
	hOutput = GetStdHandle (STD_OUTPUT_HANDLE);
	
	SetConsoleCursorPosition (hOutput,loc);
	
}
void zhibiao ( int n )                  //=================  制表函数
{
	int x , y;
	for ( y = 0 ; y <= n ; y++)
		for (x= 0 ; x <= n ; x++)
		{
			if (y == 0)
			{
				if (x == 0)
					printf ("┏");
				else if (x  == n)
					printf ("┓");
				else if (x%2 == 1)
					printf ("━");
				else if (x%2 == 0)
					printf ("┯");
			}
			else if ( y == n)
			{
				if (x == 0)
					printf ("┗");
				else if (x  == n)
					printf ("┛");
				else if (x%2 == 1)
					printf ("━");
				else if (x%2 == 0)
					printf ("┷");
			}
			else if (y % 2 == 1 )
			{
				if (x == 0)
					printf ("┃");
				else if (x  == n)
					printf ("┃");
				else if (x%2 == 1)
					printf ("  ");
				else if (x%2 == 0)
					printf ("│");
			}
			else if ( y % 2 == 0)
			{
				if (x == 0)
					printf ("┠");
				else if (x  == n)
					printf ("┨");
				else if (x%2 == 1)
					printf ("─");
				else if (x%2 == 0)
					printf ("┼");}
			
			if ( x == n)
				printf ("\n");
		}
}