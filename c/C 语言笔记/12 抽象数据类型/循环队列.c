# include <stdio.h>
# include <stdlib.h>

typedef struct {
	int * Queue ;
	int front ;
	int rear;
} QUEUE , *PQUEUE ;

void init_queue (PQUEUE Q) ;	 // 初始化队列
void in_queue (PQUEUE Q , int a) ;	 // 入队
int out_queue (PQUEUE Q , int *pVal) ; // 出队 
void traverse_queue (PQUEUE Q ) ;	//遍历队列
int full_queue (PQUEUE Q ) ;	//检查栈满
int empty_queue (PQUEUE Q ) ;	//检查栈空

int main ()
{
	QUEUE Qu ;
	char t ;
	int r ;

	init_queue (&Qu) ;
	puts ("请选择 :") ;
	puts ("1. 入队") ;
	puts ("2. 出队") ;
	puts ("3. 遍历队列");
	puts ("else. 退出队列");

	t = getchar () ;

	while(t =='1' || t=='2' || t=='3')
	{
		switch (t)
		{
			case '1' :
				puts ("请输入要输入的数字 :");
				scanf ("%d",&r);
				
				in_queue (&Qu , r) ;
				break ;
			case '2':
				if (out_queue (&Qu , &r)) 
					printf ("出栈值 : %d" , r);
				break ;
			case '3':
				traverse_queue (&Qu) ;
				break ;
		}
	getchar () ;
	puts ("请选择 :") ;
	puts ("1. 入队") ;
	puts ("2. 出队") ;
	puts ("3. 遍历队列");
	puts ("else. 退出队列");
	t = getchar () ;


	}

	return 0 ;
}
void init_queue (PQUEUE Q)
{
	Q->Queue = (int *) malloc (6*sizeof (int)) ;
	Q->front = 0 ;
	Q->rear = 0 ;	// 初始化队列
}
void in_queue (PQUEUE Q , int a) 
{
	if (full_queue(Q))
		puts ("队列已满请稍候 !!!") ;
	else
	{
		Q->Queue[Q->rear] = a ;
		Q->rear = ( Q->rear+1) % 6 ; 
	}
}

int out_queue (PQUEUE Q , int *pVal) 
{
	if (empty_queue(Q))
	{
		puts ("队列中无元素 !!!") ;
		return 0;
	}
	else
	{
		*pVal = Q->Queue [Q->front] ;
		Q->front =( Q->front +1 ) % 6 ;
		return 1 ;
	}
}
void traverse_queue (PQUEUE Q ) 
{
	int i = Q->front ;

	if (empty_queue(Q))
		puts ("队列中无元素 !!!") ;
	else
	{
		while (i!=Q->rear)
		{
			printf ("%d->" , Q->Queue[i]) ;
			i = (i+1)%6 ;
		}
		puts ("end") ;
	}
	
}
int full_queue (PQUEUE Q )
{
	return (Q->rear + 1)%6 == Q->front ;
}
int empty_queue (PQUEUE Q)
{
	return Q->rear == Q->front ;
}