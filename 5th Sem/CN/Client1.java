import java.io.*;
import java.net.*;

public class Client1 {

    public static void main(String args[]) {
        DatagramSocket sock = null;
        int port = 7799;
        String s;

        byte[] buffer = new byte[65536];
        DatagramPacket incoming = new DatagramPacket(buffer, buffer.length);

        try {
            sock = new DatagramSocket(7799);

            while (true) {

                sock.receive(incoming);
                byte[] data = incoming.getData();
                s = new String(data, 0, incoming.getLength());

                System.out.println(s);
            }
        }

        catch (IOException e) {
            System.err.println("IOException " + e);
        }
    }
}
