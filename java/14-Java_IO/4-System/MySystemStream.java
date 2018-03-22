import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.InputStream;
import java.util.Scanner;

public class MySystemStream
{
  public static void main(String[] args) throws IOException
  {
    // 标准输入流的读取
    // 读取字符串
    BufferedReader fin = new BufferedReader(new InputStreamReader(System.in));
    String str = fin.readLine();
    System.out.println(str);

    // 读取其他类型的数据
    //DataInputStream cin = new DataInputStream(new InputStreamReader(System.in));
    Scanner cin = new Scanner(System.in);
    System.out.println("请输入 int 型");
    int a = cin.nextInt();
    System.out.println("请输入 double 型");
    double b = cin.nextDouble();
    System.out.println("请输入 char 型");
    byte c = cin.nextByte();
    System.out.println("输出 : " + a + " " + b + " " + c );

  }
}
