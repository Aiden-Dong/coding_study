import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class MyFrame
{
  // 部件区域
  private JFrame        window;
  private ButtonGroup   buttongroup;
  private JButton       button;
  private JToggleButton toggle;
  private JRadioButton  radio, radio1;
  private JCheckBox     check, check2;

  public MyFrame()
  {
    myFrameinit();
  }

  // 构建窗体
  public void myFrameinit()
  {
    window = new JFrame("Hello world");

    // button 组件
    buttongroup = new ButtonGroup();

    button = new JButton("button");           // 普通 button
    toggle = new JToggleButton("toggle");     // 开关 button
    radio = new JRadioButton("radio");        // 单选框
    radio1 = new JRadioButton("rbdio");
    check = new JCheckBox("check");           // 复选框
    check2 = new JCheckBox("check2");
    buttongroup.add(radio);
    buttongroup.add(radio1);

    // 创建一个基本的窗体
    window.setSize(500, 300);
    window.setLayout(new FlowLayout());
    window.setLocation(300, 100);
    window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    // 为窗体添加部件
    window.add(button);
    window.add(toggle);
    window.add(radio);
    window.add(radio1);
    window.add(check);
    window.add(check2);

    window.setVisible(true);
  }
}
