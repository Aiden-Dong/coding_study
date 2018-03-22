import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;

public class MyList{
	public static void main(String[] args){
		 Frame cnt = new Frame("List");

		 cnt.setLayout(new FlowLayout(FlowLayout.CENTER));
		 cnt.setSize(200,400);
		 cnt.setLocation(100, 100);
		
		 cnt.addWindowListener(new WindowAdapter(){
		 	@Override
		 	public void windowClosing(WindowEvent e){
		 		System.exit(0);
		 	}
		 });

		 List lst = new List(7, false);
		 
		 TextField lineText = new TextField();
		 lineText.setColumns(20);
		 lineText.addKeyListener(new KeyAdapter(){
		 	@Override
		 	public void keyPressed(KeyEvent e){
		 		if(e.getKeyCode() == KeyEvent.VK_ENTER){
		 			lst.add(lineText.getText());
		 			lineText.setText("");
		 		}
		 	}
		 }) ;
		 cnt.add(lst);
		 cnt.add(lineText);

		 cnt.setVisible(true);

	}
}

