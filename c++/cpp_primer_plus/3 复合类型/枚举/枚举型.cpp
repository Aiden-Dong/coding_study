# include <iostream>

enum color { red=1 , orange , yellow , green , blue , violet , indigo };

int main (void)
{
	using namespace std;

	color mode;

	mode = yellow; //不能将数值直接付给 mode;

	cout <<"mode = "  << mode << endl;

	mode = color (4);  //第二种赋值方式
	cout <<"mode = "  << mode << endl;

	return 0;

}