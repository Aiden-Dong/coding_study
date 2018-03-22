import java.util.ArrayList;
import java.util.List;

class BaseClass
{
}
class OneClass extends BaseClass
{
}
public class WildCard
{
  public static void main(String[] args)
  {
      List<String> strList    = new ArrayList<String>();
      List<Integer> intList   = new ArrayList<Integer>();
      List<? extends BaseClass> oneList  = new ArrayList<OneClass>();   // 向上转型
      List<? super String> twoList = new ArrayList<Object>();           // 逆转
      List<?> threeList = new ArrayList<String>();                      // 无边界通配符
      // 必须指定一个确切类型， 否认将任何类型都方不进去
      threeList.add("one");
      //threeList.add(12);
      //threeList.add(13L);

      System.out.println(strList.getClass());
      System.out.println(strList.getClass() == intList.getClass());
      System.out.println(oneList.getClass() == intList.getClass());
      System.out.println(twoList.getClass() == oneList.getClass());
  }
}
