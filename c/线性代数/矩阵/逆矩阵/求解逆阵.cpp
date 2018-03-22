# include <stdio.h>
# include <stdlib.h>

int HL_shi ( int str[10][10] , int n );
void j_zhen ( int str[10][10] , int n );
int f_hao ( int a , int b );

int main (void)
{
	int str [10][10];
	int x , y , n ; 
	char c , At ; 
	
Start:
	
	printf ("请输入原矩阵( 10 阶以下) :\n");
	scanf ("%d" , &n);
	puts ("请按行输入 :");
	
	for ( y = 1 ; y <= n ; y++)
		for ( x = 1 ; x <= n ; x++)
			scanf ("%d", &str[y][x]);
		puts ("-------------------------------------------------------------");
		printf ("你输入的矩阵为:\n");
		
		for ( y = 1 ; y <= n ; y++)
		{
			printf ("\t\t| ");
			for ( x = 1 ; x <= n ; x++)
				printf ("%4d ",str[y][x]);
			printf ("|\n");
			
		}
		puts ("--------------------------------------------------------------");
		
		c = getchar ();
		
		puts ("如果输入不正确请输入 : (N/n)");
		puts ("如果输入正确请按任意其他键继续 :");
		
		At = getchar ();
		
		if ( At =='N' || At == 'n')
			goto Start;
		
		j_zhen ( str , n );
		
		return 0;
}

void j_zhen ( int str[10][10] , int n )
{
	float Sum;
	int str_1[10][10] ;
	float str_2 [10][10];
	int x , y , a , b , ptr;
	
	printf ("这个矩阵的逆阵为 :\n");
	puts ("---------------------------------------------------------------");
	printf ("\n\n\n\n");
	
	if ( n == 1 )
		printf ("\t\t| %4d |\n" , str[1][1]);
	
	else
	{
		Sum = ( 1 / (float) HL_shi ( str , n));
		
		for ( b = 1 ; b <= n ; b++)
			for ( a = 1 ; a <= n ; a++)
			{
				for ( y = 1 ; y <= n ; y++)
					for ( x = 1 ; x <= n ; x++ )
						str_1[y][x] = str [y][x];
					
					for ( y = 1 ; y <= n-1 ; y++ )
						for ( x = 1 ; x <= n ; x++)
							if ( y >= b )
								str_1 [y][x] = str_1 [y+1][x];
							for ( y = 1 ; y <= n-1 ; y++ )
								for ( x = 1 ; x <= n-1 ; x++)
									if ( x >= a )
										str_1 [y][x] = str_1 [y][x+1];
									str_2[b][a] = Sum * f_hao ( a , b ) * HL_shi ( str_1 ,n-1);
									
			}
			
			for ( b = 1 ; b <= n ; b++)
			{	printf ("\t\t| ");
			
			    for ( a = 1 ; a <= n ; a++)
					printf ("%5f ",str_2[a][b]);

			    printf ("|\n");
			}
			
	}
	
	printf ("\n\n\n");
	puts ("---------------------------------------------------------------");
	
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
	
	if ( (a+b) % 2 == 1)
		t = -1;
	else
		t = 1;
	return t;
}




