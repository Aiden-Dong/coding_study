import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.regex.*;
import java.util.HashMap;

public class GCCList extends List{

	MyGccMessage gccMessage;
	HashMap<String, File> fileList = new HashMap<String, File>();

	public GCCList(MyGccMessage gccMessage){
		this.gccMessage = gccMessage;
		gccMessage.setFileList(this);
		listInit();
		addListEvent();
	}

	private void listInit()
	{
		this.setBackground(new Color(56,70, 70));
		this.setForeground(new Color(120, 100, 153));
		Font font = new Font(null, Font.PLAIN, 17);
		this.setFont(font);
	}

	public void addListEvent(){
		this.addItemListener(new ItemListener(){
			@Override
			public void itemStateChanged(ItemEvent e){
				if(e.getStateChange() == ItemEvent.SELECTED)
				{
					if(gccMessage.getSaveFlage() == true){
						gccMessage.getEditText().saveFileAction();
					}
					File textFile = fileList.get(GCCList.this.getItem((int)e.getItem()));

					if(!textFile.exists() || !textFile.canWrite()){
						fileList.remove(textFile.getName());
						return;
					}

					gccMessage.setFilePath(textFile.getAbsolutePath());
					gccMessage.getEditText().openFile();
				}
			}
		});
	}

	public void showList()
	{
		fileList.clear();
		this.removeAll();

		if(gccMessage.getFilePath() == null)
			return;

		Pattern pattern = Pattern.compile(".+\\.c");

		File curDir = new File(new File(gccMessage.getFilePath()).getParent());

		for(File one : curDir.listFiles()){
			if(pattern.matcher(one.getName()).matches())
			{
				this.add(one.getName());
				fileList.put(one.getName(), one);	
			}
		}
	}
}