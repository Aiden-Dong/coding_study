// 基类
class BaseClass
{
	private String 	name;
	private int 	age;

	// 类的构造函数
	public BaseClass()
	{
		this.name = "Null";
		this.age = 0;
	}
	public BaseClass(String name, int age)
	{
		this.name = name;
		this.age = age;
	}

	// 类的方法
	public void setName(String name)
	{
		this.name = name;
	}
	public void setAge(int age)
	{
		this.age = age;
	}

	public String getInfo()
	{
		return name + " " + age;	
	}


}

class Student extends BaseClass
{
	public String school;

	// 类构造函数
	public Student()
	{
		super();
		school = "NUll";
	}
	public Student(String name, int age, String school)
	{
		super(name, age);
		this.school = school;
	}
	// 类方法
	public void setSchool(String school)
	{
		this.school = school;	
	}

	public String getInfo()		// 重写	
	{
		//String basestr = super.getInfo();

		return super.getInfo() + " " + school;
	}
}

class MainClass
{
	public static void main(String args[])
	{
		Student one = new Student("saligia", 20, "Linux");

		System.out.println(one.getInfo());
	}
}
