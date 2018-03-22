# include <stdio.h>
# include <windows.h>
# include <conio.h>
# include <stdlib.h>
# include <time.h>

void zhibiao ( int n );
void gotoxy ( int a , int b ) ;
void HideCursor(void)  ;
int **  leiqu (int n , int t);
void leimu ( int ** p , int n);
void pailei ( int ** p , int n ,int t);
void k_gua ( int **p , int ** q, int n);
void l_qu (int ** p , int ** q ,int *and , int x , int y , int n);


int main()// ===========================================================主函数==================================================
{						 // ==================变量
	char ch ;
	int ** p;
						//================= 变量
	HideCursor();
	
	system ("color E9");
	system ("title  扫雷   ------------------董涛制作");
	
	system ("mode con cols=70 lines=30");
	
	gotoxy (13 , 10);
	puts ("==================扫雷====================");
	gotoxy (20 , 15);
	puts ("1.  开始游戏");
	gotoxy (20 , 16);
	puts ("2.  退出游戏");
	gotoxy ( 20 , 18 );
	puts("请选择。。。。。");
	
	while (1)
	{
		ch = getch ();
		if (ch == '1')
		{
			system ("cls");
			break;
		}
		else if (ch == '2')
		{
			system ("cls");
			goto end;
		}
		else;
	}

	gotoxy (13 , 10);
	puts ("===============请选择关卡==================");
	gotoxy (20 , 15);
	puts ("1.  第一关");
	gotoxy (20 , 16);
	puts ("2.  第二关");
	gotoxy ( 20 , 17 );
	puts("3.  第三关");
	gotoxy ( 20 , 20 );
	puts ("注意 : 使用 W A D S 移动光标 ");
	gotoxy (20 , 21);
	puts ("       使用 空格键 标记雷区 ");
	gotoxy (20 , 22);
	puts ("       使用 回车键 标记打开覆盖区 ");

	
	while (1)
	{
		ch = getch ();
		
		if (ch == '1'|| ch == '2'|| ch == '3' )
		{
			system ("cls");
			break;
		}
		else;
	}
	
	if ( ch == '1')
	{
		system ("mode con cols=40 lines=27");
		
		zhibiao (18);
		
		
		p = leiqu( 9 , 15);
		leimu (p , 9);


		gotoxy ( 2 , 1 );
		printf ("◎");
		pailei ( p , 9 ,15);
	


	}

	if (ch == '2')
	{
		system ("mode con cols=70 lines=40");
		
		zhibiao (32);
		
		
		p = leiqu( 16 , 40);
		leimu (p , 16);


		gotoxy ( 2 , 1 );
		printf ("◎");
		pailei ( p , 16 ,40);
	}

	if ( ch == '3')
	{
		system ("mode con cols=100 lines=50");
		
		zhibiao (46);
		
		
		p = leiqu( 23 , 100);
		leimu (p , 23);


		gotoxy ( 2 , 1 );
		printf ("◎");
		pailei ( p , 23 ,100);
	}
	
	
	
end:

	return 0 ;

}                     //=================================================主函数===========================================


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

void gotoxy ( int a , int b )                         //================坐标函数
{
	HANDLE hOutput;
	
	COORD loc;
	loc.X = a , loc.Y = b;
	
	hOutput = GetStdHandle (STD_OUTPUT_HANDLE);
	
	SetConsoleCursorPosition (hOutput,loc);
	
}

void HideCursor(void)                                 //=============== 不显示光标
{
	HANDLE Stdout;
	
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};
	
	Stdout = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleCursorInfo(Stdout , &cursor_info);
}

int ** leiqu (int n , int t)  //============================================雷区函数
{
	int ** p;
	int m , k = 0;
	int x  ,y ;
	
	p = (int **)malloc (sizeof (int*) * n);
	for ( x = 0 ; x <= n-1 ; x++)
		p[x] = (int *) malloc (sizeof (int) * n);
	
	for ( y = 0 ; y <= n-1 ; y ++)
		for ( x = 0 ; x <= n-1 ; x++)
			p[y][x] = 0;
			
			srand ((unsigned)time(0));
		
		x = 0 , y = 0;
		
		while(1)
		{
			m =	rand ();
			if ( p[y][x] == 0 )
			{
				if ( m % 13 == 0)
				{
					p[y][x] = -1;
					x++;
					k++;
				}
				else
				{
					x++;
				}
				
				if (x == n)
				{
					x = 0;
					y ++;
				}
				if ( y == n )
					y = 0;
			}
			else
			{
				x++;
				if (x == n)
				{
					x = 0;
					y++;
				}
				if (y == n)
					y = 0;
			}

			if ( k == t)
				break;
		}
		
	return p;
}

void leimu ( int ** p , int n)      //  =================列出雷的数目
{
	int x , y , i , j ;
	int and;

	for ( y = 0 ; y < n ; y++)
		for ( x = 0 ; x < n ; x++)
		{
			if ( p[y][x] == 0 )
			{
				and = 0;

				for ( j = y - 1  ; j <= y+1  ; j++)
					for ( i = x-1 ; i <= x+1 ; i++)
					{
						if(i >= 0 && i<= n-1 && j >= 0 && j<= n-1)
							if (p[j][i] == -1)
								and++;
					}

				p[y][x] = and;				
			}
		}
}
void pailei ( int ** p , int n , int t)
{
	int x = 0 , y = 0;
	int ** q;
	char one , ch ;
	int and = 0;

	q = (int **)malloc (sizeof (int*) *n);

	for (y = 0 ; y <= n-1 ; y++)
	{
		q[y] = (int *)malloc (sizeof(int)*n);
	}

	for (y = 0 ; y <= n-1 ; y++)
		for (x = 0 ; x <= n-1 ; x++)
			q[y][x] = 0;              // 标记雷区的副本 用于反馈雷区信息
	x = 0 , y = 0 ;					  // 雷块被打开 : 1
									  // 雷块被标记 : 2
	while (1)						  // 雷块未打开 : 0
	{								  //  0 区      : 3
									  // 标记区     : 4
		one = getch();

		gotoxy ( 4*x+2 , 2*y+1);

		if (one == 'w')
		{
			
			if (q[y][x] == 0)
				printf ("  ");
			else if (q[y][x] == 1  )
				printf ("%2d",p[y][x]);
			else if (q[y][x] == 2)
				printf ("★");
			else
				printf ("⊙");
			y--; 
			if ( y < 0)
				y = n-1;
			gotoxy ( 4*x+2 , 2*y+1);
			printf ("◎");
		}

		if (one == 'a')
		{
			if (q[y][x] == 0)
				printf ("  ");
			else if (q[y][x] == 1  )
				printf ("%2d",p[y][x]);
			else if (q[y][x] == 2)
				printf ("★");
			else
				printf ("⊙");
			x-- ;

			if (x < 0)
				x = n-1;

			gotoxy (4*x+2 , 2*y+1);
			printf ("◎");
			
		}

		if (one == 's')
		{
			if (q[y][x] == 0)
				printf ("  ");
			else if (q[y][x] == 1 )
				printf ("%2d",p[y][x]);
			else if (q[y][x] == 2)
				printf ("★");
			else
				printf ("⊙");
			y++;
			if (y == n )
				y = 0;

			gotoxy (4*x+2 , 2*y+1);
			printf ("◎");
		}

		if (one == 'd')
		{
			if (q[y][x] == 0)
				printf ("  ");
			else if (q[y][x] == 1  )
				printf ("%2d",p[y][x]);
			else if (q[y][x] == 2)
				printf ("★");
			else
				printf ("⊙");

			x++;

			if (x==n)
				x=0;
			gotoxy (4*x+2 , 2*y+1);
			printf ("◎");
		}

		if ( one == 'N')
			k_gua ( p , q , n );

		if (one == ' ')
		{
			if (q[y][x] == 0)
			{
				printf ("★");
				q[y][x] = 2;
			}
			else if (q[y][x] == 2)
			{
				printf ("  ");
				q[y][x] = 0;
			}
		}	

		if (one == '\r')
		{
			if (q[y][x] == 0 )
			{
				if (p[y][x] == -1)
				{
					for ( y = 0 ; y <= n-1 ; y++)
						for ( x = 0 ; x <= n-1 ; x++)
						{
							if (p[y][x] == -1)
							{
								gotoxy (4*x+2 , 2*y+1);
								printf ("╬");						
							}
						}

						Sleep (1000);
						
						gotoxy (10 , 15);
						puts ("游戏结束!!!");
						ch = getch();
						system ("cls");
						break;
				}

				else if (p[y][x] != 0) 
				{
		
					printf ("%2d", p[y][x]);
					and++;
					q[y][x] = 1;
					
				}
				else
					l_qu ( p , q , & and , x , y , n);
			}						
		}

		if (and == (n*n-t))
		{
			Sleep (1500);
	
			gotoxy (10 , 15);
			puts ("过关!!!");

			ch = getch();
			break;
		}		
	}

}
void k_gua ( int **p , int ** q , int n)
{
	int x , y;

	for (y = 0 ; y <= n-1 ; y++)
		for (x = 0 ;  x <= n-1 ; x++)
		{
			if (p[y][x] == -1)
			{
				gotoxy (4*x+2 , 2*y+1);
				printf ("╬");
			}
		}
	Sleep (2000);

	for (y = 0 ; y <= n-1 ; y++)
		for (x = 0 ;  x <= n-1 ; x++)
		{
			if (p[y][x] == -1)
			{
				if (q[y][x] == 0)
				{
					gotoxy (4*x+2 , 2*y+1);
					printf ("  ");
				}
				else if (q[y][x] == 2)
				{
					gotoxy (4*x+2 , 2*y+1);
					printf ("★");
				}
			}
		}
}
void l_qu (int ** p , int ** q ,int * and , int x , int y , int n)
{
	int i , j;

	q[y][x] = 4 ;

	(*and) ++;

	for ( j = y-1 ; j <= y+1 ; j++)
		for ( i = x-1 ; i <= x+1 ; i++)
		{
			if ( i >= 0 && i <= n-1 && j >= 0 && j <= n-1)
			{
				if (p[j][i] == 0 )
				{
					if (q[j][i] != 4 )
					{
						q[j][i] = 3;
						gotoxy (4*i+2 , 2*j+1);
						printf ("⊙");
						l_qu ( p , q , and , i , j , n);
					}
					else
					{
						gotoxy (4*i+2 , 2*j+1);
						printf ("⊙");
					}										
				}
				else 
				{
					if (q[j][i] != 1)
					{
						(*and) ++;
						q[j][i] = 1;
					}
					gotoxy (4*i+2 , 2*j+1);
					printf ("%2d",p[j][i]);									
				}					
			}
		}	
}




