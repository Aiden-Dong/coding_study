
# include <iostream>

typedef struct Stact{
	char a[20];
	int n;
	Stact * New ;

} NOTE , *PNOTE;

typedef struct s_taic{
	PNOTE HEAD;
	PNOTE END;
}SOUT , *PSOUT;

void stact_1 (PSOUT ps);
void stact_2 (PSOUT ps);
void stact_3 (PSOUT ps );
void stact_4 (PSOUT ps );
 
int main ()
{
	SOUT s;

	stact_1(&s);
	stact_2(&s);
	stact_3(&s);
	stact_4(&s);

	return 0;
}
void stact_1 (PSOUT ps)
{
	PNOTE Newd;
	
	if ((Newd = new NOTE) == NULL)
	{
		std::cout << "未分配成功 ！！" << std::endl ;
		exit (-1);
	}
	else
	{
		ps->HEAD =  Newd;
		ps->END = Newd;
		Newd->New = NULL;
	}

}
void stact_2 (PSOUT ps)
{
	using namespace std;

	cout << "是否录取信息 :" << endl;
	cout << "继续选择 1" << endl;
	
	int t;
	cin >> t;

	if ( t == 1)
		while (1)
		{
			if (t != 1)
				break;
			stact_3(ps);
			cout << "是否录取信息 :" << endl;
			cout << "继续选择 1" << endl;
			cin >> t;
			
		}
}
void stact_3 (PSOUT ps )
{
	PNOTE Nead = new NOTE;
	
	if ((Nead = new NOTE) == NULL)
	{
		std::cout << "未分配成功 ！！" << std::endl ;
		exit (-1);
	}
	else
	{
		Nead->New = ps->HEAD ;
		ps->HEAD = Nead;
	}

	std::cout << "请输入姓名 :" << std::endl;
	std::cin >> Nead->a ;
	std::cout <<"请输入学号" << std::endl;
	std::cin >> Nead->n ;
}
void stact_4 (PSOUT ps )
{
	PNOTE p = ps->HEAD ;

	while (p != ps->END)
	{
		std::cout << "姓名 : " << p->a << std::endl;
		std::cout << "学号 : " << p->n << std::endl;
		p = p->New ;
	}
}
