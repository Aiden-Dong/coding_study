/*
*	函数重载问题
*/
class BaseClass{							// 基类

	private String	name;
	private short 	age;

	// 类的构造方法
	public BaseClass()
	{
		name 	= "Null";
		age	= 0;
	}
	public BaseClass(String p_name, short p_age)
	{
		name 	= p_name;
		age 	= p_age;
	}

	// 类方法
	public void show()
	{
		System.out.printf("name         = %s\n", name);
		System.out.printf("age          = %d\n", age);
	}
}

// BaseClass 的派生类
class StudentClass extends BaseClass{

	private	String	idcard;
	private short 	grade;

	public StudentClass()
	{
		super();		// 此处如果不调用， 将自动调用
					// 必须在第一句首先调用---------- 首先构造父类属性
		idcard = "00000000";
		grade = 0;	
	}

	public StudentClass(String p_name, short p_age)
	{
		super(p_name, p_age);
	}
	public StudentClass(String p_name, short p_age, String p_idcard, short p_grade)
	{
		super(p_name, p_age);
		idcard	= p_idcard;
		grade	= p_grade;
	}
	// 函数重写
	public void show()
	{
		super.show();		// 调用父类的方法
		System.out.printf("id           = %s\n", idcard);
		System.out.printf("grade        = %d\n\n", grade);
	}
}

// Main函数调用类
class MainClass{
	public static void main(String arg[])
	{
		StudentClass one 	= new StudentClass();
		StudentClass two 	= new StudentClass("one", (short)20);
		StudentClass three 	= new StudentClass("saligia", (short)20, "2013201890", (short)23);
		one.show();
		two.show();
		three.show();
	}
}
