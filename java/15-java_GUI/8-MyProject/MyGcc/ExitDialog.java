import java.awt.*;
import java.awt.Dialog.*;
import java.awt.event.*;
import javax.swing.*;
import java.io.*;

public class ExitDialog extends Dialog{
	
	JLabel showText	 = new JLabel();
	Button	 button  	 = new Button("I Know");

	public ExitDialog(Frame parent , String text){
		super(parent);
		labelSet();
		buttonSet();
		this.setSize(500, 300);
		this.setLocation(300, 200);
		this.setBackground(new Color(2, 69, 114));
		this.setModalityType(Dialog.ModalityType. APPLICATION_MODAL);
		this.setMinimumSize(new Dimension(500, 300));
		this.setMaximumSize(new Dimension(500, 300));
		this.addWindowListener(new WindowAdapter(){
			@Override
			public void windowClosing(WindowEvent e){
				ExitDialog.this.dispose();
			}
		});
		Box box = Box.createVerticalBox();
		box.add(showText);
		box.add(Box.createVerticalGlue());
		box.add(button);
		box.add(Box.createVerticalStrut(5));
		this.add(box);
		this.setText(text);
		this.setVisible(true);
	}

	private void labelSet(){
		Font font = new Font(null, Font.PLAIN, 16);
		showText.setFont(font);
		showText.setBackground(new Color(2, 69, 114));
		showText.setForeground(new Color(130,175,108));
	}
	
	public void setText(String text){
			BufferedReader sin = new BufferedReader(new StringReader(text));
			String str, htmlText;
			try{
			htmlText = "<html><body>";

			while((str = sin.readLine()) != null){
				htmlText += str + "<br>";
			}
			sin.close();
			htmlText += "</body></html>";
			
			showText.setText(htmlText);

		}catch(IOException e){
			htmlText = "Label error";
		}
	}

	private void buttonSet(){
		Font font = new Font(null, Font.PLAIN, 10);
		button.setFont(font);
		button.setBackground(new Color(16, 159, 222));
		button.setForeground(new Color(187,200,191));
		button.setMinimumSize(new Dimension(80, 30));
		button.setMaximumSize(new Dimension(80, 30));
		button.addActionListener(new ActionListener(){
			@Override
			public void actionPerformed(ActionEvent e){
				ExitDialog.this.dispose();
			}
		});
	}
}