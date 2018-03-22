class A{
	private int	i;
	private int 	j;

	// 构造函数
	public A(int a, int b)
	{
		i = a;
		j = b;
		System.out.printf("构造函数被调用\n");
	}
	public void show()
	{
		System.out.printf("i = %d\n", i);
		System.out.printf("j = %d\n", j);
	}
	public void set_i(int a)
	{
		i = a;		
	}
	public void set_j(int b)
	{
		j = b;
	}
	public void set(int a, int b)
	{
		i = a;
		j = b;
	}
	
}

class MainClass{
	public static void main(String arg[])
	{
		A aa = new A(100, 200);		// 此处应该与 类的构造函数相对应

		aa.show();
	}
}
