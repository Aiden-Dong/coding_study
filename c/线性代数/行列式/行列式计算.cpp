# include <stdio.h>

int HL_shi ( int str[10][10] , int n );
int f_hao ( int a , int b );

int main (void)
{
	char t , r ,ch ;
	int n;
	int x , y;
	int str[10][10];
	
Start:
	
	puts ("请输入要求的行列式阶数(阶数要在 10 阶之内) :");
	
	scanf ("%d" , &n);
	
	puts ("请按行输入行列式 :");
	
	for( y = 1 ; y <= n ; y++)
	{
		for ( x = 1 ; x <= n ; x++)
			scanf ("%d", &str[y][x]);
	}
	
	puts ("你输入的行列式为 :");
	
	for( y = 1 ; y <= n ; y++)
	{
		printf ("\t\t|");
		for ( x = 1 ; x <= n ; x++)
			printf ("%7d ",str[y][x]);
		printf ("|\n");
	}
	
	printf ("\n\n");
	
	puts ("如果错误请输入: N/n");
	puts ("如果正确请按其他任意键继续 :");
	
	r = getchar ();
	
	t = getchar();
	
	if (t == 'N' || t == 'n')
		goto Start;          //-----------------------到此之前为接收正确行列式 ;
	
	
	printf ("行列式的结果为 :     %d\n\n\n\n\n\n", HL_shi( str , n ) );

	puts ("如果推出请按任意键\n否则请按 Y/y 继续 :");

	ch = getchar ();

	if ( (ch == 'Y') || (ch == 'y') )
		goto Start;
	
	return 0;
}

int HL_shi ( int str[10][10] , int n )
{
	int Sum = 0;
	int t , x , y , str_1[10][10];
	
	if ( n == 1 )
		Sum = str[1][1];
	
	
	else
	{
		for ( t = 1 ; t <= n ; t ++)
		{
			for ( y = 1 ; y <= n ; y++)
				for ( x = 1 ; x <= n ; x++)
					str_1[y][x] = str[y][x];
				
				for ( y = 1 ; y <= n-1 ; y++)
					for ( x = 1 ; x <= n-1 ; x++)
					{
						if ( x >= t )
							str_1 [y][x] = str_1 [y][x+1];
					}
					
					Sum = Sum + ( f_hao ( t , n ) * str_1[n][t] * HL_shi ( str_1 , n-1 ));
					
		}
		
	}
	return Sum;
	
}

int f_hao ( int a , int b )
{
	int t;
	int And = 1;
	
	for ( t = 1 ; t <= (a+b) ; t++ )
	{
		And = And * (-1);
	}
	
	return And;
}