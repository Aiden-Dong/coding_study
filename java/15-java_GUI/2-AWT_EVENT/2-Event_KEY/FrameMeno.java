import java.awt.*;
import java.awt.event.*;

public class FrameMeno
{
  private Frame frame;
  private TextField tf;


  public FrameMeno(String title, int x, int y)
  {
    init(title, x, y);
    frameCloseEvent();
    textKeyEvent();
    frameKeyEvent();
  }

  private void init(String title, int x, int y)
  {
    frame = new Frame(title);
    tf = new TextField(30);

    frame.add(tf);
    frame.setLayout(new FlowLayout());
    frame.setSize(x, y);
    frame.setLocation(300, 100);
    frame.setVisible(true);
  }

  private void frameCloseEvent()
  {
    frame.addWindowListener(new WindowAdapter()
    {
      public void windowClosing(WindowEvent e)
      {
        System.exit(0);
      }
    });
  }

  private void textKeyEvent()
  {

  }
  private void frameKeyEvent()
  {
    // 添加键盘事件
    frame.addKeyListener(new KeyAdapter()
    {
      // 键盘按下的事件 ------------ 控制字符
      public void keyPressed(KeyEvent e)
      {
        System.out.println("按键被激活 : " + KeyEvent.getKeyText(e.getKeyCode()));
      }
      // 键盘弹起事件
      public void keyRelased(KeyEvent e)
      {
          System.out.println("按键被释放 ： " + e.getKeyCode());
      }
      // 键入某个键的事件 ------------------ 字符按键
      public void keyTyped(KeyEvent e)
      {
        System.out.println("按键被按下 ： " + e.getKeyChar());
      }
    });

    tf.addKeyListener(new KeyAdapter()
    {
      public void keyPressed(KeyEvent e)
      {
        int code = e.getKeyCode();
        if(!(code >= KeyEvent.KV_0 && code <= KeyEvent.KV_9))
        {
          e.consume();
        }
        System.out.println("按键被激活 : " + KeyEvent.getKeyText(e.getKeyCode()));
      }
    });
  }
}
