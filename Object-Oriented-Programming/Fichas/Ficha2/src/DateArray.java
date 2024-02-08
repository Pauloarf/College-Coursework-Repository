import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.temporal.ChronoUnit;
import java.util.Arrays;

public class DateArray {

    public int array_size = 8;
    public LocalDate[] arr = new LocalDate[array_size];
    private int size = 0;

    public LocalDate[] makeArrBigger(LocalDate[] arr){
        return Arrays.copyOf(arr, arr.length+10);
    }

    public void insertData(LocalDate data) {
        if(size == array_size) arr = makeArrBigger(arr);
        arr[size] = data;
        size++;
    }

    public LocalDate closestDate(LocalDate data){
        LocalDate firstClosest = arr[0];
        long closestDifference = ChronoUnit.SECONDS.between(data ,firstClosest);

        for (LocalDate d : arr) {
            long difference = Math.abs(ChronoUnit.DAYS.between(data, d));
            if (difference < closestDifference) {
                closestDifference = difference;
                firstClosest = d;
            }
        }
        return firstClosest;
    }

}
