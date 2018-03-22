// 一维数组
import java.util.Random;
import java.util.Arrays;

public class MainClass
{
    public static void main(String[] args)
    {
        
        Random random = new Random(10);
        
        //方式一 :
        int[] array1 = {14, 12, 13, 20, 22 };
        
        for(int i = 0; i < array1 .length; i++)
            System.out.print(array1[i] + " ");
        System.out.printf("\n");
        
        // 方式二 :
        int[] array2 = new int [7];
        
        for(int i = 0 ; i < array2.length; i++)
            array2[i] = random.nextInt(100);
        
        for(int i = 0 ; i < array2.length; i++)
            System.out.print(array2[i] + " ");
        System.out.printf("\n");
        
        // 方式三
        
        int[] array3 = new int[] {14, 12, 13, 20, 22 };
        for(int i = 0; i < array3 .length; i++)
            System.out.print(array3[i] + " ");
        System.out.printf("\n");
        
        // arraycopy 调用
        
        System.arraycopy(array2, 1, array3, 0, 5); // 数组元素的拷贝
        
        for(int i = 0; i < array3 .length; i++)
            System.out.print(array3[i] + " ");
        System.out.printf("\n");
        
        // 排序
        Arrays.sort(array2);
        for(int i = 0 ; i < array2.length; i++)
            System.out.print(array2[i] + " ");
        System.out.printf("\n");
        
        System.out.printf("查找 13 : %d\n", Arrays.binarySearch(array2, 13));
    }
}