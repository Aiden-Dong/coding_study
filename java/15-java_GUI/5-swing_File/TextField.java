import javax.swing.*;
import javax.swing.event.*;
import javax.swing.text.*;
import java.awt.*;
import java.awt.event.*;

public class TextField extends JFrame
{
  private JButton
     b1 = new JButton("Get Text"),
     b2 = new JButton("Set Text");
  private JTextField
    t1 = new JTextField(30),
    t2 = new JTextField(30),
    t3 = new JTextField(30);
  private String s = "";
  private UpperCaseDocument ucd = new UpperCaseDocument();

  public TextField(String name)
  {
    super(name);

    t1.setDocument(ucd);

    ucd.addDocumentListener(new T1());
    t1.addActionListener(new T1A());
    b1.addActionListener(new B1());
    b2.addActionListener(new B2());

    this.setLayout(new FlowLayout());

    this.add(b1);
    this.add(b2);
    this.add(t1);
    this.add(t2);
    this.add(t3);
  }

  class T1 implements DocumentListener
  {
    public void changedUpdate(DocumentEvent e){}
    public void insertUpdate(DocumentEvent e)
    {
      t2.setText(t1.getText());
      t3.setText("Text : "+ t1.getText());
    }
    public void removeUpdate(DocumentEvent e)
    {
      t2.setText(t1.getText());
    }
  }

  class T1A implements ActionListener
  {
    private int count = 0;
    public void actionPerformed(ActionEvent e)
    {
      t3.setText("t1 Action Event " + count);
    }
  }

  class B1 implements ActionListener
  {
    public void actionPerformed(ActionEvent e)
    {
      if(t1.getSelectedText() == null)
        s = t1.getText();
      else
        s = t1.getSelectedText();
      t1.setEditable(true);
    }
  }
  class B2 implements ActionListener
  {
    public void actionPerformed(ActionEvent e)
    {
      ucd.setUpperCase(false);
      t1.setText("Inserted by button 2 : " + s);
      ucd.setUpperCase(true);
      t1.setEditable(false);
    }
  }

  public static void main(String[] args)
  {
    TextField one = new TextField("Hello world");
    one.setSize(375,200);
    one.setLocation(200, 100);
    one.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    one.setVisible(true);
  }
}
  class UpperCaseDocument extends PlainDocument
  {
    private boolean upperCase = true;
    public void setUpperCase(boolean flag)
    {
      upperCase = flag;
    }
    public void insertString(int offset, String str, AttributeSet attSet)throws BadLocationException
    {
      if(upperCase)
        str = str.toUpperCase();
        super.insertString(offset, str, attSet);
    }
  }
