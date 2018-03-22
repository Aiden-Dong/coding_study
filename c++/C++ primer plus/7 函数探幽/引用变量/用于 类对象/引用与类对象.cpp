# include <iostream>
# include <fstream>
# include <cstdlib>

using namespace std;

void file_it (ostream &os , double fo , const double fe[] , int n);

int main ()
{


	ofstream fout;

	fout.open ("name.txt");

	if (!fout.is_open() )  // 此处直接调用 不需要参数
	{
		cout << "error to opening file !"<< endl;

		exit (-1);
	}

	double object;

	cout << "请输入一组数据 : " << endl;

	cin >> object;

	double eps [5];

	for (int i = 0 ; i < 5 ; i++)
	{
		cout  << "请输入第 " << i+1 << " 组数据" << endl;

		cin >> eps[i];
	}

	file_it ( fout , object , eps , 5);
	file_it ( cout , object , eps , 5);

	cout << "Down!!\n";


	return 0;
}

void file_it (ostream &os , double fo , const double fe[] , int n)
{
	ios_base::fmtflags initial;              //  ios_base::fmtflags 用于存储 setf () 所需的数据类型

	initial = os.setf (ios_base::fixed );    // 将对象用于使用定点表示的模式

	os.precision (0);

	os << "Focal length of objective : " << fo << " mm\n";  // ios_base 的类型决定于 precision 的格式

	os.setf (ios_base::showpoint);

	os.precision (2);                        //  precision () 函数指定了 要显示的浮点数的长度  (小数点后位数) 

	os.width (12);

	os << "f.l. eyepiece" << endl;

	os.width (15);

	os << "magnification" << endl;

	for (int i = 0 ; i < n ; i++)
	{
		os.width (12);                    // 指出了 (下一次输出) 操作使用的字段宽度
		os << fe[i];
		os.width (15);
		os << int(fo/fe[i] +0.5) << endl; 
	}

	os.setf (initial);
}
/*
在 VC++ 6.0 中的输出结果是 ：
=============================
请输入一组数据 :
78.2
请输入第 1 组数据
12.1
请输入第 2 组数据
13.2
请输入第 3 组数据
14.2
请输入第 4 组数据
15.234
请输入第 5 组数据
13.234
Focal length of objective : 78 mm      // 小数点后为 0 位；
f.l. eyepiece
  magnification
       12.10              6
       13.20              6
       14.20              6
       15.23              5
       13.23              6
Down!!
Press any key to continue
=============================
*/