import java.nio.*;
import java.io.*;
import java.nio.channels.FileChannel;
/*
*   文件复制方法一：
*             -> FileInputSrem FileOutputStream
*             -> FileChannel
*             -> ByteBuffer
*/
public class CopyFile
{
  public static void main(String[] args)
  {
    long time1 = System.currentTimeMillis();
    if(args.length != 2)
    {
      System.out.println("Process <InputFile---Path> <OutputFile ---Name>");
      System.exit(0);
    }

    File fin = new File(args[0]);              // 要复制的文件
    File fout = new File("./"+ args[1]);       // 要输出的文件

    if(!fin.exists() || !fin.isFile())                     // 检测要输出的文件是否存在
    {
      System.out.println("InputFile is not Found");
      System.exit(0);
    }
    System.out.println("文件大小 : " + fin.length());
    try{
      fout.createNewFile();

      FileChannel filein = new FileInputStream(fin).getChannel();     // 获取与此对象关联的唯一的通道
      FileChannel fileout = new FileOutputStream(fout).getChannel();  // 获取于此对象关联的唯一通道

      ByteBuffer buffer = ByteBuffer.allocate(1024);              // 设置一个缓冲区
      while(filein.read(buffer) != -1)
      {
        buffer.flip();                  // 准备好写入数据
        fileout.write(buffer);
        buffer.clear();                 // 准备好读取数据
      }

      filein.close();
      fileout.close();
      System.out.println("消耗时间 : " + (System.currentTimeMillis() - time1));
    }catch(IOException e)
    {
      e.printStackTrace();
    }finally
    {}
  }
}
