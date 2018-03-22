import java.util.Random;
import java.lang.System;

public class MainClass
{
  public static void main(String[] args)
  {
    Random it = new Random(System.nanoTime());
    GenericDao<Integer> one = new GenericDao<Integer>();

    for(int i = 0; i < 10; i++)
      one.add(it.nextInt(30));

    one.show();
    one.delete((int)1);
    one.show();
  }
}
