import java.nio.*;
import java.io.*;
import java.nio.channels.*;

public class DataChange
{
  public static void main(String[] args)
  {
    try{
      FileChannel fout = new FileOutputStream("./one.txt").getChannel();    // 获取通道
      ByteBuffer buffer = ByteBuffer.allocate(100);

      CharBuffer ch = buffer.asCharBuffer();
      ch.put("hello world".toCharArray());
      /*
      *     CharBuffer 虽然从ByteBuffer 中继承来， 但是拥有根 CharBuffer 独立的指针点， limit 限制
      *     CharBuffer 与 ByteBuffer 共享的只是缓冲区
      */
      System.out.println(ch.limit());
      System.out.println(ch.capacity());
      System.out.println(ch.position());
      // 转 short
      ShortBuffer sh = buffer.asShortBuffer();
    //  sh.limit(ch.position());
      sh.put((short)23);

      // 转 int
      IntBuffer in = buffer.asIntBuffer();
      in.limit(ch.position()/2);

      buffer.limit(ch.position()*2);          // 重设现有存储区的空区

      while(buffer.hasRemaining())
      {
        System.out.print(buffer.get() + " ");
      }
      System.out.println();
      while(in.hasRemaining())
      {
        System.out.print(in.get() + " ");
      }

      System.out.println();

      buffer.rewind();
      fout.write(buffer);
      fout.close();

    }catch(IOException e)
    {
      e.printStackTrace();
    }
  }
}
