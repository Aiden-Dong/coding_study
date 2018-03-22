import java.awt.*;
import java.awt.event.*;

public class MyFrame
{
  private Frame frame;
  private Button button;

  MyFrame()
  {
    init();
    windowCloseEvent();
    buttonCloseEvent();
  }
  // 窗口布局
  public void init()
  {
    frame = new Frame("My Frame");
    frame.setBounds(300, 100, 700, 500);
    frame.setLayout(new FlowLayout());

    button = new Button("My Button");
    frame.add(button);
    frame.setVisible(true);
  }
  // 为窗口添加事件
  private void windowCloseEvent()
  {
    // 为窗口添加鼠标事件
    frame.addMouseListener(new MouseAdapter()
    {
      public void mouseClicked(MouseEvent e)
      {
        System.out.println("窗体中发生了鼠标点击事件");
      }
    });
  }
  // 为 button 添加事件
  private void buttonCloseEvent()
  {
    // 为按钮添加鼠标事件
    button.addMouseListener(new MouseAdapter()
    {
      public void mouseEntered(MouseEvent e)
      {
        System.out.println("鼠标进入事件");
      }
      public void mouseClicked(MouseEvent e)
      {
        if(e.getClickCount() == 5)
        {
          System.exit(0);
        }
        else if(e.getClickCount() == 2)
        {
          System.out.println("鼠标双击事件");
        }

      }
    });
  }

}
