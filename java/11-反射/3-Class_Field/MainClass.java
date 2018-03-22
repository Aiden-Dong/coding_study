import java.lang.reflect.Field;
/*
*************************************************************************
* Field 方法:
*         ->  Class.getField(String... args);    // 通过变量名获取一个类的变量子段
*                 => Class.getDeclaredField(String... args);
*         ->  Class.getFields();                 // 获取这个类的所有的变量子段
*                 => Class.getDeclaredFields();
*         -> Field.get(Object);                  // 获取此指定对象的此变量的值     // static 可以使用 null
*         -> Field.getName();                    // 获取此变量的名
*         -> Field.setAccessible(boolean);       // 设置private 变量的访问权限
*         -> Field.set(Object, Object);          // 设置指定对象的此变量的值
*************************************************************************
*/
public class MainClass
{
  private static void changeStringValue(Object obj) throws Exception
  {
    Field[] it = obj.getClass().getFields();    // 这个类的所有字段  ---- 可允许访问部分

    for(Field one : it)
    {
      System.out.println(one.getName() + " : " + one.get(obj));
      if(one.getType() == String.class)   // == 与 equals（） 方法的比较
      {
        String str = ((String)one.get(obj)).replaceAll("l", "i");
        one.set(obj, str);      // 将此子段赋予新的值
      }
    }
    System.out.println();
  }

  public static void main(String[] args) throws Exception
  {
    RefiectPoint one = new RefiectPoint(3, 5);  // 创建一个类实体
    Field field1 = one.getClass().getField("y");        // getField() 只能获取类允许外部访问的字段
    Field field2 = one.getClass().getDeclaredField("x");  // 可以获取其私有字段
    // 通过变量名来获取制定类的制定字段
    // Field 只与类相关， 而不是与对象相关， 所以需要使用 get 指定确定的对象
    System.out.println(field1.get(one));

    // 暴力反射
    field2.setAccessible(true);                       // 获取其私有成员的访问权
    System.out.println(field2.get(one));
    changeStringValue(one);
    System.out.println("=====================================");
    System.out.println("one.str1 : " + one.str1);
    System.out.println("one.str2 : " + one.str2);
  }
}
