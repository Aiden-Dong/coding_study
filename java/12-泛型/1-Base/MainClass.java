/*
*   java 泛型是提供给 java 编译器(javac)来使用的的， 可以限定集和中的输入类型， 让编译器挡住源程序中的非法输入；
*   编译器编译带类型说明的集合时会去除掉"类型"信息;
*   对于参数化的泛型类型， getClass() 方法的返回值和原始类型完全一样
*/
import java.util.ArrayList;
import java.lang.Class;
import java.lang.Exception;

public class MainClass
{
  public static void main(String[] args) throws Exception
  {
    // 非泛型的操作
    ArrayList list = new ArrayList();
    list.add(1);
    list.add(1L);
    list.add("Hello world");
    int i = (Integer)list.get(0);
    System.out.println("i = " + i);

    // 泛型的引入， 显示的指明容器中要存放的值
    // 这样， 容器中只能存放 String 对象 -------------- 限制了存放的对象的类型
    ArrayList<String> strlist = new ArrayList<String>();
    strlist.add("one");
    strlist.add("two");
    strlist.add("three");
    String one = strlist.get(0);                         // 会确定返回的是 String 所以不需要强制类型转换
    System.out.println(strlist);
    System.out.println(one);

    Class<String> itclass = String.class;
    String one1 = itclass.newInstance();  // 不用使用强制类型转化
    // 泛型的类型消除
    ArrayList<Integer> intList = new ArrayList<Integer>();
    intList.add(1);
    ArrayList<String> strList = new ArrayList<String>();
    System.out.println(intList.getClass() == strList.getClass());

    // 反射的使用
    try{
      intList.getClass().getMethod("add", Object.class).invoke(intList, "abc");
        //  Method getMethod(String name, Class<?>... parameterTypes)
        //  返回一个 Method 对象，它反映此 Class 对象所表示的类或接口的指定公共成员方法。
        //  Object invoke(Object obj, Object... args)
        // 对带有指定参数的指定对象调用由此 Method 对象表示的底层方法。
    }catch(Exception e)
    {
      e.printStackTrace();
    }
    System.out.println(intList.get(1)); // 成功的将 "abc" 插入到 ArrayList<Integer> 的容器中
  }
}
