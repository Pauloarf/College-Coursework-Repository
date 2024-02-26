import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class TestePrograma {
    public static List<Object> makeNewArray(){
        List<Object> result = new ArrayList<>();
        Scanner sc2 = new Scanner(System.in);

        System.out.println("Insira o tamanho do array:");
        int arraySize = sc2.nextInt();
        int n_elements = 0;

        sc2.nextLine(); // Consume the newline character after reading the integer

        int[] arr = new int[arraySize];
        System.out.println("Insira os numeros a serem inseridos no array:");
        String numeros = sc2.nextLine();
        Scanner nsc = new Scanner(numeros);

        for (int i = 0; i < arraySize && nsc.hasNextInt(); i++) {
            arr[i] = nsc.nextInt();
            n_elements++;
        }
        result.add(arr);
        result.add(n_elements);
        nsc.close();
        return result;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.println("Escolha o exercicio que quer realizar (1-x):");

        int ex = sc.nextInt();

        switch (ex){
            case 1:
                List<Object> result = makeNewArray();
                int[] arr = (int[]) result.get(0);
                int n_elements = (int) result.get(1);

                IntArray intArray = new IntArray(n_elements,arr);
                System.out.println(Arrays.toString(intArray.array));
                System.out.println("Valor minimo no array: " + intArray.MinimumValue());
                System.out.println("Escolha dois indices de modo a obter um array entre esses valores:");
                System.out.println("Indice a:");
                int a = sc.nextInt();
                System.out.println("Indice b:");
                int b = sc.nextInt();
                System.out.println(Arrays.toString(intArray.arrFromAtoB(a, b)));

                List<Object> result2 = makeNewArray();
                int[] arr2 = (int[]) result2.get(0);
                int n_elements2 = (int) result2.get(1);

                System.out.println(Arrays.toString(intArray.elementosComuns(arr2, n_elements2)));
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

