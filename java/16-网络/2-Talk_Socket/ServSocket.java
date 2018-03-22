 import java.util.*;
 import java.io.*;
 import java.net.*;
 import java.util.concurrent.*;

 /*
 *			Service Socket
 */


class SystemIn implements Runnable
{
	Socket sock;
	BufferedReader fin;
	DataOutputStream sout;


	public SystemIn(Socket sock)
	{
		try{
			this.sock = sock;
			fin = new BufferedReader(new InputStreamReader(System.in));
			sout = new DataOutputStream(sock.getOutputStream());	
		}catch(Exception e){e.printStackTrace();}
		
	}

	@Override
	public void run()
	{
		String buff;

		try{
			while((buff = fin.readLine()) != "end")
			{
				sout.writeUTF(buff);
			}

			if(buff == "end")
				System.exit(0);
		}catch(Exception e){
			e.printStackTrace();
		}
		
	}
}

public class ServSocket
{
	public static void main(String[] args){

		ExecutorService exec = Executors.newCachedThreadPool();
		ServerSocket serSocket; 
		Socket cliSocket;

		try{
			serSocket = new ServerSocket(8068);
			cliSocket = serSocket.accept();
			System.out.println("Get Connect : " + cliSocket.getInetAddress() + " : " + cliSocket.getPort());
			exec.execute(new SystemIn(cliSocket));
			DataInputStream sin = new DataInputStream(cliSocket.getInputStream());

			while(true)
			{
				System.out.println(sin.readUTF());
			}

		}catch(Exception e){e.printStackTrace();}
	}
}