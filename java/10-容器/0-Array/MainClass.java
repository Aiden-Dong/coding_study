import java.lang.reflect.Array;
import java.util.*;

public class MainClass
{
    public static void main(String[] args)
    {
        int[] arrint = new int[]{12, 13, 14, 15};   // 是以数组形式实现， 不允许插入与删除操作

        for(int one : arrint)
            System.out.printf("%d ", one);
        System.out.println();

        System.out.println(double[].class.getName());

        List<Integer> listint = new ArrayList<Integer>();
        listint.add(12);
        listint.add(13);

        Iterator<Integer> it = listint.iterator();
        while(it.hasNext())
            System.out.print(it.next() + " ");
        System.out.println();
    }
}
