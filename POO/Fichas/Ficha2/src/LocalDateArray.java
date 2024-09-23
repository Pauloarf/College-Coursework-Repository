import java.time.LocalDate;
import java.time.temporal.ChronoUnit;
import java.util.Arrays;
import java.time.Period;

public class LocalDateArray {

    public LocalDate[] array;

    public LocalDateArray(LocalDate[] array){
        this.array = Arrays.copyOf(array, array.length);
    }

    public void insereData(LocalDate data){
        int index = this.array.length;
        this.array = Arrays.copyOf(this.array, this.array.length + 1);
        this.array[index] = data;
    }

    public LocalDate dataMaisProxima(LocalDate date) {
        LocalDate dataMaisProx = this.array[0];

        for (LocalDate dateArray : this.array) {
            long daysDifference = ChronoUnit.DAYS.between(dateArray, date);
            long currentDaysDifference = ChronoUnit.DAYS.between(dataMaisProx, date);

            if (Math.abs(daysDifference) < Math.abs(currentDaysDifference)) {
                dataMaisProx = dateArray;
            }
        }

        return dataMaisProx;
    }

    @Override
    public String toString() {
        return "LocalDateArray{" +
                Arrays.toString(array) +
                '}';
    }
}
