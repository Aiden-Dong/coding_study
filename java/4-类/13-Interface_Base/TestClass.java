/*
*	接口
*		---- 抽象方法和常量值的集合， 从本质上讲， 接口是一种特殊的抽象类
*	格式：
*		[public] interface InterName [extends SuperInterList]
*		{
*			// 常量定义和方法列表
*		}
*	规格:
*		-> 接口中定义的属性必须是 public static final 的
*		   接口中定义的方法则必须是 public abstract 的
*		   这些修饰符可以省略
*
*		-> 接口中定义的属性的值在实现类中不能被更改
*
*		-> 一个类只能实现某个接口， 不能继承某个接口, 实现一个接口必须实现他的方法
*
*		-> 接口可以继承接口， 而且允许多继承
*
*		-> 如果一个类只实现了一个接口的部分方法， 则该类必须声明为抽象类
*
*		-> 一个类可以在继承一个父类的同时实现一个或多个接口， 但 extends 关键字必须在 implements 之前
*	
*		-> 不可以 new 接口对象， 但可以定义一个引用接口类型的变量并将其指向实现接口的对象， 达到多态的目的
*/

// 接口
interface It
{
	int a = 10; 	// <==> public static final int a = 10;
	void f();	// <==> public abstract void f();
	
}

// 实现一个接口
class OneClass implements It
{
	public void f()	// 实现接口的方法
	{
		System.out.printf("a = %d\n", a);
	}	
}

class MainClass
{
	public static void main(String []args)
	{
		It ptr;
		OneClass one = new OneClass();

		one.f();
		ptr = one;
		ptr.f();
		
	}
}
