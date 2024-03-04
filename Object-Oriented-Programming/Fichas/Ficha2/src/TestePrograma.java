import java.lang.reflect.Array;
import java.sql.SQLOutput;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class TestePrograma {
    //TODO Alterar esta função... caso o tamnho seja menor, mudar tamanho do array, simplificar
    public static int[] makeNewArray(Scanner sc){
        List<Object> result = new ArrayList<>();

        System.out.println("Insira o tamanho do array:");
        int arraySize = sc.nextInt();
        int n_elements = 0;

        sc.nextLine(); // Consume the newline character after reading the integer

        int[] arr_temp = new int[arraySize];
        System.out.println("Insira os numeros a serem inseridos no array:");
        String numeros = sc.nextLine();
        Scanner nsc = new Scanner(numeros);

        for (int i = 0; i < arraySize && nsc.hasNextInt(); i++) {
            arr_temp[i] = nsc.nextInt();
            n_elements++;
        }

        return Arrays.copyOfRange(arr_temp, 0, n_elements);
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.println("Escolha o exercicio que quer realizar (1-x):");

        IntArray intArray = new IntArray();
        int ex = sc.nextInt();

        switch (ex){
            case 1:
                int[] arr1 = makeNewArray(sc);
                System.out.println("O valor minimo do array é: " + intArray.MinimumValue(arr1));
                System.out.println("Dado dois indices, determinar o array com valores entre esses indices: ");
                System.out.println("Indice a: ");
                int indexA = sc.nextInt();
                System.out.println("Indice b: ");
                int indexB = sc.nextInt();
                System.out.println("O array originado é: " + Arrays.toString(intArray.arrFromAtoB(arr1, indexA, indexB)));
                System.out.println("Numeros comuns a dois array:");
                System.out.println("Introduzir o segundo array: ");
                int[] arr2 = makeNewArray(sc);
                System.out.println("Numeros em comum: " + Arrays.toString(intArray.elementosComuns(arr1, arr2)));
                break;
            case 2:
                LocalDate[] DateArray = new LocalDate[4];
                System.out.println("Datas adicionadas:");

                LocalDate data1 = LocalDate.of(2020,1,8);
                DateArray[0] = data1;
                System.out.println(data1);
                LocalDate data2 = LocalDate.of(2022,2,10);
                DateArray[1] = data2;
                System.out.println(data2);
                LocalDate data3 = LocalDate.of(2021,2,10);
                DateArray[2] = data3;
                System.out.println(data3);
                LocalDate data4 = LocalDate.of(2023,2,10);
                DateArray[3] = data4;
                System.out.println(data4);

                LocalDateArray myDateArray = new LocalDateArray(DateArray);
                System.out.println("Que data deseja adicionar: Ano Mes Dia:");
                int ano = sc.nextInt();
                int mes = sc.nextInt();
                int dia = sc.nextInt();
                LocalDate newDate = LocalDate.of(ano,mes,dia);
                myDateArray.insereData(newDate);

                LocalDate dataTeste = LocalDate.of(2021,3,5);
                System.out.println("Data mais proxima a " + dataTeste.toString() + " é a data: " + myDateArray.dataMaisProxima(dataTeste).toString());

                System.out.println("Array atual: " + myDateArray.toString());
                break;
            case 3:
                int[] arr31 = makeNewArray(sc);
                intArray.ordena(arr31);
                System.out.println("Array ordenado: " + Arrays.toString(arr31));
                System.out.println("Procura binaria do elemento: ");
                int bSearch = sc.nextInt();
                System.out.println("Resultado: " + intArray.biSearch(arr31, bSearch));
                break;
            case 4:
                StringArray myArrStr = new StringArray();
                String[] arr = new String[6];
                String str1 = "O antonio";
                String str2 = "saltou";
                String str3 = "saltou";
                String str4 = "de paraquedas";
                String str5 = "de paraquedas";
                String str6 = "para o chao";
                arr[0] = str1;
                arr[1] = str2;
                arr[2] = str3;
                arr[3] = str4;
                arr[4] = str5;
                arr[5] = str6;
                System.out.println("Array inicial: " + Arrays.toString(arr));
                String[] newArr = myArrStr.removeReps(arr);
                System.out.println("Após remoção de repetidos: " + Arrays.toString(newArr));
                System.out.println("Maior String: " + myArrStr.biggestStr(arr));
                System.out.println("Array com repetidos: " + Arrays.toString(myArrStr.arrayComReps(arr)));
                System.out.println("Escreva a string a usar como input: ");
                sc.nextLine();
                String str = sc.nextLine();
                System.out.println("A string aparece " + myArrStr.howMany(arr, str) + " vezes.");
                break;
            default:
                System.out.println("O numero que colocou nao esta correto...\nTry again!!");
        }
    }
}

