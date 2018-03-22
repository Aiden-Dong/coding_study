/*
*   finally 作用
*               -> 无论 try 所指定的程序块是否抛出异常， 也无论catch 语句的异常类型是否与所抛出的异常的类型一致, 
*                  finally 中的代码一定会执行
*                -> finally 语句为异常处理提供了一个统一的出口， 使得在控制流程转到程序的其他部分以前， 能够对程序的状态作统一的管理
*                -> 通常在 finally 语句中可以进行资源的清楚工作， 如关闭打开文件， 删除临时文件等。。
*/

import java.lang.ArithmeticException;

class BaseClass
{
    public int fin(int a, int b)
    {
        int m;
        m = a/b;
        return m;
    }
}

class MainClass
{
    public static void main(String args[])
    {
        BaseClass one = new BaseClass();
        try
        {
            one.fin(20, 1);    
        }
        catch(ArithmeticException errno)
        {
            System.out.printf("计算异常\n");
            errno.printStackTrace();
        }
        finally
        {
            System.out.printf("Hello world\n");
        }
        
    }
}