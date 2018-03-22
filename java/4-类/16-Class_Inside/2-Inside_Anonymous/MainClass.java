// 匿名内部类， 主要通过 其实现的接口或者基类访问

interface Service
{
    public void make(int i);
    public void show();
}
interface ServiceGet
{
    public Service getService();
}

class TestClass1 implements Service
{
    private int i = 0;
    public void make(int i)
    {
        this.i = i;
    }
    public void show()
    {
        System.out.printf("TestClass1 : %d\n", i);
    }
    public static ServiceGet one = // 声明一个匿名类对象
        new ServiceGet(){           
        public Service getService()
        {
            return new TestClass1();
        }
    };
}

class TestClass2 implements Service
{
    private String name = "Name";
    private int i   = 0;
    
    public void make(int i)
    {
        this.i = i;
    }
    public void show()
    {
        System.out.println("TestClass2 name : " + name);
        System.out.println("TestClass2 i    : " + i);
    }
    public static ServiceGet one =  
        new ServiceGet(){
        public Service getService()
        {
            return new TestClass2();
        }
    };
}

public class MainClass
{
    public static void show(ServiceGet i)
    {
        Service one = i.getService();
        one.make(10);
        one.show();
    }
    public static void main(String[] args)
    {
        show(TestClass1.one);
        show(TestClass2.one);
    }
}
/*
// Result of Runing
===================================
TestClass1 : 10
TestClass2 name : Name
TestClass2 i    : 10
===================================
*/