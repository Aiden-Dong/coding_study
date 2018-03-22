import java.util.*;

public class MainClass
{
  public static void main(String[] args)
  {
    // 参数化类型与原始类型的继承关系
    Collection<String> c = new ArrayList(); // OK
    Collection d = new ArrayList<String>(); // OK

    // 参数化类型不考虑类型的继承关系
    //List<String> slist = new ArrayList<Object>(); // error
    //List<Object> olist = new ArrayList<String>(); // error

    // 在创建数组时， 数组的元素不能使用参数化的类型
    //List<String> listarray[] = new ListArray<String>(); // error

  }
}
