import java.lang.*;
import java.lang.reflect.Constructor;
/*
****************************************************************************
* Constructor 方法：
*            =》 获取 Constructor 方法：
*                Class.getConstructor(Class... args);     // 获取由变量类型（由 Class 类型确认）指定的构造器
*                Class.getConstructors();                 // 获取此类的所有构造器
*             =》 Constructor 的常用方法：
*                Constructor.getName();                   // 获取此构造器的方法名
*                Constructor.newInstance(Object... args); // 利用此构造方法构造一个实体
****************************************************************************
*/
public class MainClass
{
  public static void main(String[] args)throws Exception
  {
    String str = "abc";
    Class one = str.getClass();                           // 获取这个 String 的 Class 对象
    System.out.println("one = " + one.getName());

/*
*       获取类的构造器
*/
    Constructor ctl = one.getConstructor(char[].class);   // 获取String 对象的一个构造器
    System.out.println(ctl.getName());
    System.out.println(ctl);                              // 返回构造器描述
    String str2 = (String)ctl.newInstance(new String("Hello world").toCharArray());  // 需要传递同样类型的对象
    //  使用此 Constructor 对象表示的构造方法来创建该构造方法的声明类的新实例，并用指定的初始化参数初始化该实例。
    //  此处相当于调用 String str2 = new String(new String());
    // 没有绑定对象， 因为 构造器为 static 类型  
    System.out.println(str2);

  }
}
