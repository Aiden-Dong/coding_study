// 所有的类对象共享一个 static 属性
// static 属性是属于类本身， 或者如果没有对象也可通过类名访问
// static 的方法不能去使用 非 static 属性
// 非静态方法可以访问 静态方法 静态方法不允许访问 非静态方法
	/*
	* 	因为有非静态方法一定有静态方法， 有静态方法不一定有非静态方法
	*/

class StaticClass{
	int a = 20;

	public static int i = 10;
	private static int num = 0;

	public StaticClass()
	{
		num++;
	}
	public static void show()
	{
		// a = 10;	error 不允许static 的方法调用 非static 变量
		System.out.printf("hello world : %d\n", i);
	}
	public void get()		// 允许内部 public 方法直接调用 static 方法跟属性
	{
		System.out.printf("get : %d\n", a);
		System.out.printf("get : %d\n", i);
		show();
	}
	public static void show_num()
	{
		System.out.printf("当前类的数目 : %d\n", num);
	}
}

class MainClass{

	public static void main(String args[])
	{
		StaticClass one	= new StaticClass();
		StaticClass two = new StaticClass();

		System.out.printf("i = %d\n", one.i);
		one.i	= 20;
		System.out.printf("i = %d\n", two.i);
		System.out.printf("i = %d\n", StaticClass.i);
		StaticClass.show();
		one.get();
		StaticClass.show_num();
	}
}
