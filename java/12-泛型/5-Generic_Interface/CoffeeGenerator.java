import java.util.Random;
import java.util.Iterator;

// Coffee 的生成器
// Iterable 实现迭代功能 --------- foreach
public class CoffeeGenerator implements Generator<Coffee>, Iterable<Coffee>
{
  private Class[] types = {Latte.class, Mocha.class, Cappuccino.class, Americano.class, Breve.class};
  private static Random rand = new Random(System.nanoTime());

  public CoffeeGenerator()
  {
  }
  private int size = 0;
  public CoffeeGenerator(int size)
  {
    this.size = size;
  }
  public Coffee next()
  {
    try{
        return (Coffee)types[rand.nextInt(types.length)].newInstance();    // 为什么不直接使用对象而使用反射
    }catch(Exception E)
    {
      throw new RuntimeException();
    }

  }

  /*
  * Iterator 接口为实现的方法
  *               next();
  *               hasNext();
  *               remove();
  */
  // 内部类
  class CoffeeIterator implements Iterator<Coffee>
  {
      int count = size;
      public boolean hasNext()
      {
        return count > 0;
      }
      public Coffee next()
      {
        count --;
        System.out.println("================");
        return CoffeeGenerator.this.next() ; // 调用外部对象方法
      }
      public void remove()
      {
        throw new UnsupportedOperationException();    // 抛出为实现的异常
      }
  }
  public Iterator<Coffee> iterator()
  {
    return new CoffeeIterator();
  }

  public static void main(String[] args)
  {
        CoffeeGenerator gen = new CoffeeGenerator();

        for(int i = 0; i < 5; i++)
            System.out.println(gen.next());

        for(Coffee c : new CoffeeGenerator(5))
              System.out.println(c);
  }
}
