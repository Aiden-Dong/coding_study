/*
* 	不同包的继承问题
*			-> 首先继承的类必须是 public 属性的
*/
package Package.main;
import Package.base.BaseClass;

// 继承类
class ChildClass extends BaseClass
{
	private int j ;
	
	public ChildClass()
	{
		super();
		j = 0;
	}		
	public ChildClass(int a, int b, int j)
	{	
		super(a, b);
		this.j = j;
	}

	// 在不同的包中， 继承问题 ： 
	//				子类可以访问父类的公有成员跟保护成员（public -- protected）
	public void show()
	{
		super.show_p();
		System.out.printf("j = %d\n", j);
	}
}

class MainClass
{
	public static void main(String args[])
	{
		ChildClass one = new ChildClass(3, 18, 19);
		//one.show_p();			// 不可以访问 protected 成员
		one.show();
		/*				
			BaseClass two = new BaseClass();
			two.show_p();		// 也不可以直接访问 
		*/
	}
}
