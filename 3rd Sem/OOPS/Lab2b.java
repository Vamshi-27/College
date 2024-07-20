// Program to calculate the bill amount after discount.
/* Amount Discount
 <2000 5%
 2000-5000 25%
 5000-10000 35%
 >10000 50%*/

import java.util.Scanner;

public class Lab2b
{
    public static void main(String[] args) 
    {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the total cost: ");
        double bill = s.nextDouble();
        if (bill < 2000)
            bill -= 0.05 * bill;
        else if (bill <= 5000)
            bill -= 0.25 * bill;
        else if (bill <= 1000)
            bill -= 0.35 * bill;
        else
            bill -= 0.5 * bill;
        System.out.println("Total Bill= " + bill);
        s.close();
    }
}