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
                int[] arr = new int[arraySize];
                System.out.println("Insira os numeros a ser inseridos no array:");
                for (int i = 0; i < arraySize; i++) {
                    System.out.println(sc.toString());
                    arr[i] = sc.nextInt();
                    if (!sc.hasNext()) {
                        System.out.println("Não há mais entradas.");
                        break;
                    }
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

