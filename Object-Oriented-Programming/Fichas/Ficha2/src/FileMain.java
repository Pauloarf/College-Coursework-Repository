import java.time.LocalDate;
import java.util.Arrays;
import java.util.Scanner;

public class FileMain {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.println("Choose the exercise you want to run from 1-7:");
        int exercise = input.nextInt();
        switch (exercise) {
            case 1:
                IntegerArray integerArray = new IntegerArray();

                System.out.println("Array has size 8 by default:");
                System.out.println("Input the values for the Array:");

                for (int i = 0; i < integerArray.arr.length; i++) {
                    integerArray.arr[i] = input.nextInt();
                }

                System.out.println("The array you made is: ");
                System.out.println(Arrays.toString(integerArray.arr));

                System.out.println("The minimum value inserted on the array is: " + integerArray.minimumValue());

                System.out.println("The Array between 2 and 5(index) is: " + Arrays.toString(integerArray.arrayBetween(2, 5)));

                int[] tempArr1 = new int[integerArray.array_size]; // Using a default size just to test (you can use Scanner to set the size)
                int[] tempArr2 = new int[integerArray.array_size];

                System.out.println("Input the values for the Array1:");
                for (int i = 0; i < tempArr1.length; i++) {
                    tempArr1[i] = input.nextInt();
                }
                System.out.println("Input the values for the Array1:");
                for (int i = 0; i < tempArr2.length; i++) {
                    tempArr2[i] = input.nextInt();
                }

                System.out.println("The common elements in the arrays arte: " + Arrays.toString(integerArray.arrayReunion(tempArr1, tempArr2)));
                break;
            case 2:
                DateArray dateArr = new DateArray();

                dateArr.insertData(LocalDate.now());
                System.out.println(Arrays.toString(dateArr.arr));
                for (int i = 0; i < 10; i++) {
                    dateArr.insertData(LocalDate.now());
                }
                System.out.println(Arrays.toString(dateArr.arr));

                break;
            case default:
                System.out.println("Not an exercise number...");
                break;
        }
    }
}