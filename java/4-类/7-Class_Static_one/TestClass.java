
// 创建只有一个类实例的方法
class Static_One
{
	public int i = 20;
	// 此处必须为 static 是避免递归问题
	// static 使得只有一个实例， 所有的其他调用将共享此方法
	private static  Static_One one = new Static_One();
	
	// 将类的构造函数设为私有是防止外部构造 new 	 
	private Static_One()
	{
	}
	
	public static Static_One getClass_Static()
	{
		return  one;
	}
}

class MainClass
{
	public static void main(String arg[])
	{
		Static_One first = Static_One.getClass_Static();
		Static_One second = Static_One.getClass_Static();
		System.out.printf("i = %d\n", second.i);
		first.i = 40;
		System.out.printf("i = %d\n", second.i);
	}
}
