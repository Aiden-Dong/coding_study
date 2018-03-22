import java.io.BufferedReader;
import java.io.FileReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.FileOutputStream;
import java.io.BufferedOutputStream;

public class MyFileOut
{
  // 文件读取
  public static void main(String[] args) throws Exception
  {
    try{
      BufferedReader fin = new BufferedReader(new FileReader("./one.txt"));

      while(fin.ready())
      {
        String str = fin.readLine();
        System.out.println(str);
      }
      fin.close();
    }catch(Exception e)
    {
      e.printStackTrace();
    }

    // 文件写入
    File fname = new File("./file.txt");
    if(fname.exists())                                       // 检测文件是否存在
      fname.delete();
    fname.createNewFile();                                   // 创建文件
    char[] buffer =  new char[]{'A', 'B', 'C', 'D', '我'};
    String strbuf = new String(buffer);
    System.out.println(strbuf);
    byte[] blist = strbuf.getBytes();
    System.out.println(blist.length);

    BufferedOutputStream fout = new BufferedOutputStream(new FileOutputStream(fname));
    fout.write(blist, 0, blist.length);
    fout.close();
  }
}
