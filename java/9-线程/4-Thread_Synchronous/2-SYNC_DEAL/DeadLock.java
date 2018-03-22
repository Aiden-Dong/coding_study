public class DeadLock implements Runnable
{
  public int flag = 1;
  static Object obj1 = new Object();
  static Object obj2 = new Object();

  public DeadLock(int flag)
  {
    this.flag = flag;
  }

  public void run(){

    System.out.println("flag :" + flag);

    if(flag == 1){
      synchronized(obj1){   // 对 obj1 元素进行加锁
        try{
          Thread.sleep(500);
        }catch(Exception e){
          e.printStackTrace();
        }
        synchronized(obj2){ // 对 obj2 元素进行加锁
          System.out.println("已经获取元素");
        }
      }
    }
    if(flag == 0){
      synchronized(obj2){
        try{
          Thread.sleep(500);
        }catch(Exception e){
          e.printStackTrace();
        }
        synchronized(obj1){
          System.out.println("已经获取元素");
        }
      }
    }
  }

  public static void main(String[] args)
  {
    DeadLock one = new DeadLock(0);
    DeadLock two = new DeadLock(1);

    Thread th1 = new Thread(one);
    Thread th2 = new Thread(two);

    th1.start();
    th2.start();
  }
}
