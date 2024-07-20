// 2a: Write a java program to develop a simple calculator using switch statement.
import java.util.Scanner;

class Lab2a
{
    public static void main(String[] args) 
    {
        Scanner s = new Scanner(System.in);
        int a, b;
        float c = 0;
        System.out.println("Enter 2 numbers: ");
        a = s.nextInt();
        b = s.nextInt();
        System.out.println("Enter the Operator to perform the operation: ");
        char op = s.next().charAt(0);
        switch (op) 
        {
            case '+':
                c = a + b;
                break;
            case '-':
                c = a - b;
                break;
            case '*':
                c = a * b;
                break;
            case '/':
                if (a == 0 || b == 0) 
                {
                    System.out.println("ZeroDivisionError");
                    break;
                } else {
                    c = (float) a / b;
                    break;
                }
            default:
                System.out.println("Invalid Input");
                break;
        }
        System.out.println("Result of " + a + op + b + "=" + c);
        s.close();
    }
}