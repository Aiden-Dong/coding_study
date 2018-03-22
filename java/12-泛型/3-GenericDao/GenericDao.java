import java.util.ArrayList;
import java.util.Arrays;
/*
***********************************************
* 泛型类型：
*
***********************************************
*/
class GenericDao<T>
{
  ArrayList<T> obj = new ArrayList<T>();

  public void add(T x)      // 增加一个对象
  {
    obj.add(x);
  }
  public T findById(int id) // 查找一个对象
  {
    if(id >= obj.size())
      return null;
    return obj.get(id);
  }
  public boolean delete(T x) // 删除对象
  {
    return obj.remove(x);
  }
  public boolean delete(int id)
  {
    if(id >= obj.size())
      return false;
    obj.remove(id);
    return true;
  }
  public boolean update(int id, T x) // 修改数据
  {
    if(id >= obj.size())
      return false;
    else
      obj.set(id, x);
    return true;
  }
  public void show()
  {

    System.out.println(Arrays.toString(obj.toArray()));
  }
}
