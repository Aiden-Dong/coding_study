import java.awt.*;
import java.awt.event.*;

public class MyFrame extends Frame
{
  Panel panel1 = new Panel();
  Panel panel2 = new Panel();
  Panel panel3 = new Panel();

  Button butt1 = new Button("one");
  Button butt2 = new Button("two");
  Button butt3 = new Button("three");

  Button bord1 = new Button("Center");
  Button bord2 = new Button("North");
  Button bord3 = new Button("South");
  Button bord4 = new Button("East");
  Button bord5 = new Button("West");


  public MyFrame(String title)
  {
    frameInit(title);
    panelInit();
    this.setVisible(true);
  }

  // set Frame
  public void frameInit(String title){
    this.setTitle(title);
    this.setSize(700, 500);
    this.setLocation(200, 100);
    this.setBackground(new Color(33, 43, 57));
    this.setLayout(null);
    this.setMinimumSize(new Dimension(700, 500));           // setMinimumSize(Dimension)
    this.setMaximumSize(new Dimension(700, 500));           // setMaximumSize(Dimension);

    this.addWindowListener(new WindowAdapter(){
      @Override
      public void windowClosing(WindowEvent e){
        System.exit(0);
      }
    });
  }

  public void panelInit()
  {
    panel1.setBackground(Color.WHITE);
    panel2.setBackground(Color.ORANGE);
    panel3.setBackground(Color.GRAY);
    
    panel1.setBounds(0, 35, this.getWidth()/2, this.getHeight()/5*4-35);
    panel2.setBounds(this.getWidth()/2, 0, this.getWidth()/2, this.getHeight()/5*4);
    panel3.setBounds(0, this.getHeight()/5*4, this.getWidth(), this.getHeight()/5);

    // FlowLayout
    FlowLayout flow = new FlowLayout(FlowLayout.LEFT);
    flow.setHgap(20);
    panel3.setLayout(new FlowLayout(FlowLayout.LEFT));
    panel3.add(butt1);
    panel3.add(butt2);
    panel3.add(butt3);

    // BorderLayout
    panel1.setLayout(new BorderLayout());
    
    panel1.add(bord2, BorderLayout.NORTH);
    panel1.add(bord1, BorderLayout.CENTER);
    panel1.add(bord3, BorderLayout.SOUTH);
    panel1.add(bord4, BorderLayout.EAST);
    panel1.add(bord5, BorderLayout.WEST);

    this.add(panel1);
    this.add(panel2);
    this.add(panel3);
  }

  public static void main(String[] args){
    new MyFrame("Hello world");
  }
  
}