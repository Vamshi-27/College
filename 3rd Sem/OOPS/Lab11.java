import java.util.Random;

class Square implements Runnable 
{
    Thread t;
    int x;

    Square(int n) 
    {
        x = n;
        t = new Thread(this, "Square");
        t.start();
    }

    public void run() 
    {
        System.out.println("Square: " + x * x);
    }
}

class Cube implements Runnable 
{
    Thread t;
    int x;

    Cube(int n) 
    {
        x = n;
        t = new Thread(this, "Cube");
        t.start();
    }

    public void run() 
    {
        System.out.println("Cube: " + x * x * x);
    }
}

class Generate implements Runnable 
{
    Thread t;

    Generate() 
    {
        t = new Thread(this, "Generate");
        t.start();
    }

    public void run() 
    {
        int n, i = 3;

        Random r = new Random();
        while (i-- > 0) {
            n = r.nextInt(100);
            System.out.println("Generate: " + n);
            new Square(n);
            new Cube(n);
            try 
            {
                Thread.sleep(1000);
            } catch (InterruptedException e) 
            {
                System.out.println("Interrupted");
            }
        }
    }
}

public class Lab11 
{
    public static void main(String[] args) 
    {
        new Generate();
    }
}