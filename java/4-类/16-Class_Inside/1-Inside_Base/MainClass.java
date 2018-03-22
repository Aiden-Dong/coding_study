/*
*       内部类：
*               内部类可以访问外部的成员变量 : 外部类方法也可直接访问内部类的所有 
*                                       -> 一个内部类必须与外部类所关联
*                                       -> 内部类成员方法必须非 static 
*/
class TestClass
{
    private int i = 10;
    public TestClass()
    {
        System.out.println("Hello world");
    }
    
    public class One
    {
        private int a;
        //public static int b;  // error
        private One()
        {
            a = 20;
            System.out.printf("One class is Create ： %d\n", a);
        }
        public void show()
        {
            System.out.printf("Outside variable : %d\n", TestClass.this.i); // 访问外部类的 private 成员
            System.out.printf("Inside variable : %d\n", a);
        }
 
        public TestClass getclass()
        {
            return TestClass.this;              // 获取本外部类
        }
    }

    public void show()
    {
        TestClass.One one = new TestClass.One();
        one.show();
        System.out.printf("Visit One.i in Outside of class : %d\n", one.a);
    }
}
public class MainClass
{
    public static void main(String[] args)
    {
        TestClass one = new TestClass();
        one.show();
    }
}

/*
// Result of Runing:
-----------------------------------------------------
Hello world
One class is Create ： 20
Outside variable : 10
Inside variable : 20
Visit One.i in Outside of class : 20
----------------------------------------------------
*/