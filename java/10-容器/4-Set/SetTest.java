/*
*   1> 存入 Set 中的每一个元素必须是唯一的， Set 不保存重复元素  		→ 使用 equals() 方法来确定唯一性
* 	2> HashSet 实现了快速查找								→ 容器中的元素必须定义有 hashCode();
* 	3> LinkedHashSet 使用链表维护其次序
* 	4> TreeSet, 底层为树结构， 可以提取为 有序队列				→ 容器中的元素必须实现 Comparable 接口
*/
import java.util.TreeSet;
import java.util.Set;
import java.util.HashSet;
import java.util.Arrays;
import java.util.Iterator;

class HashBase
{
  public int num = 0;
  private String name = "saligia";

  public HashBase(int num, String name)
  {
    this.num = num;
    this.name = name;
  }
  public HashBase()
  {}

  public boolean equals(Object obj)       // 重定义 equals 方法
  {
    if(obj.getClass() == HashBase.class)
    {
      HashBase it = (HashBase) obj;
      if(it.num == this.num && it.name == this.name)
        return true;
    }

    return false;
  }
  public int hashCode()               // 重定义 hashCode() 方法
  {
      int value = 17;
      value += 37 * num;
      value += 37 * name.hashCode();

      return value;
  }
  public String toString()
  {
    return name + " : " + num;
  }
}
class TreeBase implements Comparable<TreeBase>
{
  private int major = 0;
  private int manor = 0;

  public TreeBase(int major, int manor)
  {
    this.major = major;
    this.manor = manor;
  }

  // this > tb 就正序排列
  public int compareTo(TreeBase tb)   // TreeSet 使用此来代替 equals() 方法
  {
    if(this.major > tb.major)
        return -1;
    else if(this.major == tb.major)
    {
      if(this.manor > tb.manor)
        return -1;
      else if(this.manor == tb.manor)
        return 0;
    }
    return 1;
  }
  public String toString()
  {
    return "major : " + major + '\n' + "manor : " + manor + '\n';
  }
}

public class SetTest
{
  public static void main(String[] args)
  {
    /*
    *     HashSet 方法调用
    *     容器根据 hashCode() 跟 equals() 方法来实现其值
    */
    Set<HashBase> one = new HashSet<HashBase>();
    HashBase it1 = new HashBase(12, "it1");
    one.add(it1);
    System.out.println(it1.hashCode());
    System.out.println(one.contains(it1));
    it1.num = 0;            // 重新设置用于 equals 跟 散列元素
    System.out.println(one.contains(it1));
    System.out.println(one.remove(it1));      // 此元素已经无法指定删除
    System.out.println(Arrays.toString(one.toArray()));
    Iterator<HashBase> iter = one.iterator();
    if(iter.hasNext())
    {
      System.out.println(iter.next());
      iter.remove();                        // remove 也已经无法删除
    }
    System.out.println(one.size());

    /*
    * TreeSet 的方法调用， 容器元素必须实现有 Comparable 接口（排序规则）
    */

    TreeSet<String> it2 = new TreeSet<String>();
    it2.add(new String("one"));
    it2.add(new String("awo"));
    it2.add(new String("three"));

    Iterator<String> iter2 = it2.iterator();
    while(iter2.hasNext())
      System.out.println(iter2.next());

    TreeSet<TreeBase> it3 = new TreeSet<TreeBase>();
    it3.add(new TreeBase(4, 6));
    it3.add(new TreeBase(1, 3));
    it3.add(new TreeBase(4, 7));
    it3.add(new TreeBase(2, 1));
    it3.add(new TreeBase(4, 6));

    Iterator<TreeBase> iter3 = it3.iterator();
    while(iter3.hasNext())
      System.out.println(iter3.next());
  }

}
