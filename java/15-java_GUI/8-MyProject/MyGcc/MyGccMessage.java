import java.awt.*;
import java.awt.event.*;

public class MyGccMessage{
	// component -- Area
	private GCCTextArea	gccEditText;
	private TextArea		gccDebugText;
	private GCCList 		gccFileList;
	private GCCFrame		gccFrame;
	// message	--- Area
	private String		filePath;
	// flag		-- Area
	private boolean		fileSave;
	private boolean		debugFlage;

	public MyGccMessage(){
		fileSave = false;
		debugFlage = false;
	}

	public void setFrame(GCCFrame frame){
		gccFrame = frame;
	}
	public void setEditText( GCCTextArea textArea){
		this.gccEditText	 = textArea;
	}
	public void setDebugText(TextArea debugText){
		this.gccDebugText = debugText;
	}
	public void setFileList(GCCList list){
		this.gccFileList = list;
	}

	public GCCTextArea getEditText(){
		return gccEditText;
	}
	public TextArea getDebugText(){
		return gccDebugText;
	}
	public GCCList getFileList(){
		return gccFileList;
	}

	public GCCFrame getFrame(){
		return gccFrame;
	}

	public void setFilePath(String path){
		filePath = path;
	}
	public String getFilePath(){
		if(filePath == null){
			return null;
		}

		return filePath;
	}
	public void setSaveFlage(boolean flag){
		this.fileSave = flag;
	}
	public boolean getSaveFlage(){
		return fileSave;
	}

	public void setDebugFlage(boolean flage){
		this.debugFlage = flage;
	}
	public boolean getDebugFlage(){
		return this.debugFlage;
	}
}