/*
*   继承的异常抛出范围问题 ---- 多态
*       -> 子类抛出的异常不能大于其父类
*       -> 先 catch 子类异常 在 catch 父类异常， 则报错
*   -> try--catch 是一个整体
*/

import java.lang.Exception;

class A extends Exception
{
    public A(String strname)
    {
        super(strname);
    }
}
class B extends Exception
{
    public B(String strname)
    {
        super(strname);
    }
}
class BaseClass
{
    public void except() throws A , B
    {
        //throw new A("A Exception");
        throw new B("B Exception");
        // 抛出该异常后， 该方法即终止
    }
}
class ChildClass extends BaseClass
{
    // 重写函数中， 方法抛出的异常不能大于其父类
    public void except() throws A
    {
        throw new A("A Exception");
    }
}

class MainClass
{
    private static void show_except(BaseClass one)
    {
        try
        {
            one.except();
        }
        catch(A errno)
        {
            errno.printStackTrace();
        }
        catch(B errno)
        {
            errno.printStackTrace();
        }
    }
    public static void main(String args[])
    {
        ChildClass child = new ChildClass();
        BaseClass base = new BaseClass();
        
        System.out.printf("调用子类方法 \n");
        show_except(child);
        System.out.printf("调用父类方法 \n");
        show_except(base);
    }
}