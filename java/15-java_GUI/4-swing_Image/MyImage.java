import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class MyImage extends JFrame
{
  private JLabel label;
  private JButton button;

  ImageIcon image = new ImageIcon("25.jpg");
  ImageIcon buimg = new ImageIcon("13.jpg");

  public MyImage(String name)
  {
    super(name);
    myInit();
  }

  private void myInit()
  {
    this.setSize(500, 300);
    this.setLocation(300, 100);
    this.setLayout(new FlowLayout());

    // 设置图片的大小
    image.setImage(image.getImage().getScaledInstance(500, 200,Image.SCALE_DEFAULT));
    buimg.setImage(buimg.getImage().getScaledInstance(50,20,Image.SCALE_DEFAULT));


    label = new JLabel();
    button = new JButton("OK");

    button.setIcon(buimg);
    label.setIcon(image);
    this.add(label);
    this.add(button);

    //his.setIcon(icon);
    this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    this.setVisible(true);
  }
}
