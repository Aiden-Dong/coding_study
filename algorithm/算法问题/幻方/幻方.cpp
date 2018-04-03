# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <windows.h>

void h_fang1 (int **a ,  int n );
void h_fang22 ( int ** a , int n );
void h_fang21 ( int **a , int n );
void Han_dal ();

int main (void)
{
	int n , y , x ;
	int **a;
	
	
	
	puts ("请输入要求的幻方阶数 :");
	
	
	scanf ("%d",&n);

	
	system ("mode con cols=100 lines=80");
	Han_dal();
	
	a = (int **) malloc (sizeof (int) * (n+1));
	
	for ( y = 0 ; y <= n+1 ; y ++)
		a[y] = (int *) malloc (sizeof(int) *(n+1));

	a[1][1] = 0;  // 初始化变量值


	for ( y = 1 ; y <= n ; y ++)
	{
		for ( x = 1 ; x <= n ; x++)
			a[y][x] = 0;
	}
	
    if ( n%2 == 1 )
		h_fang1 ( a , n );
	else if (n/2%2 == 0)
		h_fang22 ( a , n );
	else
		h_fang21 ( a , n );
	
	return 0;
}
void h_fang1 (int **a ,  int n )
{
	int x = n/2+1, y = 1;
	int t = 0;
	
	while ( t != (n*n) )
	{
		t++;
		
		if ( x > n )
			x = 1;
		if ( y < 1 )
			y = n;
		
		if ( a[y][x] )
		{
			x--;
			y++;
			if (x < 1 )
				x = n;
			if ( y > n )
				y = 1;
			y++;           //找位置
			
			if ( y > n )
				y = 1;
		}
		
		a[y][x] = t;      // 插入数据
		x++;
		y--;
	}
	
	puts ("==================================================================");
	printf ("\n");
	
	for ( y = 1 ; y <= n ; y ++)
	{
		for ( x = 1 ; x <= n ; x++)
			printf ("%4d ",a[y][x]);
		printf ("\n\n");
	}
	puts ("==================================================================");
}
void h_fang22 ( int ** a , int n )
{
	int x , y ;
	int Sum1 = 0 , Sum2 = 0 ;
	int and = 1;

	for( y = 1 ; y <= n/2 ; y ++)
		for (x = 1 ; x <= n/2 ; x++)
		{
			if ( y%2 == 1 )
			{
				if ( x%2 == 1)
					a[y][x] = -1;
			}
			else
			{
				if ( x%2 == 0)
					a[y][x] = -1;
			}
		}

	for ( y = 1 ; y <= n ; y ++)
		for ( x = 1 ; x <= n; x++)
		{
			if (y <= n/2)
			{
				if (x <= n/2)
				{
					a[y][n+1-x] = a[y][x];
					a[n+1-y][x] = a[y][x];
				}
				else
					a[n+1-y][x] = a[y][x];

			}

		}

	for ( y = 1 ; y <= n ; y ++)
		for ( x = 1 ; x <= n; x++)
		{
			if (!a[y][x])
				a[y][x] = and;

			and++;

		}
		and = 1;
	for ( y = n ; y >= 1 ; y --)
		for ( x = n ; x >= 1; x--)
		{
			if ( a[y][x] == -1 )
				a[y][x] = and;
			and++;
		}
	printf ("\n");

	puts ("================================================================================\n");
	printf ("\n");

	for( y = 1 ; y <= n ; y ++)
	{
		for (x = 1 ; x <= n ; x++)
			printf ("%4d   ",a[y][x]);
		printf ("\n\n");
	}
	printf ("\n");
	puts ("================================================================================\n");

}

void h_fang21 ( int **a , int n )
{
	int x , y , t=0;
	int k = n/4;
	int w;

	x = n/2/2+1 , y = 1;

	while ( t != ( n/2 * n/2 ) )
	{
		t++;
		
		if ( x > n/2)
			x = 1;
		if ( y < 1 )
			y = n/2;
		
		if ( a[y][x] )
		{
			x--;
			y++;
			if (x < 1 )
				x = n/2;
			if ( y > n/2)
				y = 1;
			y++;           //找位置
			
			if ( y > n /2)
				y = 1;
		}
		
		a[y][x] = t;      // 插入数据
		x++;
		y--;
	}

	x = n/2 + n/2/2+1 , y = 1 ;

	while ( t != ( (n/2)* n ) )
	{
		t++;
		
		if ( x > n )
			x = n/2 +1 ;
		if ( y < 1 )
			y = n/2;
		
		if ( a[y][x] )
		{
			x--;
			y++;
			if (x < n/2+1 )
				x = n;
			if ( y > n/2 )
				y = 1;
			y++;           //找位置
			
			if ( y > n /2)
				y = 1;
		}
		
		a[y][x] = t;      // 插入数据
		x++;
		y--;
	}

	x = n/2/2+1 , y = n/2+1;
	
	while ( t != ( n/2 * n/2*3 ) )
	{
		t++;
		
		if ( x > n/2)
			x = 1;
		if ( y < n/2+1 )
			y = n;
		
		if ( a[y][x] )
		{
			x--;
			y++;
			if (x < 1 )
				x = n/2;
			if ( y > n)
				y = n/2+1;
			y++;           //找位置
			
			if ( y > n )
				y = n/2+1;
		}
		
		a[y][x] = t;      // 插入数据
		x++;
		y--;
	}

	x = n/2 + n/2/2+1 , y = n/2+1 ;
	
	while ( t != ( n * n ) )
	{
		t++;
		
		if ( x > n)
			x = n/2+1;
		if ( y < n/2+1 )
			y = n;
		
		if ( a[y][x] )
		{
			x--;
			y++;
			if (x < n/2+1 )
				x = n;
			if ( y > n)
				y = n/2+1;
			y++;           //找位置
			
			if ( y > n )
				y = n/2+1;
		}
		a[y][x] = t;      // 插入数据
		x++;
		y--;
	}

	for (y = 1 ; y <= n/2 ; y++)
		for ( x = 1 ; x <= n/2 ; x++)
		{
			if ( y != n/2/2+1)
			{	if (x <= n/2/2)
				{
					//a[y][x] = 0;
					w = a[y][x];
					a[y][x] = a[y+n/2][x];
					a[y+n/2][x] = w;
					
				}
			}
			else
			{
				if ( x >= n/2/2+1 && x != n/2)
				{
					w = a[y][x];
					a[y][x] = a[y+n/2][x];
					a[y+n/2][x] = w;
				}
			}

		}
		if ( k - 1 > 0)
			for ( y = 1 ; y <= n/2 ; y ++)
				for ( x = n/2+1 ; x <= n ; x++)
					if ( x >= n/2+n/2/2+1 && x<= n/2+n/2/2+1 + k - 2)
					{
						w = a[y][x];
						a[y][x] = a[y+n/2][x];
						a[y+n/2][x] = w;
					}


	puts ("================================================================================\n");
	printf ("\n");

	for( y = 1 ; y <= n ; y ++)
	{
		for (x = 1 ; x <= n ; x++)
			printf ("%4d   ",a[y][x]);
		printf ("\n\n");
	}
	printf ("\n");
	puts ("================================================================================\n");

}
void Han_dal ()
{
	HANDLE hstdout;

	CONSOLE_CURSOR_INFO ads = {1,0};

	hstdout = GetStdHandle (STD_OUTPUT_HANDLE);

	SetConsoleCursorInfo (hstdout, &ads);
}