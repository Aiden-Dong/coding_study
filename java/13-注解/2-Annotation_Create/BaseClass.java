import java.util.Arrays;

// 自定义注解的使用
@ItCastAnnotation()  // 注解的赋值
public class BaseClass
{
  @MyAnnotation("saligia")
  public static void show()throws Exception
  {
    System.out.println("Hello world");
    MyAnnotation ma = (MyAnnotation)BaseClass.class.getMethod("show").getAnnotation(MyAnnotation.class);  // 获取接口
    System.out.println(ma);
    System.out.println(ma.value() + " : " + ma.it());
    System.out.println(Arrays.toString(ma.one()));

  }
  public static void main(String[] args)throws Exception
  {
    if(BaseClass.class.isAnnotationPresent(ItCastAnnotation.class))
    {
      ItCastAnnotation it = (ItCastAnnotation)BaseClass.class.getAnnotation(ItCastAnnotation.class);
      System.out.println(it);
      System.out.println(it.color());
      show();
    }
    else
      System.out.println("out");
  }
}
/*
***************************************************************************************************
  black
  Hello world
  @MyAnnotation(value=saligia)
  saligia
***************************************************************************************************
*/
