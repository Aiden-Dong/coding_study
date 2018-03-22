import java.util.ArrayList;
import java.util.List;
import java.lang.reflect.*;

class ReflectClass
{
  public static void main(String[] args) throws Exception
  {
    List<Integer> one = new ArrayList<Integer>();
    List<String> two = new ArrayList<String>();

    // 只能通过反射方法来获取 泛型的实际对象
    Method func = ReflectClass.class.getMethod("applyList", List.class);
    Type[] types = func.getGenericParameterTypes();
    ParameterizedType pType = (ParameterizedType) types[0];
    System.out.println(pType.getRawType());
    System.out.println(pType.getActualTypeArguments()[0]);      // 获取实例对象

    System.out.println(one.getClass() == two.getClass());     // List<Integer> == List<String>
  }
  public static void applyList(List<String> v1)
  {

  }
}
