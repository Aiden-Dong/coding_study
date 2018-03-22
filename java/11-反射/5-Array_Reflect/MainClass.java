/*
*****************************************************
* 具有相同类型的相同维度的数组属于同一个 Class
*****************************************************
*/
import java.util.Arrays;
import java.lang.reflect.Array;

public class MainClass
{
  private static void print(Object obj)
  {
    Class it = obj.getClass();
    if(it.isArray())
    {
      int len = Array.getLength(obj);
      System.out.print("[");
      for(int i = 0; i < len; i++)
        System.out.print(Array.get(obj, i) + " ");
      System.out.print("]");
      System.out.println();
    }
    else
      System.out.println(obj);
  }
-
  public static void main(String[] args)
  {
    int[] a1 = {12, 13, 14, 15};                  // 数组定义形式 -- 1
    int[] a2 = new int[5];                        // 数组定义形式 -- 2
    int[] a3 = new int[]{12, 13, 14, 15, 16};     // 数组定义形式 -- 3
    String[] str1 = new String[]{"one", "two", "three", "fore", "five"};

    System.out.println(a1 == a2);
    System.out.println(a1.getClass() == a2.getClass());
    System.out.println((Class)a1.getClass() == (Class)str1.getClass());

    System.out.println(Arrays.toString(a1));
    System.out.println(Arrays.asList(str1));

    print(a1);
  }
}
