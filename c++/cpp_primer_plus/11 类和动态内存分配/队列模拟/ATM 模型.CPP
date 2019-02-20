# include <iostream>
# include <cstdlib>
# include <ctime>
# include "name.h"

const int M = 60 ;

bool newcustom (double x);

int main ()
{
	using std::cout ;
	using std::cin ;
	using std::endl ;
	using std::ios_base ;

	srand (time (0));

	cout << "这里是 ＡＴＭ　模型!!!!" << endl;
	cout << "请输入一个队列所能容纳的最大值  : " << endl ; 

	int qs ;

	cin >> qs ; 

	Queue line (qs);

	cout << "请输入所等待的时间 (小时) :" << endl; 

	int hourse ;

	cin >> hourse ;

	long cycle = M * hourse ;

	cout << "请输入平均要等待的时间 :" << endl ; 

	double perhourse ;
	cin >> perhourse ;

	double min_per ; 
	min_per = M / 60 ; 


	Item temp ; 

	long turnaways = 0 ; 
	long custome = 0 ; 
	long server = 0 ; 
	long sum_line = 0 ;
	long wait_time = 0 ;
	int line_wait = 0;

	for (int cyc = 0 ; cyc < cycle ;  cyc++)
	{
		if (newcustom (min_per))
		{
			if (line.isful ())       // 判断满队否
				turnaways ++;        // 
			else 
			{
				custome ++;
				temp.set (cyc);
				line.enqueue (temp);  // 加入新队列
			}
		}
	

		if (wait_time <= 0 && !line.isempty ())   // 队列不空
		{
			line.dequeue (temp);
			wait_time = temp.ptime ();
			line_wait += cyc - temp.when () ; 
			server ++;
		}

		if (wait_time > 0)
			wait_time--;

		sum_line += line.queuecount ();           // 队列中的个数；

	}

	if (custome > 0)
	{
		cout << "coustom = " << custome << endl;
		cout  << "custome srever = " << server << endl;
	}
	return 0 ;
}

bool newcustom (double x)
{
	return (rand () * x / RAND_MAX <1 );
}