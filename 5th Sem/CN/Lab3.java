// Program for error detection using CRC-CCITT (16-bits)

import java.util.Scanner;
import java.io.*;

public class Lab3 
{
    public static void main(String[] args) throws IOException
    {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        Scanner sc = new Scanner(System.in);
        int[] message;
        int[] gen;
        int[] appMessage;
        int[] rem;
        int[] transMessage;
        int messageBits, genBits, totalBits;

        System.out.println("Enter the number of bits in the message: ");
        messageBits = sc.nextInt();
        message = new int[messageBits];
        System.out.println("Enter the message bits: ");
        for (int i = 0; i < messageBits; i++) 
        {
            message[i] = sc.nextInt();
        }

        System.out.println("Enter the number of bits in the generator: ");
        genBits = sc.nextInt();
        gen = new int[genBits];
        System.out.println("Enter the generator bits: ");
        for (int i = 0; i < genBits; i++) 
        {
            gen[i] = sc.nextInt();
        }

        totalBits = messageBits + genBits - 1;
        appMessage = new int[totalBits];
        rem = new int[totalBits];
        transMessage = new int[totalBits];
        for (int i = 0; i < message.length; i++) 
        {
            appMessage[i] = message[i];
        }

        System.out.println("Message bits are: ");
        for (int i = 0; i < messageBits; i++) 
        {
            System.out.print(message[i] + " ");
        }

        System.out.println("\nGenerator bits are: ");
        for (int i = 0; i < genBits; i++) 
        {
            System.out.print(gen[i] + " ");
        }

        System.out.println("\nAppended message is: ");
        for (int i = 0; i < appMessage.length; i++) 
        {
            System.out.print(appMessage[i]);
        }

        rem = computecrc(appMessage, gen, rem);
        for (int i = 0; i < appMessage.length; i++) 
        {
            transMessage[i] = appMessage[i] ^ rem[i];
        }

        System.out.println("\nTransmitted message from the transmitter is: ");
        for (int i = 0; i < transMessage.length; i++) 
        {
            System.out.print(transMessage[i]);
        }

        System.out.println("\n\nEnter the received message of " + totalBits + " bits at the receiver end: ");
        for (int i = 0; i < transMessage.length; i++) 
        {
            transMessage[i] = Integer.parseInt(br.readLine());
        }

        System.out.println("Received message is: ");
        for (int i = 0; i < transMessage.length; i++) 
        {
            System.out.print(transMessage[i]);
        }

        for (int j = 0; j < transMessage.length; j++) 
        {
            rem[j] = transMessage[j];
        }

        rem = computecrc(transMessage, gen, rem);
        for (int i = 0; i < rem.length; i++) 
        {
            if (rem[i] != 0) {
                System.out.println("\nError detected in the received message.");
                break;
            }
            if (i == rem.length - 1) {
                System.out.println("\nNo error detected in the received message.");
            }
        }
    }

    static int[] computecrc(int appMessage[], int gen[], int rem[]) 
    {
        int current = 0;
        while (true) {
            for (int i = 0; i < gen.length; i++) 
            {
                rem[current + i] = (rem[current + i] ^ gen[i]);
            }
            while (rem[current] == 0 && current != rem.length - 1) 
            {
                current++;
            }
            if ((rem.length - current) < gen.length) 
            {
                break;
            }
        }
        return rem;
    }
}