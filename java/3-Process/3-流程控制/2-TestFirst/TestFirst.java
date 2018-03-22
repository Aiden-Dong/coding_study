class Triager{			//三角形对象 
	int 	a;
	int 	b;
	int 	c;

	int triager_len()
	{
		return a+b+c;
	}

	double triager_sin()
	{
		return(a+b+c)/2.0;	
	}
}

class TriagerTest{
	public static void main(String arg[])
	{
		Triager one = new Triager();
		one.a 	= 3;
		one.b	= 4;
		one.c	= 5;
		
		System.out.printf("三角形周长 : %d\n", one.triager_len());
		System.out.printf("三角形面积 : %f\n", one.triager_sin());
	}
}
