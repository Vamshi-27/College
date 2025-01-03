// Lab 7: Using TCP/IP sockets, write a client – server program to make the client send the file name and to make the server send back the contents of the requested file if present.

// Client.java

import java.net.*; 
import java.io.*; 
public class Client
{
	public static void main( String args[ ] ) throws Exception
	{
		Socket sock = new Socket( "127.0.0.1", 4000);
		System.out.print("Enter the file name to display the contents of file");
		BufferedReader keyRead = new BufferedReader(new InputStreamReader(System.in)); 
		String fname = keyRead.readLine();
		try
		{
			OutputStream ostream = sock.getOutputStream( ); 
			PrintWriter pwrite = new PrintWriter(ostream, true); 
			pwrite.println(fname); 
			InputStream istream = sock.getInputStream();
			BufferedReader socketRead = new BufferedReader(new InputStreamReader(istream)); 
			String str;
			while((str = socketRead.readLine()) != null)
			{
				System.out.println(str);
			}
			pwrite.close();
			socketRead.close();
			keyRead.close();
		}
		catch(Exception e)
		{
			System.out.println("An error occured while opening the file");
		}
	}
}