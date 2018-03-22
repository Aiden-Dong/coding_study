/*
*  List<> 容器收藏的是 Object 对象
*/

import java.util.*;

class StructClass
{
    private int[] list = new int [10];       // 声明一个容量为 10 的数组
    
    public StructClass()
    {
        Random ranit = new Random(System.nanoTime());
        for(int i = 0; i < list.length; i++)
            list[i] = ranit.nextInt(100);
    }
    public void show()
    {
        for(int i = 0; i < list.length; i++)
            System.out.print(list[i] + " ");
        System.out.println();
    }
    public String toString()
    {
        return "StructClass";
    }
}
class StackQueue
{
    private LinkedList<String> link = new LinkedList<String>();
    private final int mark;
    public StackQueue(int i)
    {
        if(i == 1)
        {
            mark = 1;
            System.out.println("这是一个栈实现");
        }
        else
        {
            mark = 2;
            System.out.println("这是一个队列实现");
        }
    }
    public void put(String str)
    {
        if(mark == 1)
            link.addFirst(str);
        else
            link.addLast(str);
    }
    public String get()
    {
        if(link.size() > 0)
            return link.pollFirst();
        else
            return null;
    }
    public void show()
    {
        for(int i = 0; i < link.size(); i++)
            System.out.print(link.get(i) + " ");
        System.out.println();
    }
}
public class MainClass
{
    public static void main(String[] args)
    {
        List<Object> one = new ArrayList<Object>();

        
        for(int i = 0; i < 10; i++)
        {
            if(i%2 == 0)
                one.add(new StructClass());
            else
                one.add("Hello world");
        }
        System.out.printf("length : %d\n", one.size());
        
        for(int i = 0; i < one.size(); i++)
        {
            //if(one.get(i).toString().equals("StructClass"))
            if(one.get(i).toString() == "StructClass")  
            {
                StructClass the = (StructClass)one.get(i);
                the.show();
            }
            else
                System.out.printf("%s\n", one.get(i).toString());
        }
        System.out.println();
        StackQueue stack = new StackQueue(1);
        
//        System.out.println(one.toArray());
        
    }
}