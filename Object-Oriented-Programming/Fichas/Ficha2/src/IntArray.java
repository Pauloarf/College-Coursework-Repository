import java.util.Arrays;

public class IntArray {

    public int MinimumValue(int[] arr){
        if(arr.length < 1) return Integer.MIN_VALUE; // O que fazemos se o array for vazio? fica á escolha
        else {
            int min = arr[0];
            for (int j : arr) {
                if (min > j) min = j;
            }
            return min;
        }
    }

    public int[] arrFromAtoB(int[] arr, int a, int b){
        return Arrays.copyOfRange(arr, a, b);
    }

    public int[] elementosComuns(int[] arr1, int[] arr2){
        Arrays.sort(arr1);
        Arrays.sort(arr2);

        int newArrSize = Math.min(arr1.length, arr2.length);

        int[] newArray = new int[newArrSize];
        int index = 0;
        for(int i = 0; i < arr1.length; i++){
            for(int j = 0; j < arr2.length; j++){
                if(arr1[i] > arr2[j]) continue;
                if (arr1[i] == arr2[j]) {
                    newArray[i] = arr1[index];
                    index++;
                    break;
                }
            }
        }
        return newArray;
    }

    public void ordena(int[] arr){
        Arrays.sort(arr);
    }

    public int biSearch(int[] arr, int a){
        return Arrays.binarySearch(arr, a);
    }
}