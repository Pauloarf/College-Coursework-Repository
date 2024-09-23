import java.util.Arrays;

public class StringArray {

    public String[] removeReps(String[] arr){
        String[] newArr = Arrays.copyOf(arr, arr.length);
        int myIndex = 0;
        boolean inside = false;
        newArr[myIndex] = arr[0];
        for(int i = 1; i < arr.length; i++){
            inside = false;
            for(int j = 0; j < i; j++){
                if (arr[i].equals(arr[j])) {
                    inside = true;
                    break;
                }
            }
            if(!inside){
                newArr[++myIndex] = arr[i];
            }
        }
        return Arrays.copyOfRange(newArr, 0, myIndex+1);
    }

    public String biggestStr(String[] arr){
        int tamanho = arr[0].length();
        String biggest = arr[0];
        for(String i : arr){
            if(tamanho < i.length()){
                tamanho = i.length();
                biggest = i;
            }
        }
        return biggest;
    }

    public String[] arrayComReps(String[] arr){
        String[] newArr = Arrays.copyOf(arr, arr.length);
        int myIndex = 0;
        boolean inside;
        for(int i = 0; i < arr.length; i++){
            inside = false;
            for(int j = 0; j < i; j++){
                if (arr[i].equals(arr[j])) {
                    inside = true;
                    break;
                }
            }
            if(inside){
                newArr[myIndex++] = arr[i];
            }
        }
        return Arrays.copyOfRange(newArr, 0, myIndex+1);
    }

    public int howMany(String[] arr, String str){
        int res = 0;
        for(String i : arr){
            if(i.equals(str)) res++;
        }
        return res;
    }
}
