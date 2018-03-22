# include <iostream>
# include "deques.h"

int main ()
{
	using std::cout ;
	using std::endl ;
	using std::cin ;

	deque_s one ;

	cout << "队列模型以实现 ， 请选择 :" << endl
		<< "1 . 入队 " << endl 
		<< "2 . 出队 " << endl
		<< "3. 遍历队列" << endl; 

	int a ;
	cin >> a ; 

	while (a == 1 || a == 2 || a == 3)
	{
		int t ;

		switch (a)
		{
		case 1:
			cout << "请输入入队元素 :" ;
			cin >> t ;
			if (! one.push_deque(t))
				cout << "队列已满 ， 请稍后再重新将元素存入队列" << endl ;
			break ;

		case 2 :
			if (one.pop_deque (t))
				cout << "正在处理元素 : " << t << endl ;
			else
				cout << "队列中以空 ， 无元素处理 " << endl ;
			break ;
		case 3 :
			one.show_deque () ;

		}

		cout <<endl
			<<"1 . 入队 " << endl 
			<< "2 . 出队 " << endl
			<< "3. 遍历队列" << endl; 

		cin >> a ;

	}
	 
	return 0 ;
}
/*
在 VC++6.0 的运行环境中 :
===============================
队列模型以实现 ， 请选择 :
1 . 入队
2 . 出队
3. 遍历队列
1
请输入入队元素 :14

1 . 入队
2 . 出队
3. 遍历队列
3
队列元素 :  14 ->  End
front = 0
rear = 1
sum = 1

1 . 入队
2 . 出队
3. 遍历队列
1
请输入入队元素 :45

1 . 入队
2 . 出队
3. 遍历队列
3
队列元素 :  14 -> 45 ->  End
front = 0
rear = 2
sum = 2

1 . 入队
2 . 出队
3. 遍历队列
1
请输入入队元素 :78

1 . 入队
2 . 出队
3. 遍历队列
3
队列元素 :  14 -> 45 -> 78 ->  End
front = 0
rear = 3
sum = 3

1 . 入队
2 . 出队
3. 遍历队列
1
请输入入队元素 :34

1 . 入队
2 . 出队
3. 遍历队列
3
队列元素 :  14 -> 45 -> 78 -> 34 ->  End
front = 0
rear = 4
sum = 4

1 . 入队
2 . 出队
3. 遍历队列
1
请输入入队元素 :56

1 . 入队
2 . 出队
3. 遍历队列
3
队列元素 :  14 -> 45 -> 78 -> 34 -> 56 ->  End
front = 0
rear = 5
sum = 5

1 . 入队
2 . 出队
3. 遍历队列
1
请输入入队元素 :67

1 . 入队
2 . 出队
3. 遍历队列
3
队列元素 :  14 -> 45 -> 78 -> 34 -> 56 -> 67 ->  End
front = 0
rear = 0
sum = 6

1 . 入队
2 . 出队
3. 遍历队列
1
请输入入队元素 :23
队列已满 ， 请稍后再重新将元素存入队列

1 . 入队
2 . 出队
3. 遍历队列
3
队列元素 :  14 -> 45 -> 78 -> 34 -> 56 -> 67 ->  End
front = 0
rear = 0
sum = 6

1 . 入队
2 . 出队
3. 遍历队列
2
正在处理元素 : 14

1 . 入队
2 . 出队
3. 遍历队列
3
队列元素 :  45 -> 78 -> 34 -> 56 -> 67 ->  End
front = 1
rear = 0
sum = 5

1 . 入队
2 . 出队
3. 遍历队列
6
Press any key to continue
====================================
*/