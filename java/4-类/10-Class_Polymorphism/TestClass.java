/*
 * 多态 问题
*/

class BaseClass
{
	public void show()
	{
		System.out.printf("hello world\n");
	}
}

class ChildClass extends BaseClass
{
	public void show()
	{
		System.out.printf("Hello Java\n");
		super.show();
	}
	public void func()
	{
		System.out.printf("ower inline");
	}
}

class MainClass
{
	// 多态的使用
	private static void show(BaseClass the)
	{
		the.show();
	}
	public static void main(String arg[])
	{
		BaseClass one = new BaseClass();
		ChildClass two = new ChildClass();		
		show(one);
		show(two);
	
		// 错误的子类指向父类的方法
		/*// error
		two = (ChildClass) one;
		two.func();
		*/

		// 正确的子类指向父类的方法
		one = two;
		two = (ChildClass)one;
		two.show();

	}
}
