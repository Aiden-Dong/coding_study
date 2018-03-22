class TestClass
{
    public static int a = get();
    
    public static class One
    {
       void set()
       {
           System.out.printf("set runing ..\n");
           a = 10;
           System.out.printf("set down\n");
       }
    }
    
    public static int get()
    {
        System.out.printf("Static on...\n");
        return 4;
        //System.out.printf("Static down...\n");
    }
}
public class MainClass
{
    public static void main(String[] args)
    {
        
        TestClass.One one= new TestClass.One();
        one.set();
        TestClass the = new TestClass();
        System.out.printf("a = %d\n", the.a);   
    }
}

/*
============================================
set runing ..
Static on...
set down
a = 10
============================================
*/