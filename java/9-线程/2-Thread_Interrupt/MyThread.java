import java.util.*;

public class MyThread
{
  public static void main(String[] args)
  {
    YieldClass thyield = new YieldClass();

    InterClass thread = new InterClass();
    thread.start();
    thyield.start();
    try{
        thread.join();
    }catch(InterruptedException e){}
    for(int i = 0; i < 10; i++){
      System.out.println("hello world");
    }
  }
}

class YieldClass extends Thread{
  public void run(){
    for(int i = 0 ; i < 100; i++)
    {
      if(i % 10 == 0)
        this.yield();
      System.out.println(i);
    }
  }
}
class InterClass extends Thread
{
  public void run()
  {
    for(int i = 0; i < 10; i++)
    {
      System.out.println("============" + new Date() +"===========");
      try{
        sleep(1000);
      }catch(InterruptedException e)
      {
        System.out.println("线程被中断");
        return;
      }
    }
  }
}
