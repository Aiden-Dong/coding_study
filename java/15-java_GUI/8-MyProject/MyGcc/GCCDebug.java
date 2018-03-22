import java.util.*;
import java.awt.*;
import java.awt.event.*;
import java.util.regex.*;
import java.io.*;

public class GCCDebug{
	
	static boolean debugAction(String path, TextArea window){
		boolean debugFlage = false;
		window.setText("");

		try{
			if(!Pattern.matches(".+\\.c", path))
			return false;
			
			File textFile = new File(path);
			String objFile = Pattern.compile("\\.c").matcher(path).replaceFirst(".obj");

			String[] command = new String[]{"g++", "-c", path, "-o", objFile};


			Process process = new ProcessBuilder(command).start();	

			BufferedReader debugDin = new BufferedReader(new InputStreamReader(process.getInputStream()));
			BufferedReader debugErr = new BufferedReader(new InputStreamReader(process.getErrorStream()));

			String strbuf;
			

			Pattern compath = Pattern.compile("^.+" + textFile.getName());
			Pattern errpat = Pattern.compile("error");

			debugFlage = true;
			while((strbuf = debugErr.readLine()) != null){
				
				Matcher errmat = errpat.matcher(strbuf);

				if(errmat.find())
					debugFlage = false;
				window.append(compath.matcher(strbuf).replaceFirst(textFile.getName()) + "\n");
			}	

			if(debugFlage == true)
				window.setText("Debug Sucess");

		}catch(IOException e){
			new ExitDialog(null,e.getMessage());
			System.exit(0);
		}
		
		return debugFlage;

	}


	static void runAction(String path, TextArea window){
		
		window.setText("");
		try{

			String objpath = Pattern.compile("\\.c").matcher(path).replaceFirst(".obj");
			String exepath = Pattern.compile("\\.c").matcher(path).replaceFirst(".exe");

			if(!new File(objpath).exists())
				return;

			String[] command = new String[]{"g++", objpath, "-o", exepath};


			Process process = new ProcessBuilder(command).start();	

			BufferedReader debugDin = new BufferedReader(new InputStreamReader(process.getInputStream()));
			BufferedReader debugErr = new BufferedReader(new InputStreamReader(process.getErrorStream()));

			String strbuf;

			while((strbuf = debugErr.readLine()) != null){		
				window.setText(strbuf + "\n");
			}

			if(!new File(exepath).exists())
				return;

//			exepath = "\\\"" + exepath + "\\\"";
//			new ExitDialog(null, exepath);

			String[] exeCom = new String[]{"CMD", "/k", "start", exepath};

			new ProcessBuilder(exeCom).start();

		}catch (IOException e){
			new ExitDialog(null, e.getMessage());
			System.exit(0);
		}
		
	}
}