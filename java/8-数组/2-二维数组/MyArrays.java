import java.util.Random;
import java.util.Arrays;

public class MyArrays
{
  public static void main(String[] args)
  {
    Random random = new Random(System.currentTimeMillis());
    int[][] one;          // 声明一个二维数组

    // 实现 5*5 的二维数组 （java 的数组允许长度不相等的长度）
    one = new int[5][];                   // 二维数组的长度为 5；
    for(int i = 0; i < one.length-1; i++)   // 为每一个一维的引用创建一个长度为 5的引用
      // one.length => 二维数组的长度
      one[i] = new int[5];

    for(int i = 0; i < one[0].length; i++)
      one[0][i] = random.nextInt(20);
    one[4] = Arrays.copyOf(one[0], one[0].length);    // copyOf 在新的空间中分配一个内存在付给 one[4]
    Arrays.fill(one[1], 5);                           // fill()
    one[2] = Arrays.copyOf(one[0], one[0].length);    // copyOf()
    Arrays.sort(one[2]);                              // sort()
    for(int i = 0; i < one[0].length; i++)
      one[0][i] = i;

    for(int i = 0; i < one.length; i++)
      System.out.println(Arrays.toString(one[i]));

    System.out.println(Arrays.equals(one[0], one[4]));    // false;

  }
}
