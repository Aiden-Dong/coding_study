package Package.base;

public class BaseClass
{
	private int a;
	private int b;

	// 构造函数
	public BaseClass()
	{
		a = 0;
		b = 0;	
	}
	public BaseClass(int a, int b)
	{
		this.a = a;
		this.b = b;
	}

	public void show()
	{
		System.out.printf("a = %d\n", a);
		System.out.printf("b = %d\n", b);
	}
	protected void show_p()
	{
		System.out.printf("a = %d\n", a);
                System.out.printf("b = %d\n", b);
	}
}
