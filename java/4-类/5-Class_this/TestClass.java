// 类对象拥有自己数据空间， 但是共享一个方法空间

class ThisClass{
	public int i;
	
	public ThisClass(int i)
	{
		this.i = i;	// this.i 的指示作用
	}
	public ThisClass()
	{
		i = 10;
	}

	public void show()
	{
		System.out.printf("i = %d\n", i);	// i 可以替换为 this.i
	}
}

class MainClass{
	public static void main(String args[])
	{
		ThisClass one = new ThisClass();
		ThisClass two = new ThisClass(20);

		one.show();
		two.show();
	}
}
