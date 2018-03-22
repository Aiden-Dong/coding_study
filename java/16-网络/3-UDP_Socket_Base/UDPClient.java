import java.net.*;

public class UDPClient
{
	public static void main(String[] args)throws Exception{
		byte[] buf = new String("Hello world").getBytes();		// create a byte array

		DatagramPacket dp = new DatagramPacket(buf, buf.length,
												new InetSocketAddress("127.0.0.1", 8068));
		DatagramSocket ds = new DatagramSocket(9999);
		ds.send(dp);
		ds.close();

	}
}