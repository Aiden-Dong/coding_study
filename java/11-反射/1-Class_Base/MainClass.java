import java.lang.Class;
import java.lang.Exception;
public class MainClass
{

  public static void main(String[] args) throws Exception
  {
    String str = "abc";
    Class cls1 = Class.forName("java.lang.String");
    Class cls2 = str.getClass();
    Class cls3 = String.class;

    System.out.println("cls1 Name : " + cls1.getName());
    System.out.println("cls1 Name : " + cls1.getCanonicalName());
    System.out.println("cls1 Name : " + cls1.getSimpleName());
    System.out.println("cls1 Name : " + cls1.getSuperclass().getName());
    System.out.println("cls1 = cls2                 : " + (cls1 == cls2));
    System.out.println("cls1 = cls3                 : " + (cls1 == cls3));
    System.out.println("cls1                        : " + cls1.isPrimitive());   // 判断是否是原始类型
    System.out.println("int.class                   : " + int.class.isPrimitive());
    System.out.println("int[].class                 : " + int[].class.isPrimitive()); // 数组不是基本类型
    System.out.println("int[].class                 : " + int[].class.isArray());      // 判断是否是一个数组
    System.out.println("int.class == Integer.class  : " + (int.class == Integer.class));
  }
}
