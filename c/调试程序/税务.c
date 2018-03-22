# include <stdio.h>

int main ()
{
	double m , n , t ;

	printf ("。。。。。。。。\n");
	printf ("最低 3500元\n");
	printf ("税前收入 : ");

	scanf ("%lf",&m);

	if (m <= 3500)
		t = 0 ;
	else
	{
		n = m-3500 ;
		if(n <= 1500)
			t = n*0.03-0 ;
		else
			if (n>1500&&n<=4500)
				t=n*0.10-105;
			else
				if (4500 < n&& n <= 9000)
					t=n*0.25-1005;
	}

	printf ("所得 : %lf",t);


	return 0 ;
}
