import java.util.Arrays;

public class IntegerArray {

    public int array_size = 8;
    public int [] arr = new int[array_size];

    public int minimumValue(){
        int min = arr[0];

        for (int i : arr) {
            if (min > i) min = i;
        }

        return min;
    }

    public int[] arrayBetween(int index1, int index2){
        return Arrays.copyOfRange(arr, index1, index2 + 1);
    }
    
    public int [] arrayReunion(int [] arr1, int [] arr2){
        int size = Math.min(arr1.length, arr2.length);
        int [] combinedArray = new int[size];
        int index = 0;

        for (int j : arr1) {
            for (int value : arr2) {
                if (j == value) {
                    boolean found = false;
                    for (int k = 0; k < index; k++) {
                        if (j == combinedArray[k]) {
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        combinedArray[index] = j;
                        index++;
                    }
                }
            }
        }
        return Arrays.copyOfRange(combinedArray, 0, index);
    }
}
