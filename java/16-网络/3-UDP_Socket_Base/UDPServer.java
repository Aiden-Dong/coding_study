import java.net.*;
import java.lang.*;

/*
*		UDP Datagram
*/

public class UDPServer{

	public static void main(String[] args)throws Exception
	{
		byte[] buff = new byte[1024];

		DatagramPacket dp = new DatagramPacket(buff, buff.length);			// recv Data
		DatagramSocket ds = new DatagramSocket(8068);

		while(true){
			ds.receive(dp);												// receive datagram
			System.out.println(new String(buff, 0, dp.getLength()));			// Print datagram
		}
	}
	
}