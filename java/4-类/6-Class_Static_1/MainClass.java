class Static_1
{
	public Static_1()
	{
			System.out.println("Static_1 OK");
	}
	public Static_1(int i)
	{
				System.out.println("Static_1 : " + i);
	}
}
class Base_1
{
	static Static_1 one = new Static_1();
	static Static_1 two = new Static_1(3);
	
	public static void print_show()
	{
				System.out.printf("Hello world\n");
	}
}
public class MainClass
{
	public static void main(String [] args)
	{
		Base_1.print_show();
		}
}