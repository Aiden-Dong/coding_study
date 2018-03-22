# include <stdio.h>
# include <string.h>

char * recive_one () ;
char * recive_two () ;
char * recive_three () ;
char * recive_four () ;

int main ()
{
	printf ("%s" , recive_one ()) ;
	printf ("%s" , recive_two ()) ;

	printf ("%d\n" , recive_one ()) ;
	printf ("%d\n" , recive_three ()) ;

	printf ("%s" , recive_four ()) ;

	return 0 ;
}

char * recive_one ()
{
	char *p1 = "hellow world !!\n" ;	// 常量/全局变量 属于系统管理 当程序调用完毕时才释放掉内存 
	return p1;							// 与局部变量存放位置是不同的
}

char * recive_two ()
{
	char *p1 = "I will hold on !!\n" ;
	return p1 ;
}

char * recive_three () 
{
	char * p1 = "hellow world !!\n" ;	// 此处的重点是两个相同的字符串位于常量区时 ， 编译器不会另外分配空间
										// 只是调用原数据 
	return p1 ;
}
char * recive_four () 
{
	char buf [30] ;

	strcpy (buf , "hellown world!!\n") ;

	return buf ;
}


/*
在 VC++6.0 的运行环境中 :
============================、
hellow world !!
I will hold on !!
4333604
4333604
============================
*/