public class IntArray {

    public int[] array;

    public IntArray(int[] arr){
        this.array = arr; //Passar o apontador para o array ou o seu clone
    }

    public int MinimumValue(int[] arr){
        if(arr.length < 1) return Integer.MIN_VALUE; // O que fazemos se o array for vazio
        else {
            int min = arr[0];
            for (int i : arr) {
                if (min > i) min = i;
            }
            return min;
        }
    }
}