// 	函数重载:
// 		 参数(个数， 顺序， 数据类型 其中之一)必须不能相同
//		 造成解析失败， 无法一对一
class AddClass{
	static int add(int a, int b)
	{
		return a+b;
	}
	static double add(double a, double b)
	{
		return a+b;
	}
	static int add(int a, int b, int c)
	{
		return a+b+c;
	}
}

class MainClass{
	public static void main(String []args)
	{
		System.out.printf("%d\n"	, AddClass.add(5,6));	
		System.out.printf("%d\n"	, AddClass.add(5,6,7));
		System.out.printf("%.5f\n"	, AddClass.add(5.3, 7.9));
	}
} 
