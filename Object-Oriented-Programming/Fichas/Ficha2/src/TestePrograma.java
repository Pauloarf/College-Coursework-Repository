import java.util.Arrays;
import java.util.Scanner;

public class TestePrograma {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.println("Escolha o exercicio que quer realizar (1-x):");

        int ex = sc.nextInt();

        switch (ex){
            case 1:
                System.out.println("Insira o tamanho do array:");
                int arraySize = sc.nextInt();
                sc.nextLine(); // Consume the newline character after reading the integer

                int[] arr = new int[arraySize];
                System.out.println("Insira os numeros a serem inseridos no array:");
                String numeros = sc.nextLine();
                Scanner nsc = new Scanner(numeros);

                for (int i = 0; i < arraySize && nsc.hasNextInt(); i++) {
                    arr[i] = nsc.nextInt();
                }

                IntArray intArray = new IntArray(arr);
                System.out.println(Arrays.toString(intArray.array));
                break;
            case 2:
                break;
            case 3:
                break;
            default:
                System.out.println("O numero que colocou nao esta correto...\nTry again!!");
        }
    }
}

