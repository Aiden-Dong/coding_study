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
    // 关闭此程序事件
    frame.addWindowListener(new WindowAdapter(){
      public void windowClosing(WindowEvent e)
      {
        System.out.println("窗体关闭事件\n" + e.toString());
        System.exit(0);
      }
    });
  }
  // 为 button 添加事件
  private void buttonCloseEvent()
  {
    // button 的单击事件
    button.addActionListener(new ActionListener(){
      public void actionPerformed(ActionEvent e)
      {
        System.out.println("点击按钮事件\n" + e.toString());

      }
    });
  }

}
