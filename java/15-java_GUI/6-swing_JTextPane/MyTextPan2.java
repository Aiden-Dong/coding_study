import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;

public class MyTextPane extends JFrame
{
  
  private JButton     b = new JButton("And Text");
  private JTextPane   tp = new JTextPane();
  private JLabel      label = new JLabel();

  public MyTextPane()
  {
    this.setSize(500, 300);
    this.setLocation(200, 100);
    this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    tp.addCaretListener(new CaretListener()
    {
      int num = tp.getCaretPosition();
      public void caretUpdate(CaretEvent e)
      {
        System.out.println("插入符发生变化 ： " + tp.getLineOfOffset(num));
      }
    });
    b.addActionListener(new ActionListener()
    {
      @Override
      public void actionPerformed(ActionEvent e)
      {
        for(int i = 0; i < 10; i++)
          tp.setText(tp.getText() + "hello world : " + i + "\n");
      }
    });

    add(new JScrollPane(tp));
    add(BorderLayout.SOUTH, b);
    this.setVisible(true);
  }

  public static void main(String[] args)
  {
      new MyTextPane();
  }
}
