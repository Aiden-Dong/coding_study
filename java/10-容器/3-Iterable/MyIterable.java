/*
*     迭代器的构造与声明方式
*     迭代器与 Foreach
*/
import java.util.Random;
import java.util.ArrayList;
import java.util.List;
import java.util.Iterator;

public class MyIterable implements Iterable<Integer>
{
  Random random = new Random(System.currentTimeMillis());
  List<Integer> container = new ArrayList<Integer>();

  public MyIterable()
  {
    for(int i = 0; i < 10; i++)
      container.add(random.nextInt(100));
  }
  public MyIterable(int size)
  {
    for(int i = 0; i < size; i++)
      container.add(random.nextInt(100));
  }

  public Iterator<Integer> iterator()
  {
    return new Iterator<Integer>()
    {
      int index = 0;
      public boolean hasNext()
      {
        return index < MyIterable.this.container.size();
      }
      public Integer next()
      {
        return MyIterable.this.container.get(index++);
      }
      public void remove()
      {
        throw new UnsupportedOperationException();
      }
    };
  }

  public static void main(String[] args)
  {
    for(int one : new MyIterable())
      System.out.print(one + " ");
    System.out.println("");

    Iterator<Integer> it= new MyIterable(5).iterator();

    while(it.hasNext())
      System.out.print(it.next() + " ");
    System.out.println();
  }
}
