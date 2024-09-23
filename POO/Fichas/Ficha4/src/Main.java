import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        System.out.println("Escolha o exercicio que pertende executar(1-8): ");

        Scanner sc = new Scanner(System.in);

        int ex = sc.nextInt();
        sc.nextLine();

        switch (ex){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            default:
                System.out.println("O numero de exercicio que escolheu não existe...");
        }
    }
}