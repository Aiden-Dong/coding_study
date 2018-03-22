import java.io.*;
public class CopyFile
{
  public static void main(String[] args)
  {
    long tim = System.currentTimeMillis();
    if(args.length != 2)
    {
      System.out.println("Process <File--Path> <File---name>");
      System.exit(0);
    }
    try{
      File fi = new File(args[0]);
      File fo = new File("./" + args[1]);

      if(!fi.exists() || !fi.isFile())
      {
        System.out.println("File not Found");
        System.exit(0);
      }

      fo.createNewFile();

      System.out.println("文件大小 : " + fi.length());

      DataInputStream fin = new DataInputStream(new FileInputStream(fi));
      DataOutputStream fout = new DataOutputStream(new FileOutputStream(fo));

      byte[] buffer = new byte[1024];
      int len;

      while((len = fin.read(buffer)) != -1)
        fout.write(buffer, 0, len);

      fout.flush();

      System.out.println("消耗时间 ： " + (System.currentTimeMillis() - tim));


      fin.close();
      fout.close();
    }catch(IOException e)
    {
      e.printStackTrace();
    }
  }
}
