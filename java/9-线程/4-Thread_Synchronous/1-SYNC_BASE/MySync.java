public class MySync implements Runnable
{
  Timer timer = new Timer();      // 每一个  MySync 都有一个单独的 Timer 对象

  public void run()
  {
    timer.add(Thread.currentThread().getName());
  }

  public static void main(String[] args)
  {
      // 共享这个数据
      MySync one = new MySync();
      Thread thread1 = new Thread(one);
      Thread thread2 = new Thread(one);

      thread1.setName("thread1");
      thread2.setName("thread2");

      thread1.start();
      thread2.start();
  }
}
class Timer{

  private  int num = 0;

  public Timer()
  {
    //num++;
  }
  
  // syncchronized 锁机制
  public synchronized void add(String name)
  {
    num ++;
    try{
      Thread.sleep(1);
    }catch(InterruptedException e){}
    System.out.println(name + " : " + num);
  }
}
