import java.nio.*;
import java.io.*;
import java.nio.channels.FileChannel;
/*
* 存储映像式  IO
*/
public class CopyFile
{
  public static void main(String[] args) throws IOException
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

    FileChannel fi = new RandomAccessFile(fin, "r").getChannel();
    FileChannel fo = new RandomAccessFile(fout, "rw").getChannel();

    ByteBuffer ibuff = fi.map(FileChannel.MapMode.READ_ONLY, 0, fi.size());
    ByteBuffer obuff = fo.map(FileChannel.MapMode.READ_WRITE, 0, fi.size());

    while(ibuff.hasRemaining())
      obuff.put(ibuff.get());

  System.out.println("消耗时间 : " + (System.currentTimeMillis() - time1));
  }
}
