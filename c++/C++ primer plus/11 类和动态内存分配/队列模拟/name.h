# ifndef NAME_H_
# define NAME_H_


class Customer
{
private :
	long arrive ;
	int process ;

public :
	Customer () {arrive = process = 0 ;}
	void set ( long when );
	long when () const { return arrive ;}
	int ptime () const { return process ;}

};


typedef Customer Item ; 

class Queue
{
private :
	
	typedef struct N_de
	{
		Item item ;                     // 存储单元为类对象
		struct N_de * next ;            // 用于指向下一个结构单元
	} NODE , *PNODE ;

	typedef struct Pking
	{
		PNODE  p1 ; 
		PNODE  p2 ;
	} FIND , *PFIND ; 

	enum {Q = 10};

	int items  ;                   //   用于记录队列对象多少
	FIND Link ; 
	const int qsize ;

	Queue (const Queue & q ): qsize (0) {}             //复制构造函数  -------------------?????????????????
	Queue  &  operator = (const Queue & q ) {return *this;}  //---------------------------????????????????????????
public:
	Queue (int qs = Q);
	~Queue ();
	bool isempty () const ;
	bool isful () const ;
	int queuecount () const ;
	bool enqueue (const Item & item );
	bool dequeue (Item & item);
};
# endif 