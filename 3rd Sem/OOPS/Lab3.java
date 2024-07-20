// 3: A class called Employee which models am employee with an id, name and salary is designed as shown in the class diagram.
// the method raiseSalary(percentage) increases the salary by the given percentage.
// Develop the employee class and suitable main method to demonstration.
import java.util.Scanner;

class Employee 
{
    String id, name;
    double salary, percentage;

    void read() 
    {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter ID, Name, Salary");
        id = s.next();
        name = s.next();
        salary = s.nextDouble();
        s.close();
    }

    void display() 
    {
        System.out.println(id + "\t" + name + "\t" + salary);
    }

    void raise(double percentage) 
    {
        salary += (percentage / 100) * salary;
    }
}

public class Lab3 {
    public static void main(String[] args) 
    {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the number of employee");
        int n = s.nextInt();
        Employee e[] = new Employee[n];
        for (int i = 0; i < n; i++) 
        {
            e[i] = new Employee();
            e[i].read();
        }
        System.out.println("ID\tName\tSalary\n");
        for (int i = 0; i < n; i++)
            e[i].display();
        System.out.println("Enter percentage");
        double per = s.nextDouble();
        for (int i = 0; i < n; i++)
            e[i].raise(per);
        System.out.println("ID\tName\tSalary");
        for (int i = 0; i < n; i++)
            e[i].display();
        s.close();
    }
}