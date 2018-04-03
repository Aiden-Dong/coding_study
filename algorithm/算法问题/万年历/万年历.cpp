/*C语言编程万年历
1：要求输入年份，判断是否闰年；
2：输入年月日，判断星期几；
3：输入年份，月份，打印出本月日历;
4：输入年份，打出12个月的月历；
用多个函数实现。*/

#include<stdio.h>

int Leap(int year);
void allMonth(int year) ;
void Monthly(int year,int month);
int WeekDay(int year,int month,int day);

int calendar[12][6][7];//月历
char* week[]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Satarday"};
char* Monthname[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
int monthday[]={31,28,31,30,31,30,31,31,30,31,30,31};  // 记录最大天数
/*操作菜单*/
char* menu[]={
		"1：要求输入年份，判断是否闰年.\n",
		"2：输入年月日，判断星期几.\n",
		"3：输入年份，月份，打印出本月日历.\n",
		"4：输入年份，打出12个月的月历.\n"};
	
	

int main( void )
{
	int year,month,day,i,n,weekday;
	
	for(i=0;i<4;i++)
		printf("%s",menu[i]);
	
	while(1)
	{
		printf("\n请输入你的选择:\n");

		scanf("%d",&n);

		switch(n)
		{
		case 1:
			printf("请输入年份:\n");
			scanf("%d",&year);
			if(Leap(year)) printf("%d 是闰年.\n",year);
			else printf("%d 不是闰年.\n",year);
			break;

		case 2:
			printf("请输入 年 月 日:\n");
			scanf("%d%d%d",&year,&month,&day);
			weekday=WeekDay(year,month,day);
			printf("这天是 %s\n",week[weekday]);
			break;

		case 3:
			printf("请输入年份和月份\n");
			scanf("%d%d",&year,&month);
			Monthly(year,month);
			break;

		case 4:
			printf("请输入年份\n");
			scanf("%d",&year);
			allMonth(year);
			break;

		default:
			getchar();
			printf ("请重新输入 :\n");
			
		}
	}
 //getchar();   //按任意键，程序退出
	return 0;
}

//输入年份，打印出12个月的月历
void allMonth(int year)  
{
	int i;
		
	for(i=1 ; i<=12 ; i++)
	{
		Monthly(year,i);
		getchar();//按任意键继续执行
	}
}
	
/*输入年月日，判断星期几，利用Zeller公式w=y+[y/4]+[c/4]-2c+[26(m+1)/10]+d-1
w是结果星期数，y是年份的后两位，c是年份的前两位，m是月份，当3≤m≤14，也就是当
m≤2时，要算到前一年的13月份和14月份，最后要将w对7取模*/
int WeekDay(int year,int month,int day)
{
	int w,y,c,m,d;

	c=year/100;

	if(month<3)
	{
		m=12+month;
		y=year%100-1;
	}
	else
	{
		m=month;
		y=year%100;
	}

	d=day;
	
	w=y+y/4+c/4-2*c+26*(m+1)/10+d-1;

	return (w%7+7)%7;
	
}
	
	
/*输入年份，月份，打印出本月的日历*/
void Monthly(int year,int month)
{
	int weekday , i , j;
	
	if(month==2)
		if(Leap(year)) 
			monthday[1]+=1;
			
	weekday=WeekDay(year,month,1);
			
	printf("%s\n",Monthname[month-1]);
			
	printf("Sun. Mon. Tue. Wed. Thu. Fri. Sat.\n");
			
	for( i = 1,j = weekday ; i <= monthday[month-1] ; i++ , j++)
	{
		calendar[month-1][j/7][j%7]=i;
	}

	for(i=0;i<6;i++)
	{
		for(j=0;j<7;j++)
		{
			if(calendar[month-1][i][j]==0) 
				printf("     ");
			else 
				printf("%-5d",calendar[month-1][i][j]);
		}
			
		printf("\n");
	}
}
	
/*判断参数year传递的年份是否是闰年*/
int Leap(int year)
{
	if(year%4==0&&year%100!=0||year%400==0) 
		return 1;
	else 
		return 0;
}	
	
	
