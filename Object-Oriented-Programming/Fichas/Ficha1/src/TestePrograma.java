import java.util.Scanner;

public class TestePrograma {
    public static void main(String[] args){
        //inicializacao de um scanner para leitura
        Scanner sc = new Scanner(System.in);

        Ficha1 f = new Ficha1(); // criar um objeto da classe que implementa os métodos

        /*
        System.out.println("Insira nome e saldo");
        String nome = sc.nextLine();
        float saldo = sc.nextFloat();
        String str = f.criaDescricaoConta(nome, saldo);
        System.out.println("Resposta = " + str);

        System.out.println("Insira os graus celsius");
        double graus = sc.nextDouble();
        System.out.println(f.celsiusParaFarenheit(graus));

        System.out.println("Insira os numeros para comparacao");
        int a = sc.nextInt();
        int b = sc.nextInt();
        System.out.println("Max is " + f.maximoNumeros(a,b));
        */

        System.out.println("Insira os numeros para ordenar");
        int a = sc.nextInt();
        int b = sc.nextInt();
        System.out.println(f.ordenaValores(a,b));
    }
}