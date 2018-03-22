import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;
import java.io.*;
import javax.swing.filechooser.FileFilter;
import java.util.regex.*;

public class GCCTextArea extends TextArea
{
	MyGccMessage gccMessage;

	public GCCTextArea(MyGccMessage gccMessage){

		this.gccMessage = gccMessage;
		gccMessage.setEditText(this);
		textAreaInit();
		textEvent();
	}


	public void textAreaInit(){
		this.setBackground(new Color(43, 48, 59));
		this.setForeground(new Color(156,177,179));
		Font font = new Font(null, Font.PLAIN, 18);
		this.setFont(font);

	}

	public void textEvent(){
		
		this.addTextListener(new TextListener(){
			@Override
			public void textValueChanged(TextEvent e){
			 gccMessage.setSaveFlage(true);
			 
			 if(gccMessage.getFilePath() == null)
			 	gccMessage.getFrame().setTitle("saligia --- " + " * ");
			 else
			 	gccMessage.getFrame().setTitle("saligia --- " + new File(gccMessage.getFilePath()).getName() + " * ");
			}
		});
		this.addKeyListener(new KeyAdapter(){
			@Override
			public void keyPressed(KeyEvent e){
				if(e.getKeyCode() == KeyEvent.VK_S && e.isControlDown())
					GCCTextArea.this.saveFileAction();	
			}
		});
	}

	public void openFileAction(){
		JFileChooser openFileDialog	;
		File myGetFile = new File("./myOpen.file");
		File myOpenFile;
		String getpath;

		try{
			if(gccMessage.getSaveFlage() == true){
				this.saveFileAction();
			}

			if( !myGetFile.exists()){
				myGetFile.createNewFile();
				openFileDialog = new JFileChooser();
			}
			else{
				BufferedReader fin = new BufferedReader(new FileReader(myGetFile));
				
				getpath = fin.readLine();

				fin.close();
				
				if(getpath == null || !new File(getpath).isDirectory()){
					openFileDialog = new JFileChooser();
				}else{
					openFileDialog = new JFileChooser(getpath);
				}
			}

			openFileDialog.setFileFilter(new FileFilter(){
				@Override
				public boolean accept(File  f){
					if(f.isDirectory())
						return true;

					return Pattern.matches(".+\\.c", f.getName());
				}

				public String getDescription(){
					return this.toString();
				} 
			});

			int val = openFileDialog.showOpenDialog(null);

			if(val != JFileChooser.APPROVE_OPTION)
				return;

			File textfile = openFileDialog.getSelectedFile();
			BufferedWriter fout = new BufferedWriter(new FileWriter("./myOpen.file"));

			fout.write(textfile.getParent() + "\n");
			fout.flush();
			fout.close();
			
			if(!textfile.exists())
				textfile.createNewFile();

			if(!textfile.canRead() || !textfile.canWrite())
				return;

			gccMessage.setFilePath(textfile.getAbsolutePath());

			openFile();			

		}catch(Exception e){
			new ExitDialog(gccMessage.getFrame(), e.getMessage());
			System.exit(0);
		}
	}	

	public void saveFileAction(){
		try{
			if(gccMessage.getFilePath() == null){
				JFileChooser saveFileDialog;
				File getFile = new File("./myOpen.file");
				String fileDir;

				if(!getFile.exists()){
					getFile.createNewFile();
					saveFileDialog = new JFileChooser();
				}else{
					BufferedReader fin = new BufferedReader(new FileReader(getFile));

					fileDir = fin.readLine();					
					fin.close();

					if(fileDir == null || !new File(fileDir).isDirectory())
						saveFileDialog = new JFileChooser();
					else
						saveFileDialog = new JFileChooser(fileDir);
				}

				saveFileDialog.setFileFilter(new FileFilter(){
					@Override
					public boolean accept(File f){
						if(f.isDirectory())
							return true;
						return false;
					}
					@Override
					public String getDescription(){
						return this.toString();
					}
				});

				int val = saveFileDialog.showSaveDialog(null);	
				
				if(val != JFileChooser.APPROVE_OPTION)
					return;

				File fileText = saveFileDialog.getSelectedFile();
				gccMessage.setFilePath(fileText.getAbsolutePath());

				if(!fileText.exists())
				fileText.createNewFile();
				
				BufferedWriter fout = new BufferedWriter(new FileWriter("./myOpen.file"));
				fout.write(fileText.getAbsolutePath() + "\n");

				fout.flush();
				fout.close();
			}
		
			if(gccMessage.getFilePath() == null)
				return;

			File textfile = new File(gccMessage.getFilePath());

			if(!textfile.canRead() || !textfile.canWrite())
				return;

			BufferedReader sin = new BufferedReader(new StringReader(this.getText()));
			BufferedWriter fout = new BufferedWriter(new FileWriter(textfile));

			String sbuf;

			while((sbuf= sin.readLine()) != null){
				fout.write(sbuf + "\n");
			}

			fout.flush();
			sin.close();
			fout.close();

			gccMessage.setDebugFlage(false);
			gccMessage.setSaveFlage(false);
			gccMessage.getFileList().showList();
			gccMessage.getFrame().setTitle("saligia ---- " + new File(gccMessage.getFilePath()).getName());

		}catch(IOException e){
			new ExitDialog(gccMessage.getFrame(), e.getMessage());
			System.exit(0);
		}

	}

	public void openFile(){
		try{
			File textfile = new File(gccMessage.getFilePath());
			
			if(!textfile.exists())
				return;

			this.setText("");

			BufferedReader fin = new BufferedReader(new FileReader(textfile));

			String sbuf;
			while((sbuf = fin.readLine()) != null){
				this.append(sbuf +"\n");
			}

			fin.close();
			gccMessage.setDebugFlage(false);
			gccMessage.setSaveFlage(false);
			gccMessage.getFileList().showList();
			gccMessage.getFrame().setTitle("saligia ---- " + new File(gccMessage.getFilePath()).getName());

		}catch(IOException e){
			new ExitDialog(gccMessage.getFrame(), e.getMessage());
			System.exit(0);
		}
	}
}