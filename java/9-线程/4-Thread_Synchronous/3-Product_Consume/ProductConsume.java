// 生产单位
class WoTou{
  int id;

  public WoTou(int id)
  {
    this.id = id;
  }
  public String toString()
  {
    return "单位 : " + id;
  }
}

class SyncStack
{
  int index = 0;

  WoTou[] array = new WoTou[9];

  // 生产者方法
  public synchronized void push(WoTou wt)
  {
    // 篮子满
    while(index == array.length)          // while 的必要性
    {
      System.out.println("生产者休眠");
      try{
        this.wait();
      }catch(InterruptedException e){
        e.printStackTrace();
      }
      System.out.println("生产者休眠结束");
    }

    if(index == 0)
    {
      System.out.println("激活消费者");
      this.notify();
    }


    array[index] = wt;
    index++;
    System.out.println("放入一个单位 : " + wt);
  }
  // 消费者线程
  public synchronized void pop()
  {
    // 篮子空
    while(index == 0)
    {
      System.out.println("消费者休眠");
      try{
        this.wait();
      }catch(InterruptedException e){
        e.printStackTrace();
      }
      System.out.println("消费者休眠结束");
    }


    if(index == array.length)
    {
      System.out.println("激活生产者");
      this.notify();
    }
    System.out.println("取出一个单位 : " + array[--index]);
  }

}

class Product implements Runnable{

  SyncStack ss = null;
  String name ;

  Product(SyncStack ss, String name)
  {
      this.ss = ss;
      this.name = name;
  }

  public void run()
  {
    for(int i = 0; i < 50; i++)
    {
      try{
          Thread.sleep(200);
      }catch(InterruptedException e){}

      WoTou one = new WoTou(i);
      System.out.println(name + "生产单位");
      ss.push(one);

    }
  }
}
class Consume implements Runnable{

  SyncStack ss = null;
  String name;

  Consume(SyncStack ss, String name)
  {
      this.ss = ss;
      this.name = name;
  }

  public void run()
  {
    for(int i = 0; i < 50; i++)
    {
      System.out.println(name + "消费进程");
      ss.pop();
    }
  }
}
public class ProductConsume
{
    public static void main(String[] args)
    {
      SyncStack one = new SyncStack();
      Product product1 = new Product(one, "生产者 1");
      Product product2 = new Product(one, "生产者 2");
      Consume consume1 = new Consume(one, "消费者 1");
      Consume sonsume2 = new Consume(one, "消费者 2");

      Thread thPro1 = new Thread(product1);
      Thread thPro2 = new Thread(product2);
      Thread thCon1 = new Thread(consume1);
      Thread thCon2 = new Thread(sonsume2);

      thPro1.setPriority(Thread.NORM_PRIORITY);

      thCon1.start();
      thPro1.start();
      thPro2.start();
      thCon2.start();
    }
}
