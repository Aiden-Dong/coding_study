# ifndef STACK_H_
# define STACK_H_

template <class T>
class stack 
{
private:
	enum {Size = 10} ;
	int stacksize ;   // 记录最大栈区 
	T * items ;       // 保存栈内容
	int top ;         // 记录实际栈大小
public:
	explicit stack (int ss = Size);   // 默认参数
	~stack () {delete [] items ;}
	bool isempty () {return top== 0 ;}
	bool isfull () {return top == stacksize ;}
	void push (const T & item );   // 压栈
	void pop (T & item);           // 出栈
};

template <class T>
stack<T>::stack (int ss) : stacksize (ss) , top (0)
{
	items = new T [stacksize] ;   // 此处只分配了 T (指针) 的空间 
}

template <class T>
void stack<T>::push (const T & item )
{
	items[top++] = item ; 
}
template <class T>
void stack<T>::pop (T & item)
{
	item = items[--top]; 
}

# endif