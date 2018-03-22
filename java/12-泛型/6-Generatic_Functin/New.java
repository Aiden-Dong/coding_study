/*
*   泛型方法的隐式与显式类型推断
*/

import java.util.*;

public class New
{
  public static <K,V> Map<K,V> map()
  {
    return new HashMap<K,V>();
  }
  public static <T> List<T> list()
  {
    return new ArrayList<T>();
  }
  public static <T> Set<T> set()
  {
    return new HashSet<T>();
  }

  private static void f(Set<String> str)
  {
  }
  public static void main(String[] args)
  {
    Map<String, List<String>> sls = New.map();    // 自动推导返回类型
    List<String> ls = New.list();

    f(New.<String>set());                    // 显式的自动类型推断
  }
}
