/*
*   String 类:
*               -> public char charAt(int index);
*               -> public int length();
*               -> public int indexOf(String str);                          // 返回字符串中出现 str 的第一个位置
*               -> public int indexOf(String str, int fromindex);           // 从fromIndex 处开始寻找
*               -> public boolean equalsIgnoreCase(String another);         // 互略大小写比较是否想等
*               -> public String substring(int beginindex, int endindex);   // 返回原字符串的一个子字符串
*               -> public String toUpperCase();                             // 返回大写
*               -> public String toLowerCase();                             // 返回全小写
*               -> public String valueOf(*);                                // 将其他类型转换成字符串
*/

import java.lang.RuntimeException;

public class MainClass
{
    public static void main(String []args)
    {
        String str = new String("Hello world");
        String str1 = new String("192.168.124.124");
        int index_begin = 0, index_end = 0;
        
        if(str.isEmpty())  // 返回字符是否为空
        {
            System.out.println("字符为空");
            return ;
        }
            
        System.out.println("字符长度 : " + str.length()); // 返回字符长度
        System.out.println("原始    ： " + str);
        System.out.println("大写    ： " + str.toUpperCase()); // 转换成大写
        System.out.println("小写    ： " + str.toLowerCase()); // 转换成小写
        try
        {
            System.out.println("字符值   : " + str.charAt(str.length()));    
        }
        catch(IndexOutOfBoundsException error)
        {
            System.out.println("字符索引失败， 超出范围");
        }
        System.out.println(String.valueOf(15.3234));
        
        while(index_end != -1)
        {
            index_end = str1.indexOf('.', index_begin);
            
            //System.out.println(index_begin + " " + index_end);
        
            if(index_end == -1)
                System.out.println(str1.substring(index_begin) );
            else
                System.out.printf(str1.substring(index_begin, index_end) + " ");
            
            index_begin = index_end+1;
        
        }
        
    }
}