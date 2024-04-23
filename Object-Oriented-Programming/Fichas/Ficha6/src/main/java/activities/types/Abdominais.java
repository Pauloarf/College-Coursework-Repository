package activities.types;

import activities.Atividade;

public class Abdominais extends Atividade {

    private int numero;
    private int reps;

    public Abdominais(){
        super();
        this.numero = 0;
        this.reps = 0;
    }

    public Abdominais(int numero, int reps){
        this.numero = numero;
        this.reps = reps;
    }

    @Override
    public double calorias() {
        return 0;
    }

    @Override
    public Atividade clone() {
        return null;
    }
}
