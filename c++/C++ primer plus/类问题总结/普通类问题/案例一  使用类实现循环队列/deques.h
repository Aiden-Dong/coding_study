# ifndef DEQUES_H_
# define DEQUES_H_

class deque_s {
private:
	enum {SUM = 6} ;

	int Gether [SUM] ;	// 队列容器
	int front ;			// 队列头指针
	int rear ;			// 队列尾指针
	int sum ;			// 容器中的元素数目

	bool empty_deque ()const { return sum == 0 ;}	// 判断队列是否为空
	bool fill_deque () const {return sum == SUM ;}	// 判断是否栈满
public:
	deque_s () ;	// 默认构造函数
	
	bool push_deque (int a)  ;	// 将元素插入到队尾 
	bool pop_deque (int &a) ;	// 从队首删除元素
	void show_deque (void) ;	// 遍历队列
} ;

# endif 