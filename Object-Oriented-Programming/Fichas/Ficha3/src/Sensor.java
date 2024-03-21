/*Completo*/

public class Sensor {
    private double pressao;

    public Sensor(){
        this.pressao = 0;
    }

    public Sensor(double valor){
        if(valor >= 0){
            this.pressao = valor;
        }
        else {
            this.pressao = 0;
        }
    }

    public double getPressao(){
        return this.pressao;
    }

    public boolean setPressao(double pressao){
        if(pressao >= 0){
            this.pressao = pressao;
        }
        return pressao >= 0;
    }

    @Override
    public String toString() {
        return "Sensor{" +
                "pressao=" + pressao +
                '}';
    }
}
