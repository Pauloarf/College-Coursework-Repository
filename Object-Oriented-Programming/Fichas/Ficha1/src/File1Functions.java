import java.math.BigInteger;
import java.time.Duration;
import java.time.Instant;

public class File1Functions {
    public double celsiusToFahrenheit(double degrees){
        return degrees * 1.8 + 32;
    }
    public int MaxNum(int a, int b){
        return Math.max(a, b);
    }

    public long factorial(int num){
        int fact = 1;
        for(int i = 1; i <= num; i++){
            fact *= i;
        }
        return fact;
    }

    public void bigFactorial(int num){
        if(num < 0){
            return;
        }
        BigInteger fact = BigInteger.ONE;
        for(int i = 1; i <=num; i++){
            fact = fact.multiply(BigInteger.valueOf(i));
        }
    }

    public long timeSpent(){
        Instant start = Instant.now();
        bigFactorial(5000);
        Instant end = Instant.now();
        return Duration.between(start, end).toMillis();
    }

    public String printsAccountDescription(String name, double balance){
        return "This account belongs to " + name + ", and you have a balance of " + balance;
    }

    public double eurosToPounds(double value, double conversionRate){
        return (value * conversionRate);
    }
}
