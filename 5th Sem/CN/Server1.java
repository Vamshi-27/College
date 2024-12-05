import java.io.*;
import java.net.*;

public class Server1 {
    public static void main(String args[]) {
        DatagramSocket sock = null;

        try {
            sock = new DatagramSocket();
            String s;

            BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
            InetAddress host = InetAddress.getByName("localhost");

            while (true) {
                System.out.println("Enter message to send : ");
                s = (String) cin.readLine();
                byte[] b = s.getBytes();

                DatagramPacket dp = new DatagramPacket(b, b.length, host, 7799);
                sock.send(dp);

            }
        }

        catch (IOException e) {
            System.err.println("IOException " + e);
        }
    }
}
