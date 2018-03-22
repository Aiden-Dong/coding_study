/*
*   ->异常主要应用在 if, else 等控制语句解决不了的问题
*/

import java.util.Scanner;
import java.util.InputMismatchException;

class BaseClass
{
    int divite(int a, int b)
    {
        int m;
        try{
            
            m = a/b;
        }
        catch(Exception e) 
        {
            m = -1;         // 此处另赋值， 防止由于异常导致 try 里的赋值语句未执行   
        }
            return m;
    }
}

class MainClass
{
    public static void main(String args[])
    {
        int i;
        Scanner sc = new Scanner(System.in);
        // System.in 表示键盘
        try // 使用 try 捕获而无法使用 if 等处理机制的异常
        {
            i = sc.nextInt(); 
            // 从键盘中获取一个字符串('\n' 为界)， 并转换成整形
            System.out.printf("i = %d\n", i);
        }
        catch(InputMismatchException one)
        {
            System.out.printf("输入不合法\n");
            one.printStackTrace();
        }
    }
}