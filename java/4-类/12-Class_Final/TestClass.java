/*
*	final 修饰符
*
*	1> final 修饰一个类
*		-> 表示该类不能被继承， 属于最终的类
*
*	2> final 修饰一个变量-------const
*		-> 成员初始化可以在构造函数中
*		-> 成员初始化可以在定义时指定默认值
*
*	3> final 修饰一个类方法
*		-> 表示改类方法不允许被重写
*/
class BaseClass
{
	final int a ;	// 相当于 const

	public BaseClass()
	{
		// 在构造函数中指定 final 修饰值
		a = 20;	
	}
	final public void show()
	{
		System.out.printf("a = %d\n",a);
	}	
}
// 此类不能被继承
final class ChildClass extends BaseClass
{
	
}

class MainClass
{
	public static void main(String args[])
	{
		BaseClass one = new BaseClass();
		one.show();	
	}
}
