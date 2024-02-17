import java.lang.Math;

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
        return "" + max + " " + average + " " + min;
    }
}