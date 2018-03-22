# include <stdio.h>
# include <windows.h>
# include <stdlib.h>
# include <time.h>
# include <string.h>

# define N 80

void gotoxy ( int a , int b );
void z_mian ( int a , int b );
void paizu (struct Sum *pai );
void xipai ( struct Sum *pai , int n);
void qiepai (struct Sum *pai ,int n );
void puke ( int a , int b );
void paimian ( Sum *pai);
int qiaopai (Sum * pai);
Sum  choupai ( int *Q , Sum *pai );
int daxiao (Sum *pai1 , Sum *pai2);
void HideCursor(void);

struct Sum
{
	int a;
	char b;
}
;
int main (void)                                 // *************** 主函数 *************************************************
{
	HideCursor();
	system ("title 德州桥牌                    --董涛制作");
	system ("mode con cols=80 lines=27");
	system ("color 3A");
	                              //------------- 变量声明 -------------------------------
	int L , M ;               //(排序打乱)               
	int i = 6000 , j = 6000 ; //(金币值)
	int R , And = 0  , I , G; //(记录金币流出)
	int x , y , t ;           //(用于循环结构)
	int a , b;                //(坐标位置)
	int K = 1 , Q = 1;        //(抽牌顺序)
	FILE *fp;                 //(打开外部文件)
	char str[35] ;            //(打印其他字符串)          
	char name[20];            //(玩家姓名)
	Sum pai[53];              //(牌组)
	Sum nam1[6] , nam2[6];     //(手牌) 

	                          //------------- 变量声明 -------------------------------
	

	//system ("cmd");

	


	for ( y = 1 ; y <= 25 ; y ++)           //==============开始画面 1============================
	{
		for ( x = 1 ; x <= 80 ; x++)
		{
			if ( y >= 2 && y <= 24)
			{
				if ( x == 1 || x == 80)
					printf ("*");
				else
					printf (" ");
			}
			else
				printf ("*");
		}
	}
	
	
	a = N/2 - 9 ,  b = 3 ;
	z_mian ( a , b );
	a = a+2 , b++;
	z_mian ( a , b );
	a = a+2 , b++;
	z_mian ( a , b );               //==============开始画面 1============================
	

	

	while ((getchar()) != '\n');   

	system ("cls");

	if ( (fp = fopen ("游戏注意事项.txt" , "r"))  == NULL )  //============ 游戏注意事项========================
	{
		fprintf (stderr , "打开错误 检查文件完整 !!!!");
		exit (1);

	}

	fgets ( str ,30, fp );
	puts (str);
	fgets ( str ,30, fp );
	puts (str);
	fgets ( str ,30, fp );
	puts (str);
	fgets ( str ,30, fp );
	puts (str);
	fgets ( str ,35, fp );
	puts (str);

	fclose (fp);                                            //============ 游戏注意事项========================

	while ((getchar()) != '\n');

	system ("cls");



	a = N/2 -8 ; b = 4;                        // ==================== 构建 开始前奏=============

	for ( y = 1 ; y <= 3 ; y++ )
	{
		gotoxy ( a , b );
		for ( x = 1 ; x <= 16 ; x++ )
		{
			if ( y != 2 )
				printf ("*");
			else
			{
				if ( x == 1 || x == 16)
					printf ("*");
				else
					printf (" ");
			}
		}
		b++;
	}

	b = b-2 , a++ ;
	gotoxy (a , b );
	printf (" 德 州 桥 牌 ");
	b = b+2;
	gotoxy ( 0 , b );
	for ( x = 1 ; x <= 80 ; x++)
		printf ("=");


	b = b+2;
	gotoxy ( a , b );
	puts (" *  人机对战版");
	gotoxy ( a , b+1 );
	puts (" *  不能联机对战");

	a = a-2 , b = b+6;
	gotoxy ( a , b );
	puts ("按回车键开始游戏 : ...........");       // ==================== 构建 开始前奏=============
	
	paizu ( pai );

	//Sleep (1000);

	while ((getchar()) != '\n');
	system ("cls");

	puts ("请输入姓名 :");                     // ==================== 输入 玩家姓名 ==============================

	gets (name);
	
	if (strlen(name)==0)
		strcpy(name , "saligia");
  
                                        // ==================== 输入 玩家姓名 ==============================

	Sleep (500);                             

	a = N/2 -8 ; b = 4;                          // =================显示开始游戏=======================

	for ( y = 1 ; y <= 3 ; y++ )
	{
		gotoxy ( a , b );
		for ( x = 1 ; x <= 16 ; x++ )
		{
			if ( y != 2 )
				printf ("*");
			else
			{
				if ( x == 1 || x == 16)
					printf ("*");
				else
					printf (" ");
			}
		}
		b++;
	}

	b = b-2 , a++ ;
	gotoxy (a , b );
	printf (" 游 戏 开 始 ");
	Sleep (500);
	system ("cls");                                    // =================显示开始游戏=======================
	




	

	paizu ( pai );                              //===============打乱牌顺序=============================
	
	qiepai (pai , 21);
	xipai ( pai , 20);
	srand ( (unsigned)time (NULL));    // 产生随机数 
	L = rand () % 100;
	M = rand () % 52;
	xipai ( pai , L);
	qiepai (pai , M);
	
	Sleep (1500);

	
/*
	for ( t = 1 ; t <= 52 ; t++)
		printf ("pai[%d] = %d %c\n",t, pai[t].a ,pai[t].b );

	
	for ( x = 1 ; x <= 5 ;x ++)
	{
		nam1[x] = choupai (&Q,pai);
	}
	*/
/*
	for ( x = 1 ; x <= 5 ;x ++)
		printf ("nam1 =%d %c\n", nam1[x].a ,nam1[x].b );

		printf ("\nOne = %d\n",qiaopai (nam1));
		printf ("\n");
	for ( x = 1 ; x <= 5 ;x ++)
		printf ("nam1 =%d %c\n", nam1[x].a ,nam1[x].b );
	*/

		while ( i >= 1000 && j >= 1000)          
	{
		And = 0;
		system ("cls");
		
		for ( y = 1 ; y <= 25 ; y ++)                         //==================== 构建游戏界面 ================！
		{
		for ( x = 1 ; x <= 80 ; x++)
		{
			if ( y == 1 || y == 25 || y == 10 || y == 16)
				printf ("*");
			else
			{
				if (x == 1 || x == 80 )
					printf ("*");
				else
					printf (" ");
			}
		}
	}

	a = 10 , b = 0 ;

	for ( y = 1 ; y <= 25 ; y++)
	{
		gotoxy ( a , b );
		printf ("*");
		gotoxy (62 , b++);
		printf ("*");
	}

	gotoxy ( 2 , 2 );
	puts ("人机");
	gotoxy ( 2 , 17 );
	puts (name);
	gotoxy (63,1);
	printf ("人机 :");
	gotoxy (63,16);
	printf ("%s :",name);

	gotoxy ( 2 , 5 );
	printf ("金币 : ");
	gotoxy ( 2 , 6 );
	printf ("%d", i );
	gotoxy ( 2 , 21 );
	printf ("金币 : ");
	gotoxy ( 2 , 22 );
	printf ("%d", j );
	
	gotoxy ( 20 , 12 );
	puts (" 正 在 准备 牌 ......            ");
                      
	Sleep (1000);                  //==================== 构建游戏界面 ================!
//===============================发两张牌======================================================================
		if ( K % 2 == 1)
		{
			R = 100;
			j = j - R;
			And = And + R;
			gotoxy (63 , 17);         //-----------------================--押注--======----
			puts ("押注 :");
			gotoxy ( 64 , 18 );
			printf ("%5d",R);
			gotoxy ( 22 , 14 );
			printf ("%5d" , And);
			
			gotoxy (2 , 22);
			printf ("%4d",j);       //----------押注------ 

			for ( x = 1 ; x <= 2 ; x++) //----抽牌---------
			{
				nam2[x] = choupai ( &Q , pai );
				nam1[x] = choupai (&Q , pai );//----抽牌---------
			}

			
		}
		else
		{
			R = 100;
			i = i - R;
			And = And + R;
			gotoxy (63 , 2);         //----------押注------
			puts ("押注 :");
			gotoxy ( 64 , 3 );
			printf ("%5d",R);
			gotoxy ( 22 , 14 );
			printf ("%5d",And);
			gotoxy (2 , 6);
			printf ("%5d",i);       // //-----------------================--押注--======---- 

			for ( x = 1 ; x <= 2 ; x++) //----抽牌---------
			{
				nam1[x] = choupai ( &Q , pai );
				nam2[x] = choupai (&Q , pai );//----抽牌---------
			}
		}

		gotoxy ( 20 , 12 );
		puts (" 正 在 发 牌 ......            ");
		Sleep(3000);

		puke ( 12 ,1 );             // ==============打开牌面 2 张====
		gotoxy(14,2);
		paimian (&nam1[1]);

		puke (22 ,1 );
		//gotoxy(24,2);
		//paimian (&nam1[2]);

		puke ( 12 , 16);
		gotoxy (14 ,17);
		paimian (&nam2[1]);

		puke (22,16);
		gotoxy (24,17);
		paimian (&nam2[2]);  //  ==============打开牌面 2 张====
//================================================发两张牌====================================================================
		Sleep(6000);
//=================================================第一次下注=================================================================	
		if ( K % 2 == 0)   
		{
			gotoxy (63,17);
			puts ("请选择 :   ");
			gotoxy (20,12); 
			printf ("请 选择 1. 下注  2.弃牌                     ");
start:
			gotoxy (64,18);
			puts ("      ");
			gotoxy (64,18);
			t = getchar ();            //清空并输入

			if ( t == '1')
			{
 
				gotoxy (20,12); 
				printf ("请 %s 下注 :   ( 100 - 300)                     ",name);
start1:
				gotoxy (64,18);
				puts ("    ");
				gotoxy (64,18);
				scanf ("%d",&R);

				if (R < 100 || R > 300 )
				{
					while (getchar() != '\n');
					goto start1;
				}
				Sleep(3000);

				And = And + R;
				gotoxy (22,14);
				printf ("%5d",And);
				gotoxy (2,22);
				j = j - R;
				
				printf ("%5d",j);
				Sleep(500);

				gotoxy (64,4);
				puts ("跟！");
				
				i = i - R;
				gotoxy (2,6);
				printf ("%5d",i);
				And = And + R;
				gotoxy (22,14);
				printf ("%5d",And);
			}
			else if ( t == '2' )
			{
				i = i + And;
				gotoxy (2,6);
				printf ("%5d",i);
				gotoxy (22,14);
		   	    printf ("        ");
				gotoxy (20,12);
				printf ("人机胜 !!!!!                             ");
				goto end1;
			}

			else
				goto start;
		}


		else
		{
			if (nam1[1].a==nam1[2].a && nam1[1].b == nam1[2].b)
			{
				R = 300;
				
				gotoxy (63,2);
				puts ("300");
				i = i - 300;
				And = And + 300;
			}
			else if (nam1[1].b==nam1[2].b)
			{
				R = 270;
				gotoxy (63,2);
				puts ("270");
				i = i - 270;
				And = And + 270;
			}
			else if (nam1[1].a==nam1[2].a)
			{
				R = 230;
				gotoxy (63,2);
				puts ("230");
				i = i - 230;
				And = And + 230;
			}
			else
			{
				R = 150;
				gotoxy (63,2);
				puts ("150");
				i = i - 150;
				And = And + 150;
			}

			gotoxy (22,14);
			printf ("%5d",And);
			gotoxy (2,6);
			printf ("%4d",i);

			Sleep (3000);

			gotoxy ( 20 , 12 );
			printf ("%s 1.(跟牌) 2. (加注) 3.(弃牌) :       ",name);
			gotoxy (63,17);
			puts ("选择 :");
start2:
			gotoxy (64,18);
			puts ("      ");
			gotoxy (64,18);
			t = getchar ();

			

			if ( t == '1')
			{
				Sleep (1000);
				j = j - R;
				And = And + R;
				gotoxy (2,22);
				printf ("%5d",j);
				gotoxy (22,14);
				printf ("%5d",And);
			}
			else if (t == '2')
			{
				gotoxy (20,12);
				printf ("请选择要加注的数目 : (100 - 300)         ");
start3:
				gotoxy (64,18);
				puts ("      ");
				gotoxy (64,18);
				scanf ("%5d",&I);
				if ( I > 300 || I < 100 )
				{
					while (getchar() != '\n');
					goto start3;
				}

				Sleep (500);
				j = j - I - R;
				And = And + I + R;
				gotoxy (2,22);
				printf ("%5d",j);
				gotoxy (22,14);
				printf ("%5d",And);

				Sleep(1000);

				if ( I > 200  && nam1[1].a < 10 && nam1[2].a < 10 && nam1[1].b != nam1[2].b )
				{
					gotoxy (63,2);
					printf ("       ");
					gotoxy (63,2);
					printf ("卧槽 不跟了!!!");

					j = j + And;
					gotoxy (20,12);
					printf ("%s   胜                               " ,name);
					goto end1;
					gotoxy (2 , 22);
					printf ("%5d",j);
					gotoxy (22,14);
					printf ("     ");
				}
				else
				{
					gotoxy (63,2);
					printf ("       ");
					gotoxy (63,2);
					printf ("呵呵 跟你!");

					i = i - I ;
					And = And + I ;
					gotoxy (2,6);
					printf ("%5d",i);
					gotoxy (22,14);
					printf ("%5d",And);
				}

			}
			else if (t == '3')
			{
				i = i + And;
				gotoxy (2,6);
				printf ("%5d",i);
				gotoxy (22,14);
		   	    printf ("         ");
				gotoxy (20,12);
				printf ("人机胜 !!!!!                                  ");
				goto end1;

			}
			else
				goto start2;
		}
//=================================================第一次下注=================================================================
		Sleep (1000);

		gotoxy ( 20 , 12 );
		printf ("正 在 发 牌                                 ");

		Sleep (3000);
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<发后三张牌>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		if ( K % 2 == 1)
			for ( x = 3 ; x <= 5 ; x++) //----抽牌---------
			{
				nam2[x] = choupai ( &Q , pai );
				nam1[x] = choupai (&Q , pai );//----抽牌---------
			}
		else
			for ( x = 3 ; x <= 5 ; x++) //----抽牌---------
			{
				nam1[x] = choupai ( &Q , pai );
				nam2[x] = choupai (&Q , pai );//----抽牌---------
			}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<发后三张牌>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		puke (32,1);
		puke (42,1);
		puke (52,1);
		puke (32,16);
		gotoxy(34,17);
		paimian (&nam2[3]);
		puke (42,16);
		gotoxy (44,17);
		paimian (&nam2[4]);
		puke (52,16);
		gotoxy (54,17);
		paimian (&nam2[5]);
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<第二次投注>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

		Sleep(3000);

		if ( K % 2 == 1 )
		{
			
			if (qiaopai (nam1) >= 6)
				R = 400;
			if (qiaopai (nam1) < 6 && qiaopai (nam1) > 2)
				R = 300;
			else
				R = 100;
start4:
			G = rand()%500;
			R = R + G;

			if ( R < 300)
				goto start4;
			gotoxy (63,2);
			printf ("           ");
			gotoxy (63,2);
			printf ("%5d",R);

			i = i - R;
			And = And + R;

			gotoxy (2,6);
			printf ("%5d",i);
			gotoxy (22,14);
			printf ("%5d",And);

				Sleep (3000);
				// 玩家判断时刻

			gotoxy ( 20 , 12 );
			printf ("%s 1.(跟牌) 2. (加注) 3.(弃牌) :         ",name);
			gotoxy (63,17);
			puts ("选择 :");
start5:
			gotoxy (64,18);
			puts ("           ");
			gotoxy (64,18);
			t = getchar ();

		

			if ( t == '1')
			{
				Sleep (1000);
				j = j - R;
				And = And + R;
				gotoxy (2,22);
				printf ("%5d",j);
				gotoxy (22,14);
				printf ("%5d",And);
			}
			else if (t == '2')
			{
				gotoxy (20,12);
				printf ("请选择要加注的数目 : (100 - 300)           ");
start6:
				gotoxy (64,18);
				puts ("      ");
				gotoxy (64,18);
				scanf ("%d",&I);
				if ( I > 300 || I < 100 )
				{
					while (getchar() != '\n');
					goto start6;
				}

				Sleep (500);
				j = j - I - R;
				And = And + I + R;
				gotoxy (2,22);
				printf ("%5d",j);
				gotoxy (22,14);
				printf ("%5d",And);

				Sleep(1000);

				if ( qiaopai (nam1) == 1 )
				{
					gotoxy (63,2);
					printf ("               ");
					gotoxy (63,2);
					printf ("卧槽 不跟了!!!");

					j = j + And;
					gotoxy (20,12);
					printf ("%s   胜                               " ,name);
				
					gotoxy (2 , 22);
					printf ("%5d",j);
					gotoxy (22,14);
					printf ("               ");
					goto end1;
				}
				else
				{
					gotoxy (63,2);
					printf ("              ");
					gotoxy (63,2);
					printf ("呵呵 跟你!");

					i = i - I ;
					And = And + I ;
					gotoxy (2,6);
					printf ("%5d",i);
					gotoxy (22,14);
					printf ("%5d",And);
				}

			}
			else if (t == '3')
			{
				i = i + And;
				gotoxy (2,6);
				printf ("%5d",i);
				gotoxy (22,14);
		   	    printf ("             ");
				gotoxy (20,12);
				printf ("人机胜 !!!!!                                      ");
				goto end1;

			}
			else
				goto start5;
		}
//////////////////////////////////
		else
		{
			gotoxy (63,17);
			puts ("请选择 :     ");
			gotoxy (20,12); 
			printf ("请 选择 1. 下注  2.弃牌                     ");
start7:
			gotoxy (64,18);
			puts ("         ");
			gotoxy (64,18);
			t = getchar();            //清空并输入

			if ( t == '1')
			{
 
				gotoxy (20,12); 
				printf ("请 %s 下注 :   ( 300 - 600)                     ",name);
start8:
				gotoxy (64,18);
				puts ("       ");
				gotoxy (64,18);
				scanf ("%d",&R);

				if (R < 300 || R > 600 )
				{
					while (getchar() != '\n');
					goto start8;
				}
				Sleep(3000);

				And = And + R;
				gotoxy (22,14);
				printf ("%5d",And);
				gotoxy (2,22);
				j = j - R;
				
				printf ("%5d",j);
				Sleep(500);

			if (qiaopai (nam1) == 1 && nam1[1].a <= 11)
				{
					gotoxy (63,2);
					printf ("       ");
					gotoxy (63,2);
					printf ("卧槽 不跟了!!!");

					j = j + And;
					gotoxy (20,12);
					printf ("%s   胜                               " ,name);
					goto end1;
				}
				else
				{
					gotoxy (64,4);
					puts ("跟！   ");
				
					i = i - R;
					gotoxy (2,6);
					printf ("%5d",i);
					And = And + R;
					gotoxy (22,14);
					printf ("%5d",And);
				}
			}
			else if ( t == '2' )
			{
				i = i + And;
				gotoxy (2,6);
				printf ("%5d",i);
				gotoxy (22,14);
		   	    printf ("             ");
				gotoxy (20,12);
				printf ("人机胜 !!!!!                              ");
				goto end1;
			}

			else
				goto start7;

		}

		Sleep (3000);

//=============================================== 开牌时刻=======================================================================================

		puke ( 12 ,1 );             
		gotoxy(14,2);
		paimian (&nam1[1]);

		puke (22 ,1 );
		gotoxy(24,2);
		paimian (&nam1[2]);

		gotoxy(34,2);
		paimian (&nam1[3]);
		gotoxy(44,2);
		paimian (&nam1[4]);
		gotoxy(54,2);
		paimian (&nam1[5]);
		Sleep(3000);
//===========================================决胜负===============================================================================
		if ( qiaopai (nam1) > qiaopai (nam2))
		{
			gotoxy ( 20 ,12 );
			puts ("人 机 胜 !!!!!!!                                   ");
			i = And + i;
			i = i + And;
			gotoxy (2,6);
			printf ("%5d",i);
			gotoxy ( 22, 14);
			printf ("             ");

		}
		else if ( qiaopai (nam1) < qiaopai (nam2))
		{
			gotoxy ( 20 ,12 );
			printf ("%s 胜 !!!!!!!                               ",name);
			gotoxy (22,14);
			puts("         ");
			j = j + And;
			gotoxy (2 , 22);
			printf ("%5d",j);
		}
		else
		{
			if ( daxiao (nam1,nam2) == 1)
			{
				gotoxy ( 20 ,12 );
				printf ("人 机 胜 !!!!!!!                            ");
				i = And + i;
				i = i + And;
				gotoxy (2,6);
				printf ("%5d",i);
				gotoxy ( 22, 14);
				printf ("             ");
			}
			else if (daxiao (nam1,nam2) == 2 )
			{
				gotoxy ( 20 ,12 );
				printf ("%s 胜 !!!!!!!                        ",name);
				j = j + And;
				gotoxy (2 , 22);
				printf ("%5d",j);
				gotoxy ( 22, 14);
				printf ("             ");
			}
			else 
			{
				gotoxy ( 20 ,12 );
				puts ("       平                                   ");
				gotoxy ( 22, 14);
				printf ("             ");

				if (K % 2 == 1)
				{
					j = j + 100;
					j = j + (And-100)/2;
					i = i + (And-100)/2;
				}
				else
				{
					i = i + 100;
					i = i + (And-100)/2;
					j = j + (And-100)/2;
				}

				gotoxy (2 , 22);
				printf ("%5d",j);
				gotoxy (2,6);
				printf ("%5d",i);
			}


		}
//====================================================================================================
end1:
		Sleep (10000);
		system ("cls");
		K++;
	}	

	if (j>=1000)
	{
		printf("%s     输！！！！！！！！");
	}
	else
		printf ("人机输！！！！！！！！！！！！");


	getchar ();


	return 0;
}                                    // ************************************ 主函数 *********************************************

void gotoxy ( int a , int b )                        //================坐标函数
{
	HANDLE hOutput;
	COORD loc;
	loc.X = a , loc.Y = b;
	
	hOutput = GetStdHandle (STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition (hOutput,loc);
	
}

void z_mian ( int a , int b )              //================样品扑克函数
{
	int x , y , a1 , b1;
	
	a1 = a , b1 = b;
	
	
	for ( y = 1 ; y <=14 ; y++)
	{
		gotoxy ( a1 , b1 );
		
		for ( x = 1 ; x <= 18 ; x++)
		{
			if ( y == 1 || y == 14)
				printf ("*");
			else
			{
				if ( x == 1 || x == 18)
					printf ("*");
				else
					printf (" ");
			}
			
		}
		
		b1++;
	}
	
	a1 = a + 8 , b1 = b +3 ;
	
	for ( y = 1; y <= 4; y++)
	{
		gotoxy ( a1 , b1);
		for ( x = 1 ; x <= (2*y-1) ; x++)
			printf ("*");
		a1-- , b1++;
	}
	
	a1 = a1 +2;
	
	for ( y = 3 ; y >= 1 ; y--)
	{
		gotoxy ( a1 , b1);
		
		for ( x = 1 ; x <= (2*y-1) ; x++)
			printf ("*");
		a1++ , b1++;
		
	}
}

void paizu (struct Sum *pai )                     //================完整牌组函数
{
	int a , int b;
	int t = 1;

	for ( b = 2 ; b <= 14 ; b++ )
		for ( a = 1 ; a <= 4 ;a ++)
		{
			pai[t].a = b;
			pai[t].b = a+2;
			t++;
		}

}
void qiepai (struct Sum *pai ,int n )              //================切牌函数
{
	int t;
	int x , y;

	Sum *pai1 = (struct Sum *) malloc (sizeof(Sum) * n );

	for ( t = 1 ; t <= n ; t ++)
		pai1[t] = pai[t];

	for ( t = n+1 ; t <= 52  ; t ++)
		pai[t-n] = pai [t];
	for ( x = n ,y = 52 ; x >= 1 ; x--,y--)
		pai [y] = pai1[x];

/*	for ( t = 1 ; t <= 52 ; t++)
	{
		printf("%d",pai[t].a);
		printf("%c\n",pai[t].b);
	}
*/	
}
void xipai ( struct Sum *pai ,int n )                      //================洗牌函数
{
	int x , y;
	int i;
	int t;
	Sum am;
	Sum *pai1 = (struct Sum *) malloc (sizeof(Sum) * 27);

	for ( i = 1 ; i <= n ; i++)
	{

	for (x = 1 , y = 27 ; y <= 52 ; x++ , y++)
		pai1[x] = pai[y];
	for ( x=1,y=26 ; x<y ; x++,y--)
	{
		am = pai1[x];
		pai1[x] = pai1[y];
		pai1[y] = am;
	}
	
	for ( x=26,y=52 ; x >= 1; x--,y=y-2)
		pai[y] = pai[x];
	for ( x=1,y=1 ; x <= 52 ; x=x+2,y++)
		pai [x] = pai1[y];


	for (x = 1 , y = 27 ; y <= 52 ; x++ , y++)
		pai1[x] = pai[y];
	
	for ( x=26,y=52 ; x >= 1; x--,y=y-2)
		pai[y] = pai[x];
	for ( x=1,y=1 ; x <= 52 ; x=x+2,y++)
		pai [x] = pai1[y];
	}

/*		for ( t = 1 ; t <= 52 ; t++)
	{
		printf("%d",pai[t].a);
		printf("%c\n",pai[t].b);
	}
*/
}

void puke ( int a , int b )                                      //================显示扑克函数
{
	int x , y;
	int a1 , b1;
	a1 = a , b1 = b;

	for ( y = 1 ; y <= 8 ; y ++)
	{
		gotoxy ( a1 , b1 );
		for ( x = 1 ; x <= 9; x++)
		{
			if ( y == 1 || y == 8 )
				printf ("*");
			else
			{
				if ( x == 1 || x == 9 )
					printf ("*");
				else
					printf (" ");
			}

		
		}
		b1++;
	}

	a1 = a +4 , b1 = b +3;

	for ( y = 1 ; y <= 3 ; y++)
	{
		gotoxy ( a1 , b1 );
		printf ("*");
		b1++;
	}

	a1-- , b1 = b1-2;
	gotoxy ( a1 , b1 );
	printf ("***");
}

void paimian ( Sum *pai )  //========================= 显示牌面值===============================
{
	if (pai->a  == 11)
		printf ("J %c",pai->b );
	else if (pai->a  == 12)
		printf ("Q %c",pai->b );
	else if (pai->a  == 13)
		printf ("K %c",pai->b );
	else if (pai->a  == 14)
		printf ("A %c",pai->b );
	else
		printf ("%d %c", pai->a ,pai->b );
}

int qiaopai (Sum * pai)  // ================= 判断牌类型 ==================================
{
	int One , x , y;
	int t;
	Sum pai1 , pai2;
	
	for ( y = 1 ; y <= 4 ; y++)
		for ( x = 1 ; x <= 5-y ; x++)
		{
			if ( pai[x].a < pai[x+1].a  )
			{
				pai1 = pai[x];
				pai[x] = pai[x+1];
				pai[x+1] = pai1;
			}
		}
		
	if ( pai[1].a == pai[2].a+1 && pai[1].a == pai[3].a+2 && pai[1].a == pai[4].a+3 && pai[1].a== pai[5].a+4 )  
	{
		if ( pai[1].b == pai[2].b && pai[1].b == pai[3].b && pai[1].b == pai[4].b && pai[1].b == pai[5].b)  //===== 同花顺
			One = 9;
		else
			One = 5;   //======== 顺子
	}
		
	else if( pai[1].a == pai[2].a && pai[1].a== pai[3].a && pai[1].a == pai[4].a || pai[2].a == pai[3].a && pai[2].a== pai[4].a && pai[2].a == pai[5].a )
	{
		if (pai[1].a != pai[2].a)
		{
			pai1 = pai[1];
			pai[1] = pai[5];
			pai[5] = pai1;
		}

		One = 8;           //====== 四条
	}
		
	else if ((pai[1].a == pai[2].a && pai[1].a== pai[3].a && pai[4].a == pai[5].a) || (pai[3].a == pai[4].a &&pai[3].a== pai[5].a && pai[1].a == pai[2].a ) )
	{
		if ( pai[3].a == pai[4].a &&pai[3].a== pai[5].a )
			for ( x = 1 ; x <= 2 ; x++)
			{
				pai1 = pai[x];
				pai[x] = pai[6-x];
				pai[6-x] = pai1;
			}
	
			One = 7;        //========葫芦
	}
		
	else if( pai[1].b == pai[2].b && pai[1].b == pai[3].b && pai[1].b == pai[4].b && pai[1].b == pai[5].b )
		One = 6;   //==========同花
		
	else if ( pai[1].a == pai[2].a && pai[1].a == pai[3].a || pai[2].a == pai[3].a && pai[2].a == pai[4].a || pai[3].a == pai[4].a && pai[3].a == pai[5].a)
	{
		if (pai[2].a == pai[3].a && pai[2].a == pai[4].a)
		{
			pai1 = pai[1];
			for ( x=2 ; x <= 4 ; x++)
				pai[x-1]  = pai[x];
			pai[4] = pai1;
		}
		else if (pai[3].a == pai[4].a && pai[3].a== pai[5].a)
		{
			pai1 = pai[1];
			pai2 = pai[2];
			for ( x = 3 ; x <= 5 ; x++)
				pai[x-2]  = pai[x];
			pai[4] = pai1;
			pai[5] = pai2;
		}
		
		One = 4;  //========三条
	}
		
	else if ((pai[1].a == pai[2].a && pai[3].a == pai[4].a) || (pai[2].a == pai[3].a && pai[4].a == pai[5].a) || (pai[1].a == pai[2].a &&pai[4].a == pai[5].a))
	{
		if (pai[2].a == pai[3].a)
		{
			pai1 = pai[1];
			for ( x = 2 ; x <= 5 ; x++)
				pai[x-1] = pai[x];
			pai[5] = pai1;
		}

		else if (pai[1].a == pai[2].a &&pai[4].a == pai[5].a)
		{
			pai1 = pai[3];

			for ( x = 3 ; x <= 4 ; x ++)
				pai[x] = pai [x+1];
			pai[5] = pai1;
		}
		
		One = 3;  //==== 两对
	}
		
	else if (pai[1].a == pai[2].a || pai[2].a == pai[3].a || pai[3].a == pai[4].a || pai[4].a == pai[5].a)
	{
		for ( x = 1 ; x <= 4 ; x++)
			if (pai[x].a ==pai[x+1].a )
			{
				pai1 = pai[x];
				pai2 = pai[x+1];
				break;
			}
		for (t = 3 ; t >= 1; t--)
		{
			if ( t < x )
				pai[t+2] = pai [t];
		}
		pai[1] = pai1;
		pai[2] = pai2;
		

			One = 2; // ========对子
	}


	else
		One = 1;  // ===高牌		
		
	return One;
		
}

Sum  choupai ( int *Q , Sum *pai )  //==============抽牌函数============
{
	int L , M;
	Sum pai1;

	if ( *Q > 52 )
	{
		*Q = 1;
		srand ( (unsigned)time (NULL));    // 产生随机数 
		L = rand () % 100;
		M = rand () % 52;
		xipai ( pai , L);
		qiepai (pai , M);
	}

	pai1 = pai [*Q];
	(*Q)++;                   // 指针数值递增要加括号

	return  pai1;
}
int daxiao (Sum *pai1 , Sum *pai2)
{
	int x , t;
	for ( x = 1 ; x <= 5 ; x ++)
	{
		if (pai1[x].a  > pai2[x].a )
		{
			t = 1;
			break;
		}
		else if (pai1[x].a  < pai2[x].a )
		{
			t = 2;
			break;
		}
		else
			t = 3;
	}
	return t;
}
void HideCursor(void)
{
CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}