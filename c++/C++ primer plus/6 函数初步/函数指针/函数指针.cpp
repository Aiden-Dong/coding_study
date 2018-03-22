# include <iostream>

const double * f1 (const double ar[] , int n);
const double * f2 (const double ar[] , int n);
const double * f3 (const double ar[] , int n);

int main ()
{
	using namespace std;

	double av[3] = { 112.2 , 124.5 , 239.56};
	const double *(*p1) (const double ar[] , int n) = &f1;        // ??????????  此处应与下解释有关  等价于 f1;

//	 等价于  auto p1 = f1;                                                 C++ 11 新内容

	cout << "Using pointers to function :" << endl;
	cout << "Adress value" << endl;

	cout << (*p1) (av,3) << ": " << *(*p1)(av , 3) << endl;     //  (*p1) (av,3) 返回地址  *(*p1)(av , 3)  返回此地址的内容    
	cout << f2(av , 3) << ": " << *f2(av ,3) << endl;
	cout << "p1 = " << sizeof (p1) << endl << endl;              // p1 为指针 所以占 4 个字节 
//	cout << "f1 = " << sizeof (f1) << endl << endl;


    const double *(*pa[3])(const double ar[] , int n) = { f1 , f2 , f3 };
	
	cout << "Using pointers to function :" << endl;
	cout << "Adress value" << endl;

	for (int i = 0 ; i < 3; i++)
		cout << pa[i](av,3) << ": " << *pa[i] (av,3) << endl;    // 此处的 pa[i] 可以相当于 (*pa)[i]   这是规定

	cout << endl;

	const double * (**pb)(const double ar[] , int n) = pa;
	for (int j = 0 ; j < 3; j++)
		cout << pb[j](av,3) << ": " << *pb[j] (av,3) << endl;

	typedef const double * (*p_fun) (const double ar[] , int n);   //使用  typedef 创建类型别名

	p_fun p5 = f3;
	cout << p5(av , 3) << ": " << *p5(av ,3) << endl;

	p_fun pc[3] = {f1 , f2 , f3};
	for (int k = 0 ; k < 3; k++)
		cout << pc[k](av,3) << ": " << *pc[k] (av,3) << endl;

	return 0;

}

const double *f1 ( const double ar[] , int n)
{
	return ar;
}

const double *f2 (const double ar[] , int n)
{
	return ar+1;
}

const double *f3 (const double ar[] , int n)
{
	return ar+2;
}
/*
在 VC++ 6.0 中的输出结果是 ：
=======================================
Using pointers to function :
Adress value
0012FF30: 112.2
0012FF38: 124.5
p1 = 4

Using pointers to function :
Adress value
0012FF30: 112.2
0012FF38: 124.5
0012FF40: 239.56

0012FF30: 112.2
0012FF38: 124.5
0012FF40: 239.56
Press any key to continue
=======================================
*/
