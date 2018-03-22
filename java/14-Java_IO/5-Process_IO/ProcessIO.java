import java.lang.ProcessBuilder;
import java.lang.Process;
import java.io.*;

public class ProcessIO
{
	public static void main(String[] args)
	{
		if(args.length != 1)
			System.exit(0);

		String filename = new String(args[0]);
		String command = "gcc -c " + filename + " -o a.obj";
		System.out.println(command);

		try{
			Process process = new ProcessBuilder(command.split(" ")).start();	// 启动一个进程

			BufferedReader results = new BufferedReader(new InputStreamReader(process.getInputStream()));	// 获取标准输出
			BufferedReader errors = new BufferedReader(new InputStreamReader(process.getErrorStream()));	// 获取标准错误
			BufferedWriter fout	= new BufferedWriter(new FileWriter("show.txt"));

			String str;
			while(( str = errors.readLine()) != null)    // 标准错误输出
			{
				str += '\n';
				fout.write(str, 0, str.length());
			}
			fout.close();
		}catch(IOException e){
			e.printStackTrace();
		}
	}
}
