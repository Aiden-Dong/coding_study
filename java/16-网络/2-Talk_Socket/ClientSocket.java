 import java.util.*;
 import java.io.*;
 import java.net.*;
 import java.util.concurrent.*;
 /*
 *			Client_Socket 
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

 public class ClientSocket
 {
 	public static void main(String[] args)
 	{	
 		Socket clinSocket;
 		DataInputStream sin;
 		String str;
 		ExecutorService exec = Executors.newCachedThreadPool();

 		try{
 			clinSocket = new Socket("127.0.0.1", 8068);
 			exec.execute(new SystemIn(clinSocket));
 			sin = new DataInputStream(clinSocket.getInputStream());

 			while(true){
 				System.out.println(sin.readUTF());
 			}

	 	}catch(Exception e){

 		}
 	}
 }