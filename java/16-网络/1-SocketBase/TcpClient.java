import java.net.*;
import java.io.*;

/*
*	Tcp Client Socket :

*		  Socket(InetAddress address, int port) 	// Create a socket and specify the address to connect the server
*/

public class TcpClient{
	public static void main(String[] args){

		// Create a socket and specify the address and port of the server;
		Socket cliSocket;

		try{
			cliSocket = new Socket("127.0.0.1", 8068);
			
			DataInputStream cin = new DataInputStream(cliSocket.getInputStream());
			DataOutputStream cout = new DataOutputStream(cliSocket.getOutputStream());

			cout.writeUTF("hello world");

			System.out.println(cin.readUTF());
			cliSocket.close();
		}catch(Exception e){
			e.printStackTrace();
			//cliSocket.close();
		}
	}
}