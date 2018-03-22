import java.util.*;

class PrioneClass implements Runnable
{
  public void run(){
    for(int i = 0; i < 100; i++){
      System.out.println("T1 : "+ i);
    }
  }
}
class PritwoClass implements Runnable{
  public void run(){
    for(int i = 0 ; i < 100; i++){
      System.out.println("-------T2 : " + i);
    }
  }
}

public class MyThread{
  public static void main(String[] args){
    Thread t1 = new Thread(new PrioneClass());
    Thread t2 = new Thread(new PritwoClass());
    t2.setPriority(Thread.NORM_PRIORITY+1);

    System.out.println(t1.getPriority());
    System.out.println(t2.getPriority());
    t1.start();
    t2.start();
  }
}
