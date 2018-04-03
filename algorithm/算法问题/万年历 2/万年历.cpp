//w=y+[y/4]+[c/4]-2c+[26(m+1)/10]+d-1

# include <stdio.h>
# include <conio.h>

int week_day ( int year , int month , int day);
void  week_1 ( void );
int leap (int year);
void month_ly ( int year ,int *months , int * day ,int t);
void month_all (int *months , int * day );

 
int main (void)
{
	int year ;
	int l , t;
	int days [32] , months[13] = {0,31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31};
	char *str1[] = {
		"1：要求输入年份，判断是否闰年.\n",
		"2：输入年月日，判断星期几.\n",
		"3：输入年份，月份，打印出本月日历.\n",
		"4：输入年份，打出12个月的月历.\n"
	};
	char ch , i = 0 ;
	

	while (i != 4)
		puts (str1[i++]);

	for ( i = 1 ; i <= 31 ; i++)
		days[i] = i;

	while (1)
	{
start1:	
	scanf ("%d",&l);

	switch (l)
	{
		case 1:
			puts ("请输入年份 :");
			scanf ("%d",&year);
			if (leap(year))
				puts ("这一年是闰年 !!!");
			else
				puts ("这一年不是闰年!!");
			break;

		case 2:
			week_1();
			break
				;
		case 3:
			puts ("请输入年月份 :");
start3:
			puts ("格式 year-month");
			scanf ("%d-%d",&year,&t);
			if (t>= 1 && t <= 12)
				month_ly(year,months,days,t);
			else
			{
				while ( getchar() != '\n');  // 接受错误字符
				puts ("您的输入有误 ， 请重新输入:");
				goto start3;
			}
			break;

		case 4:
			month_all(months,days);
			break;

		default:
			getchar ();  //对于意外的错误情况 先清掉缓冲区的错误字符 （错误情况如果是输入了非数字字符 则清掉字符 否则缓冲区只剩换行符 ）
		    
	}
	getchar ();
	puts ("如果要结束请按 Y/y  继续运行请按任意键 :");

	ch = getch ();

	if ( ch == 'Y' || ch == 'y')
		break;
	else
		puts ("请重新选择 :");
	}

	return 0;
}
int week_day ( int year , int month , int day)  //判断星期函数  原型
{
	int c , y;

	if (month < 3)
	{
		month = month + 12;
		year --;
	}

	c=year/100 , y=year%100;

	int week=int(c/4)-2*c+int(y+y/4)+int(13*(month+1)/5)+day-1;

	while(week<0)
		week+=7; 
	return week%7;
}

void  week_1 (void)  // 判断星期函数  调用
{
	int year , month , day;
	printf ("请输入要查询的日期 :\n\n");
start2:
	puts ("输入格式 : year-month-day!!");

	scanf ("%d-%d-%d", &year, &month,&day);

	if (month >= 1 && month <= 12)
		printf ("\n\n今天是周  %d\n\n",week_day( year , month , day ) );
	else
	{
		while ( getchar() != '\n');  // 接受错误字符
		puts ("您的输入有误 ， 请重新输入:");
		goto start2;
	}
}
int leap (int year)
{
	bool i = 0;

	if ( year%100 == 0 )
		if ( year % 400 == 0)
			i = 1;
	else 
		if ( year%4 == 0)
			i = 1;

	return i;
}

void month_ly ( int year,int *months , int * day , int t )
{
	int week1 , i = 1 , Week;

	Week = months[t];

	if (leap(year))
		if (t==2)
			Week = months[t]+1;

	week1 = week_day( year , t , 1 );

	puts ("=======================================================");
	puts ("Sun. Mon. Tue. Wed. Thu. Fri. Sat. ");

	for (i = 0 ; i < week1 ; i++)
		printf ("     ");

	for ( i = 1 ; i <= Week ; i++)
	{
		printf ("%-5d",day[i]);

		if (week1++ == 6)
		{
			week1 = 0;
			printf ("\n");
		}
	}
	printf ("\n");
	puts ("=======================================================");
}
void month_all (int *months , int * day )
{ 
	int year , t;

	puts ("请输入年份");

	scanf ("%d",&year);

	for (t = 1 ; t <= 12 ; t++)
		month_ly ( year , months , day , t );
}
