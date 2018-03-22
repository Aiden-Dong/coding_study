# include <iostream>
# include <string>

struct namedf
{
	char str[20];
	int a ;
	int b;
	double c;
};

struct ndagg
{
	std::string str;
	int a ;
	double b;
	char c;
};

int main ()
{
	namedf name1 =   // 必须在声明同时初始化
	{
		"saligia",
			23.5,
			12,
			23.0,
	};
	



	ndagg *p = new ndagg;

	p ->str  = "deasgg";

	



	return 0;
}