// 访问控制符
class Triangle{
	private int a, b, c;
	// private 将数据变为私有的数据， 外部不能直接访问
	// public 可以通过 外部访问方式访问内部的成员
	public void tri_set(int t1, int t2, int t3)
	{
		a = t1;
		b = t2;
		c = t3;
	}
	
	public int tri_len()
	{
		return (a+b+c);
	}
	public double tri_sun()
	{
		return (a+b+c)/2.0;
	}
}

class TriangleMain{
	public static void main(String args[])
	{

		Triangle one = new Triangle();

		one.tri_set(3,4,5);
	
		System.out.printf("面积 : %f\n", one.tri_sun());
		System.out.printf("长度 : %d\n", one.tri_len());

	}
}
