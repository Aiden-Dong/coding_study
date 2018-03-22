import java.io.File;
import java.util.Date;

public class MyFile
{
  public static void main(String[] args)
  {
    File file = new File("/home/saligia/QT_GUI");
    //File file = new File("MyFile.java");
    System.out.println("file name : " + file.getName());      // 获取简单名字
    System.out.println("parent name : " + file.getParent());
    // 返回此抽象路径名父目录的路径名字符串 ----- 路径中必须指定父目录
    System.out.println("isAbsolute : " + file.isAbsolute());
    System.out.println("path : " + file.getAbsolutePath());
    System.out.println("time : " + new Date(file.lastModified()));  // 获取最后的修改时间
    System.out.println("length : " + file.length());

    System.out.println("=================================");
    for(String it : file.list())                                  // 返回file 下的文件列表
      System.out.println(it);                                     // 如果是普通文件便抛出异常
    System.out.println("==================================");

    System.out.println("===================================");
    for(File itf : file.listFiles())
      System.out.println(itf.getAbsolutePath());
    System.out.println("===================================");
  }
}
