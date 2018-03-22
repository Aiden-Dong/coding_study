/*
*	抽象类	
*
*	抽象方法 ： 没有方法体的方法叫抽象方法
*	抽象类不一定有抽象方法
*	有抽象方法的一定是抽象类
===========================================================
*
*	多态与抽象
*/

// 抽象基类
abstract class ABaseClass
{
	// 定义属性
	int	a;
	int 	b;

	// 抽象类的构造函数
	public ABaseClass()
	{
		a = 10;	
		b = 20;
	}

	// 抽象方法
	abstract public void abs_base();	// 抽象方法不能有实体
	// 非抽象方法
	public void show()
	{
		System.out.printf("a = %d\n", a);
		System.out.printf("b = %d\n", b);	
	}
}

class ChildClass extends ABaseClass		// 抽象类的继承问题
{
	// 继承抽象类必须将他的抽象方法实现 ---------------- 重写父类的抽象方法
	public void abs_base()			
	{
		System.out.printf("Hello Java\n");
	}
}

class MainClass
{
	public static void main(String arg[])
	{
		//ChildClass one;			// OK允许这种写法
		ABaseClass	base;			// 定义一个基类（抽象类）的为实现的变量(指针)
		ChildClass	one = new ChildClass(); // 定义一个真正的实现的子类对象
		one.abs_base();
		one.show(); 
	}
}
