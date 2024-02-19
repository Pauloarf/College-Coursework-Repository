import java.util.Scanner;

public class TestePrograma {
    public static void main(String[] args){
        //inicializacao de um scanner para leitura

        Scanner sc = new Scanner(System.in);
        System.out.println("Escolha o exercicio que quer realizar (1-7):");

        int ex = sc.nextInt();
        int num1;
        int num2;

        Ficha1 f = new Ficha1(); // criar um objeto da classe que implementa os métodos

        switch(ex){
            case 1:
                System.out.println("Insira os graus celsius:");
                double graus = sc.nextDouble();
                System.out.println("Graus em farenheit: " + f.celsiusParaFarenheit(graus) + "°F");
                break;
            case 2:
                System.out.println("Insira os numeros a serem comparados:");
                System.out.println("Numero a: ");
                num1 = sc.nextInt();
                System.out.println("Numero b: ");
                num2 = sc.nextInt();
                System.out.println("Max is " + f.maximoNumeros(num1,num2));
                break;
            case 3:
                System.out.println("Insira o nome: ");
                sc.nextLine();
                String nome = sc.nextLine();
                System.out.println("Insira o saldo: ");
                float saldo = sc.nextFloat();
                String str = f.criaDescricaoConta(nome, saldo);
                System.out.println("Resposta = " + str);
                break;
            case 4:
                System.out.println("Insira o valor que quer converter:");
                System.out.println("Valor em euros: ");
                double euros = sc.nextDouble();
                System.out.println("Insira a taxa de conversão");
                System.out.println("Taxa: ");
                double taxa = sc.nextDouble();
                System.out.println("Valor em libras: " + f.eurosParaLibras(euros, taxa));
                break;
            case 5:
                System.out.println("Insira os numeros que quer ordenar");
                System.out.println("Numero a:");
                num1 = sc.nextInt();
                System.out.println("Numero b:");
                num2 = sc.nextInt();
                System.out.println("Valores ordenados = [" + f.ordenaValores(num1,num2) + "]");
                break;
            case 6:
                System.out.println("Insira o numero para obter o seu factorial:");
                num1 = sc.nextInt();
                System.out.println("Factorial: " + f.factorial(num1));
                break;
            case 7:
                long millisecondsDifference = f.tempoGasto();
                System.out.println("Difference in milliseconds: " + millisecondsDifference);
                break;
            default:
                System.out.println("O numero que colocou nao esta correto...\nTry again!!");
        }

    }
}