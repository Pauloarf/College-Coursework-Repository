import java.time.LocalDate;

public class Situps extends Activity {
    private String type;
    private int numReps;

    public Situps(){
        super();
        this.type = "";
        this.numReps = 0;
    }

    public Situps(int id, String description, LocalDate completionDate, int time, String type, int numReps){
        super(id, description, completionDate, time);
        this.type = type;
        this.numReps = numReps;
    }

    public Situps(Situps s){
        super(s);
        this.type = s.getType();
        this.numReps = s.getNumReps();
    }

    public String getType() {
        return this.type;
    }

    public void setType(String Type){
        this.type = type;
    }

    public int getNumReps() {
        return this.numReps;
    }

    public void setNumReps(int numReps) {
        this.numReps = numReps;
    }

    @Override
    public String toString() {
        return  super.toString() +
                "Situps{" +
                "type='" + type + '\'' +
                ", numReps=" + numReps +
                '}';
    }

    @Override
    public Situps clone(){
        return new Situps(this);
    }

    @Override
    public double caloricValue(double weight, int age) {
        return super.getTime() * numReps * (3.0/5.0);
    }
}
