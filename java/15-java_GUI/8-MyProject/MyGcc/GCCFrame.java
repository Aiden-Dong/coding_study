import java.awt.*;
import java.awt.event.*;

public class GCCFrame extends Frame
{
	MyGccMessage gccMessage = new MyGccMessage();

	GCCTextArea 	editText 	= new GCCTextArea(gccMessage);
	TextArea	debugText 	= new TextArea();
	GCCMenuBar 	gccMenubar 	= new GCCMenuBar(gccMessage);
	GCCList		gccList 		= new GCCList(gccMessage);

	public GCCFrame(String title)
	{
		gccMessage.setFrame(this);
		gccMessage.setDebugText(debugText);
		frameInit(title);
		addFrameEvent();
		addComponet();
		this.setVisible(true);
	}

	private void frameInit(String title){
		this.setTitle(title);
		this.setSize(900, 650);
		this.setLocation(200, 100);
		this.setBackground(new Color(33, 43, 57));
		
	}

	private void addComponet()
	{
		this.setMenuBar(gccMenubar);
		this.setLayout(null);
		this.add(gccList);
		this.add(editText);
		debugText.setBackground(new Color(58,62,69));
		debugText.setForeground(Color.ORANGE);
		debugText.setEditable(false);
		this.add(debugText);
	}

	@Override
	public void paint(Graphics g){
		gccList.setBounds(7, 52, 180, this.getHeight()-173);
		editText.setBounds(187, 52, this.getWidth()-190, this.getHeight()-173);
		debugText.setBounds(7, this.getHeight()-123,this.getWidth()-10, 120);
	}

	private void addFrameEvent(){
		this.addWindowListener(new WindowAdapter(){
			@Override
			public void windowClosing(WindowEvent e){
				System.exit(0);
			}
		});
		this.addComponentListener(new ComponentAdapter(){
			@Override
			public void componentResized(ComponentEvent e) {
			 	GCCFrame.this.repaint();
			 }
		});
	}	
}