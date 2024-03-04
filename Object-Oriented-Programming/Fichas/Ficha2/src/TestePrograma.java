import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class TestePrograma {
    //TODO Alterar esta função... caso o tamnho seja menor, mudar tamanho do array, simplifica
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
                break;
            default:
                System.out.println("O numero que colocou nao esta correto...\nTry again!!");
        }
    }
}

