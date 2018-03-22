import java.util.concurrent.*;

/*
*     -> newCachedThreadPool      // 可以在运行时随时添加线程的线程池
*     -> newFixedThreadPool       // 只能在同一时刻最大运行固定数量的线程池
*     -> newSingleThreadExecutor  // 单例线程池 -------- 任何时刻只能有一个例子
*/

class JobThread implements Runnable
{
  @Override
  public void run()
  {
    System.out.println("start");

    for(int i = 0; i < 5; i++)
    {
      try{
          Thread.sleep(200);
      }catch(InterruptedException e){}

      System.out.println("hello world");
    }
  }
}
public class MyExecutor
{
  public static void main(String[] args)
  {
    // ------------------ newCachedThreadPool ------------------------------//
    /*
    ExecutorService exec = Executors.newCachedThreadPool();       // 创建一个线程池
    for(int i = 0; i < 5; i++)
      exec.execute(new JobThread());                              // 通过 Executors 来启用线程---------- 将新的任务加入到线程池

    //---------------------- newFixedThreadPool -----------------------------//

    ExecutorService exec = Executors.newFixedThreadPool(5);       // 创建指定大小的线程池
    for(int i = 0; i < 6; i++)
      exec.execute(new JobThread());
    */

    ExecutorService exec = Executors.newSingleThreadExecutor();        // 单例线程
    for(int i = 0; i < 6; i++)
      exec.execute(new JobThread());
  }
}
