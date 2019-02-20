# include <iostream>
# include <string>
# include <new>

using namespace std;
const int B = 512;

class Jusr
{
private :
	string worlds ;
	int number ;
public:
	Jusr (const string & s = "First" , int n = 0)
	{worlds = s ; number = n ; cout <<  worlds << " 已被创建!!!" ;}

	~Jusr ()
	{cout << worlds << " 已被释放!!!!" << endl;}

	void show (){cout << worlds << "," << number << endl;}

};

int main ()
{
	{
	char * buffer = new char[B];

	Jusr * pc1 , * pc2 ;

	pc1 = new (buffer) Jusr ;
	pc2 = new Jusr ("Heap1" , 20 );
	cout << endl;

	cout << "buffer 的地址为 : " << (void *) buffer << endl ;
	cout << "pc1 的地址为 : " << pc1 << endl;
	pc1->show();
	cout << "pc2 的地址为 : " << pc2 << endl;
	pc2->show();

	pc1->~Jusr ();    // 对于 new 定位运算符 必须显示的调用 析构函数   // 在释放 分配区域
	delete pc2;       // new 分配的内存 ， 要使用 delete 释放；
	delete[] buffer ;
	}

	return 0;

}
/*
在 VC++ 6.0 中的输出结果是 ：
==============================
First 已被创建!!!Heap1 已被创建!!!
buffer 的地址为 : 00682A80
pc1 的地址为 : 00682A80
First,0
pc2 的地址为 : 00682D10
Heap1,20
First 已被释放!!!!
Heap1 已被释放!!!!
Press any key to continue
==============================
*/