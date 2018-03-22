/*
*       Object:
*               -> 自定义类默认是 Object 类的一个继承
*/

class BaseClass
{
    // 方法的重写
    public String toString()
    {
        System.out.printf("%s\n", super.toString());    // 调用 Object 类的toString（）方法
        return ("Hello World");
    }
    
}

class MainClass
{
    public static void main(String args[])
    {
        BaseClass one = new BaseClass();
        System.out.printf("%s\n", one.toString());
    }
}