# include <iostream>

typedef struct job{
	char name[40];
	double salary ;
	int foor;
} JOB , *PJOB;

template <typename T>
void s_wap (T & a , T & b);

template <>void s_wap <JOB>(JOB &j1 , JOB & j2);  //  模版具体化方案

void show (JOB & j);

int main ()
{
	using namespace std ;

	cout.precision(2);
	cout.setf (ios::fixed , ios::floatfield);

	int i = 10, j = 20;

	cout << "现在的 i , j == " << i << " , " << j << endl;
	cout << "使用模版函数 swap()后:" << endl;

	s_wap (i , j);
	cout << "现在的 i , j == " << i << " , " << j << endl;

	JOB sue = {"saligia" , 73000.60 , 7 };
	JOB side = {"Sideney Taffee" , 78060.72 , 9};

	show (sue);
	show (side);

	cout << "使用模版函数 swap() 后 " << endl;

	s_wap (sue , side);

	show (sue);
	show (side);

	return 0 ;
}

template <typename T>
void s_wap (T & a , T & b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <> void s_wap <JOB> (JOB & j1 , JOB & j2)
{
	double t1;
	int t2 ;
	t1 = j1.salary ;
	j1.salary  = j2.salary ;
	j2.salary  = t1;

	t2 = j1.foor ;
	j1.foor = j2.foor ;
	j2.foor = t2;
} 
void show (JOB & j)
{
	using namespace std ;

	cout << j.name  << " :  $" << j.salary  << " on floor " << j.foor << endl;
}
/*
在 VC++ 6.0 中的输出结果是 ：
==============================
现在的 i , j == 10 , 20
使用模版函数 swap()后:
现在的 i , j == 20 , 10
saligia :  $73000.60 on floor 7
Sideney Taffee :  $78060.72 on floor 9
使用模版函数 swap() 后
saligia :  $78060.72 on floor 9
Sideney Taffee :  $73000.60 on floor 7
Press any key to continue
==============================
*/