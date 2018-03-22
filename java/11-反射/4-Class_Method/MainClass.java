/*
****************************************************************
* Method 方法：
*       =》 调用方式 ：
*             Class.getMethod(String, Class...);                // 方法名 + 参数类型（Class）
*                 => Class.getDeclaredMethod(String, Class...);
*             Class.getMethods();                               // 获取所有的方法
*                 => Class.getDeclaredMethods();
*      =》 使用方式：
*             Method.invoke(Object, Object...);                 // 调用类方法 （如果是静态方法， 则对象可以为 null）
****************************************************************
*/
import java.lang.reflect.Method;

public class MainClass
{
  private static void show(Object obj)
  {
    Method[] funcs = obj.getClass().getMethods();             // 获取这个类的所有允许访问的成员

    for(Method one : funcs)
    {
        System.out.println(one.toString().replaceAll("(\\w+\\.)+", ""));    // 替换掉描述符
        //System.out.println(one.getName());
    }
  }

  public static void main(String[] args) throws Exception
  {
    FunctionMethod it = new FunctionMethod();
    show(it);

    // 反射形式调用类方法
    Method func = it.getClass().getMethod("show_variable");  // 调用方式： 方法名 + 变量类型(Class 形式)
    func.invoke(it);                                // 调用变量名
    func = it.getClass().getMethod("set", int.class, int.class, String.class);
    func.invoke(it, 23, 45, "Assassin");
    it.show_variable();

    //it.main(new String[]{});
    func = it.getClass().getMethod("main", String[].class);
    //System.out.println(func);
    func.invoke(it, new Object[]{new String[]{"one", "two", "three", "split", "declare"}});   // 调用 main 的 一个方法

  }
}
