/*
 ******************************************************************************************************
 * 异常处理的两种情况:
 *                  -> 类内部自己处理
 *                  -> 让调用者去处理异常 (throws)
 *  throw:
 *                  -> 要抛出的 --对象-- 必须是 Throwable 的子类
 *  throws A        -> 不表示一定要抛出该异常， 即允许不抛出此类异常
 *                  -> 在相应的 try 语句主体中不能抛出异常
 *
 *  总结：
 *                  -> 对 throws 出的所有异常进行处理，
 *                  -> 如果一个方法内部已经对 A 异常进行了处理， 则就不要在 throws A
 *****************************************************************************************************
*/

import java.io.IOException;
import java.lang.Exception;

// 自定义异常
class OwnException extends Exception
{
    public OwnException(String name)
    {
        super(name);
    }
}
class BaseClass
{
    public void f() throws IOException          // throws 表示不处理本方法， 让调用者进行处理
    {
        // 可以不抛出这个异常
        throw new IOException();                // 抛出 IOException 异常
    }
        
    public void g()
    {
        throw new ArithmeticException();
                                                // 该异常可处理可不处理
    }
    public void usrchose() throws OwnException  // 抛出自定义处理的异常
    {
        throw new OwnException("自定义异常");
    }
    
    public int divide(int a, int b)
    {
        int m = 0;
        try
        {
            if(b == 0)
                throw new ArithmeticException();
       }
        catch(ArithmeticException errno)
        {
            errno.printStackTrace();
            return 0;
        }
        
        System.out.printf("未出现异常\n");
        m = a/b;
       
        return m;
        
    }
}

class MainClass
{

    public static void main(String args[]) 
    {
        BaseClass one = new BaseClass();
        // 调用者处理异常的处理方式
        try
        {
            one.f();    
        }
        catch(IOException errno)
        {
            errno.printStackTrace();
        }
        
        // 获取自定义异常
        try
        {
            one.usrchose();
        }
        catch(OwnException errno)
        {
            errno.printStackTrace();
        }
        /*
         *   OwnException: 自定义异常
	     *   at BaseClass.usrchose(TestClass.java:33)
	     *   at MainClass.main(TestClass.java:56)
        */
        System.out.printf("val : %d\n", one.divide(5, 1));
    }
}