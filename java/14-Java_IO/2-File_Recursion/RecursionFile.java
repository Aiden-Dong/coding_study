import java.io.File;
import java.util.Arrays;

public class RecursionFile
{
  public static void showFile(File file, int i)
  {
    if(!file.isDirectory())
      return;
    File cfiles[] = file.listFiles();     // 获取本目录下的目录项列表
    Arrays.sort(cfiles);
    for(File it : cfiles)
    {
      if(it.isFile())
      {
        for(int x = 0; x < i; x++)
          System.out.print("  ");
        System.out.print("--"+ it.getName()+"\n");
      }
      else if(it.getName() == "." || it.getName() == "..")
        continue;
      else
        {
          for(int x = 0; x < i; x++)
            System.out.print("  ");
          System.out.print("--" + it.getName()+"\n");
          showFile(it, i+1);
        }
    }
  }

  public static void main(String[] args)
  {
    File one = new File("/home/saligia/Shell_script");
    showFile(one, 1);
  }
}
