import java.awt.*;
import java.awt.event.*;
import java.util.*;
/*
*     布局管理器件
*/

public class Yard extends Frame
{
  // 定义贪吃蛇的行和列
  public static final int ROWS = 50;                                           // 行数
  public static final int CLOS = 50;                                           // 列数
  public static final int BLOCK_SIZE = 10;                                      // 块大小

  Snake s = new Snake();
  //Image offScreenImage = null;
  @Override
  public void paint(Graphics g)                                                 // 绘画区
  {
    Color c = g.getColor();                 // 获取原先的颜色
    g.setColor(Color.GRAY);                 // 设置新的颜色
    g.fillRect(0, 0, CLOS*BLOCK_SIZE, ROWS*BLOCK_SIZE); // 绘图
    //
    g.setColor(Color.DARK_GRAY);

    // 划出横线
    for(int i = 1; i < ROWS; i++)
        g.drawLine(0, i*BLOCK_SIZE, CLOS*BLOCK_SIZE, i*BLOCK_SIZE);
    for(int i = 1; i < CLOS; i++)
        g.drawLine(i*BLOCK_SIZE, 0, i*BLOCK_SIZE, ROWS*BLOCK_SIZE);

    s.draw(g);
    g.setColor(c);
  }
  private class PaintThread extends Thread
  {
    public void run()
    {
      while(true)
      {
        repaint();
        try{
          Thread.sleep(50);
        }catch(InterruptedException e)
        {
          e.printStackTrace();
        }
      }
    }
  }
  public void launch()
  {
    this.setLocation(300, 200);
    this.setSize(CLOS*BLOCK_SIZE, ROWS*BLOCK_SIZE);                             // 定义大小
    this.addWindowListener(new WindowAdapter()
    {
      @Override
      public void windowClosing(WindowEvent e)
      {
        System.exit(0);
      }
    });
    this.setVisible(true);
  }

  public static void main(String[] args)
  {
    Yard yard = new Yard();
    yard.launch();
    PaintThread pt = yard.new PaintThread();
    pt.start();
  }
}
