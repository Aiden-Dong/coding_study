/*
*	类的继承
*		私有属性跟方法在继承时不能被子类直接访问
*		共有跟保护 属性跟方法在继承时可以被子类直接继承
*		调用父类的构造函数的方法---------- super
*/

// 基类
class Student
{
	private int b = 0;		// 私有属性
	protected int i = 0;		// 保护属性
	public short age   = 0;		// = 0 表示默认属性

	// 构造函数
	public Student()
	{
		b = 10;
		i = 20;
		age = 30;
	}
	public Student(int b, int i, short age)
	{
		this.b = b;
		this.i = i;
		this.age = age;
	}

	// 公共方法
	public void show()
	{
		System.out.printf("b = %d\ni = %d\nage = %d\n", b, i, age);
	}

}

// 派生类
class Graduate extends Student
{
	int one = 0;

	
	public Graduate(int a, int b, short c)
	{
		// 如果不手动设置调用继承的父类的构造函数， 将自动调用父类的无参构造函数
		//Student();		// errno 语法不允许
		super(a, b, c);		// Success
	}

	public void set()
	{
		//b = 20;		// error : b 为私有数据， 对继承类不开放（不能直接调用）
	}
	
	public String tcher = "无";
}

// 
class MainClass
{
	public static void main(String name[])
	{
		Graduate one = new Graduate(4, 5, (short)6);

		one.show();
	}
}
