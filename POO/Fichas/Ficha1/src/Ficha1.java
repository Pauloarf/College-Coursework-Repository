import java.lang.Math;
import java.time.LocalDateTime;
import java.time.temporal.ChronoUnit;

public class Ficha1 {
    //implementação dos metodos que permitem
    //responder a cada um dos exercicios propostos

    // Pergunta 3: Ler um nome (String) e um saldo (decimal)
    // e imprimir uma String texto com os resultados.
    // Nota: o método devolve uma String que será
    // impressa no programa principal (na main)

    public double celsiusParaFarenheit(double graus){
        return (graus * (9.0 / 5) + 32);
    }

    public int maximoNumeros(int a, int b){
        return Math.max(a, b);
    }

    public String criaDescricaoConta(String nome, float saldo){
        return "Nome: " + nome + ", saldo: " + saldo;
    }

    public double eurosParaLibras(double valor, double taxaConversao){
        return valor * taxaConversao;
    }

    public String ordenaValores(int a, int b){
        int max = Math.max(a,b);
        int min = Math.min(a,b);
        int average = (max + min)/2;
        return max + " " + average + " " + min;
    }

    public long factorial(int num){
        int result = num;
        for (int i = num-1; i > 0; i--) {
            result *= i;
        }
        return result;
    }

    public long tempoGasto(){
        LocalDateTime currentDateTime = LocalDateTime.now();

        System.out.println("Data: " + currentDateTime.getYear() + "/" + currentDateTime.getMonthValue() + "/" + currentDateTime.getDayOfMonth());
        System.out.println("Hora antes factorial: " + currentDateTime.getHour() + ":" + currentDateTime.getMinute() + ":" + currentDateTime.getSecond());

        factorial(5000);

        LocalDateTime currentDateTime2 = LocalDateTime.now();
        System.out.println("Hora apos factorial: " + currentDateTime2.getHour() + ":" + currentDateTime2.getMinute() + ":" + currentDateTime2.getSecond());

        return ChronoUnit.MILLIS.between(currentDateTime, currentDateTime2);
    }
}