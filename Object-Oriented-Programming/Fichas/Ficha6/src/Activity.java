import java.nio.channels.AcceptPendingException;
import java.time.LocalDate;
import java.util.Objects;

public abstract class Activity {
    private int id;
    private String description;
    private LocalDate completionDate;
    private int time;

    public Activity(){
        this.id = 0;
        this.description = "";
        this.completionDate = LocalDate.now();
        this.time = 0;
    }

    public Activity(int id, String description, LocalDate completionDate, int time){
        this.id = id;
        this.description = description;
        this.completionDate = completionDate;
        this.time = time;
    }

    public Activity(Activity a){
        this.id = a.getId();
        this.description = a.getDescription();
        this.completionDate = a.getCompletionDate();
        this.time = a.getTime();
    }

    public int getId() {
        return this.id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getDescription(){
        return this.description;
    }

    public void setDescription(String description){
        this.description = description;
    }

    public LocalDate getCompletionDate() {
        return this.completionDate;
    }

    public void setCompletionDate(LocalDate completionDate) {
        this.completionDate = completionDate;
    }

    public int getTime() {
        return this.time;
    }

    public void setTime(int time){
        this.time = time;
    }

    @Override
    public String toString() {
        return "Activity{" +
                "id=" + id +
                ", description='" + description + '\'' +
                ", completionDate=" + completionDate +
                ", time=" + time +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;

        if (o == null || getClass() != o.getClass()) return false;

        Activity activity = (Activity) o;
        return id == activity.id &&
               time == activity.time &&
               Objects.equals(description, activity.description) &&
               Objects.equals(completionDate, activity.completionDate);
    }

    @Override
    public int hashCode() {
        return Objects.hash(id, description, completionDate, time);
    }

    public abstract Activity clone();

    public abstract double caloricValue(double weight, int age);

}
