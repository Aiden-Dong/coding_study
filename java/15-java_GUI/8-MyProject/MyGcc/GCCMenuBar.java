import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;
import java.io.*;
import javax.swing.filechooser.FileFilter;
import java.util.regex.*;

public class GCCMenuBar extends MenuBar
{
	Menu file, edit, project, other;
	MenuItem fontSize;
	MenuItem openFile, saveFile, exitFile;
	MenuItem debug, run;
	MenuItem about, help;

	MyGccMessage gccMessage;

	public GCCMenuBar(MyGccMessage gccMessage){
		this.gccMessage = gccMessage;
		menubarInit();
		addMenuEvent();
	}

	private void menubarInit(){

		file 		= new Menu("File");
		openFile 	= new MenuItem("Open");
		saveFile 	= new MenuItem("save");
		exitFile 	= new MenuItem("Exit");
		file.add(openFile);
		file.add(saveFile);
		file.add(exitFile);

		edit 		= new Menu("Edit");
		fontSize	= new MenuItem("Size");
		edit.add(fontSize);

		project 		= new Menu("Project");
		debug 		= new MenuItem("Debug");
		run 			= new MenuItem("Run");
		project.add(debug);
		project.add(run);

		other 		= new Menu("Other");
		about		= new MenuItem("About");
		help		= new MenuItem("help");
		other.add(about);
		other.add(help);

		this.add(file);
		this.add(edit);
		this.add(project);
		this.add(other);
	}

	private void addMenuEvent(){
		exitFile.addActionListener(new ActionListener(){
			@Override
			public void actionPerformed(ActionEvent e) 
 			{
 				System.exit(0);
 			}
		});
		openFile.addActionListener(new ActionListener(){
			@Override
			public void actionPerformed(ActionEvent e){
				gccMessage.getEditText().openFileAction();
			}
		});

		saveFile.addActionListener(new ActionListener(){
			@Override
			public void actionPerformed(ActionEvent e){
				gccMessage.getEditText().saveFileAction();
			}
		});

		debug.addActionListener(new ActionListener(){
			@Override
			public void actionPerformed(ActionEvent e){
				if(gccMessage.getSaveFlage())
					gccMessage.getEditText().saveFileAction();
				
				if(gccMessage.getFilePath() != null)
					gccMessage.setDebugFlage(
						GCCDebug.debugAction(gccMessage.getFilePath(), gccMessage.getDebugText())); 
			}
		});
		run.addActionListener(new ActionListener(){
			@Override
			public void actionPerformed(ActionEvent e){
				if(gccMessage.getFilePath() != null && gccMessage.getDebugFlage() == true)
					GCCDebug.runAction(gccMessage.getFilePath(), gccMessage.getDebugText());
			}
		});
	}

}