/*
*       工厂方法模型：
*                   -> 确定方法类型由接口来实现， 简化构造过程
*/

// 用来调用具体的类型
interface Service
{
    void method1();
    void method2();
}
// 用来为类型提供实例
interface ServiceMake
{
    Service getservice();
}
// 创建类 One1 模型
class One1 implements Service
{
    public One1()
    {    
    }
    public void method1()
    {
        System.out.printf("One1 method1\n");
    }
    public void method2()
    {
        System.out.printf("One1 method2\n");
    }
}
class One1Make implements ServiceMake
{
    public Service getservice()
    {
        return new One1();
    }
}

// 创建类 One2 模型
class One2 implements Service
{
    public One2()
    {    
    }
    public void method1()
    {
        System.out.printf("One2 method1\n");
    }
    public void method2()
    {
        System.out.printf("One2 method2\n");
    }
}
class One2Make implements ServiceMake
{
    public Service getservice()
    {
        return new One2();
    }
}

public class MainClass
{
    // 精髓所在------------ 忽略其具体类型， 交给接口实现
    public static void serviceConsumer(ServiceMake fact)
    {
        Service one = fact.getservice();
        one.method1();
        one.method2();
    }
    
    public static void main(String[] args)
    {
        serviceConsumer(new One1Make());
        serviceConsumer(new One2Make());
    }
}
/*
// -------- Output-----------------
One1 method1
One1 method2
One2 method1
One2 method2
-----------------------------------
*/