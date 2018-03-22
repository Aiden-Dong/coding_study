// 线程初步  Thread
/*
*     -> 优先使用 Runnable
*     java 中的线程是通过 Thread 类来实现的
*     -> 可以通过 Thread 的实例来创建新的进程
*     -> 每个线程都是通过某个特定的 Thread 对象所对应的 run() 方法来实现的 ， 方法 run() 成为线程体
*     -> 通过 Thread 类的start() 方法来启动一个线程
*/

// 使用 Thread 来实现线程
class MyThreadThr extends Thread
{
  public MyThreadThr(String str)
  {
    super(str);
  }
    // 线程体
    public void run()
    {
        while(true)
        {
            System.out.println(this);
        }
    }
}

// 使用 Runnable 来实现线程
class MyThreadRun implements Runnable     // 可以启动多个实例
{
  public void run()
  {
    while(true)
    {
      System.out.println("Hello world");

    }
  }
}
public class MainClass
{
    public static void main(String[] args)
    {
      /*
      MyThreadThr aa1 = new MyThreadThr("one");
      aa1.start();

      MyThreadThr aa = new MyThreadThr("two");
      aa.start();
*/
        MyThreadRun bb = new MyThreadRun();
        Thread one = new Thread(bb);
        one.start();
        while(true)
        {
            System.out.println("MainClass");
        }
        */
    }
}
