import java.util.Arrays;

public class IntArray {

    public int n_elements;
    public int[] array;

    public IntArray(int n_elements, int[] arr){
        this.array = arr; //Passar o apontador para o array ou o seu clone
        this.n_elements = n_elements;
    }

    public int MinimumValue(){
        if(this.array.length < 1) return Integer.MIN_VALUE; // O que fazemos se o array for vazio
        else {
            int min = this.array[0];
            for (int i = 0; i < n_elements; i++) {
                if (min > this.array[i]) min = this.array[i];
            }
            return min;
        }
    }

    public int[] arrFromAtoB(int a, int b){
        return Arrays.copyOfRange(this.array, a, b);
    }

    public int[] elementosComuns(int[] arr, int arr_size){
        Arrays.sort(arr, 0, arr_size);
        Arrays.sort(this.array, 0, this.n_elements);

        int newArrSize = Math.min(arr_size, this.n_elements);

        int[] newArray = new int[newArrSize];
        int index = 0;
        for(int i = 0; i < n_elements; i++){
            for(int j = 0; j < arr_size; j++){
                if(this.array[i] > arr[j]) continue;
                if (this.array[i] == arr[j]) {
                    newArray[i] = this.array[index];
                    index++;
                    break;
                }
            }
        }
        return newArray;
    }
}