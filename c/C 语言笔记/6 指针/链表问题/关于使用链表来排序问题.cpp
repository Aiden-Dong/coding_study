# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct Card{
	char name [15];       // 存放姓名
	char card[20];        // 存放学号
	struct Card * Next ;  // 指向下一个结点
} NOTE , *PNOTE ;  

void push (NOTE ** HEAD , char * name , char * card) ; // 压栈
void watch (PNOTE One) ;                               // 遍历整个栈区 

int main ()
{
	char name [15] ;
	char card [20] ;
	int  a ;           // 用于记录选择 
	PNOTE HEAD = NULL; // 首栈指针 暂时没有实际的内存区
	
	while (a != 3)
	{
	printf ("是否选择压入新成员 :\n 1: 压入新成员 \n 2: 遍历文件\n");


	scanf ("%d" , &a) ;

	if (a == 1 || a == 2 )
	{
start:
		getchar () ;

		switch (a)
		{
		case 1 :	// 选择压栈 
			puts ("请输入姓名 : ") ;
			gets (name) ;
			puts ("请输入学号 : ") ;
			gets (card) ;
			push (& HEAD , name , card) ; // 将姓名跟学号压入栈中 
			break ;
		case 2:	// 遍历全栈
			watch (HEAD) ;
			break ;
		}
	}
	
	else
	{
		printf ("请重新选择 !!!!\n") ;
		while (getchar() != '\n') ;
		goto start ;
	}
	}


	return 0 ;
}

//====== 经典排序压栈方法====================
void push (NOTE ** HEAD , char * name , char * card)  
{
	PNOTE curunt ;
	PNOTE previous ;
	PNOTE New ;

	curunt = * HEAD ; 
	// 初始化为指向首地址   
	// 注意 curunt 为副本
	// curunt 也有两种可能 1 为空 , 2 指向链表首指针
	previous = NULL ; 
	// 初始化为空指针

	while (curunt != NULL && strcmp (curunt->card , card) < 0)
	{
		previous = curunt ;		
		curunt = curunt->Next ; 
	}
	// previous 用于指向要插入的结点位置
	// curunt 用于指向要插入的结点位置的下一个结点
	
	New = (PNOTE) malloc ( sizeof (NOTE) ) ;
	strcpy (New->card , card) ;
	strcpy (New->name , name) ;
	// 分配内存 为存入数据做准备

	New->Next  = curunt ;  // 将新节点的下一个结点位置指向要插入处

	if (previous == NULL)
		*HEAD = New ;      // 此处有两种可能 
						   // 1 是最初的指针为空
						   // 2 是要插入的值最小 
	else 
		previous->Next = New ;
}
//====== 经典排序压栈方法====================

void watch (PNOTE One)
{
	if (One != NULL)
		while (One != NULL)
		{
			printf ("姓名 : %s \n" , One->name );;
			printf ("学号 : %s \n" , One->card );
			printf ("\n");
			One = One->Next ;
		}
	else
		printf ("此栈为空!!!\n") ;
}