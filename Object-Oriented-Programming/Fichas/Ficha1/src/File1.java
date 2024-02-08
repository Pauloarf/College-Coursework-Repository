import java.time.LocalDateTime;
import java.util.Scanner;

public class File1 {
    public static void main(String[] args){

        Scanner input = new Scanner(System.in);
        File1Functions file1Functions = new File1Functions();
        System.out.println("Choose the exercise you want to run from 1-7:");
        int exercise = input.nextInt();
        switch (exercise){
            case 1:
                System.out.println("Exercise 1:");
                System.out.println("Degrees in Celsius: ");
                double degrees = input.nextDouble();
                System.out.println("Degrees in Fahrenheit: " + file1Functions.celsiusToFahrenheit(degrees));
                break;
            case 2:
                System.out.println("Exercise 2:");
                System.out.println("Put two integers: ");
                int a = input.nextInt();
                int b = input.nextInt();
                System.out.println("The biggest value is: " + file1Functions.MaxNum(a, b));
                break;
            case 3:
                System.out.println("Exercise 3:");
                System.out.println("Put the name: ");
                String name = input.next();
                System.out.println("Put the account balance: ");
                double balance = input.nextDouble();
                String output = file1Functions.printsAccountDescription(name, balance);
                System.out.println(output);
                break;
            case 4:
                System.out.println("Exercise 4:");
                System.out.println("Put the amount you want to convert to pounds: ");
                double money = input.nextDouble();
                System.out.println("Put the conversion rate: ");
                double conversionRate = input.nextDouble();
                System.out.println(file1Functions.eurosToPounds(money, conversionRate));
                break;
            case 5:
                System.out.println("Put two Integers: ");
                a = input.nextInt();
                b = input.nextInt();
                System.out.println("Integers by order: " + Math.max(a,b) +" - " + Math.min(a,b));
                System.out.println("The average between them is: " +((double)(a+b)/2));
                break;
            case 6:
                System.out.println("Exercise 6:");
                int x = Integer.parseInt(args[0]);
                System.out.println("The factorial of " +x +" is " + file1Functions.factorial(x));
                break;
            case 7:
                System.out.println("Exercise 7:");
                LocalDateTime dateTime = LocalDateTime.now();
                int day = dateTime.getDayOfMonth();
                int month = dateTime.getMonthValue();
                int year = dateTime.getYear();
                int seconds = dateTime.getSecond();
                int minutes = dateTime.getMinute();
                int hour = dateTime.getHour();
                System.out.printf("Date: %d/%d/%d\nTime: %d:%d:%d\n",day,month,year,hour,minutes,seconds);
                long time = file1Functions.timeSpent();
                System.out.printf("Hour after executing: %d:%d:%d\n",LocalDateTime.now().getHour(),LocalDateTime.now().getMinute(),LocalDateTime.now().getSecond());
                System.out.println("Time spent in function: " +time +"ms");
                break;
            default:
                System.out.println("Not a valid exercise...");
        }
        System.out.println("GoodBye!");
        input.close();
    }
}