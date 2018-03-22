import java.net.*;			// Network Package
import java.io.*;

/*
* server Socket: 
*/

public class TcpServer{
  public static void main(String[] args) throws Exception{
  	// create a server socket and wait for connect

  	Socket conClient;
    ServerSocket serSocket = new ServerSocket(8068);	

    // BLock and wait for client Connect 
    while(true){
    		conClient = serSocket.accept();

    		System.out.println("Get a Connect : " + conClient.getInetAddress() + " : " + conClient.getPort());
    		
    		DataInputStream sin = new DataInputStream(conClient.getInputStream());	 		// get socket Inputstream
    		DataOutputStream sout = new DataOutputStream(conClient.getOutputStream());		// get socket OutputStream
    		// echo
    		// readUTF ----------------- BLOCK

    		sout.writeUTF(sin.readUTF());
    }
  }
}
