import java.util.Objects;

public class Circulo {
    private double x;
    private double y;
    private double raio;

    public Circulo(){
        this.x = 0;
        this.y = 0;
        this.raio = 1;
    }

    public Circulo(double x, double y, double raio){
        this.x = x;
        this.y = y;
        this.raio = raio;
    }

    public Circulo(Circulo circulo){
        this.x = circulo.getX();
        this.y = circulo.getY();
        this.raio = circulo.getRaio();
    }

    public double getX(){
        return this.x;
    }

    public double getY(){
        return  this.y;
    }

    public double getRaio() {
        return this.raio;
    }

    public void setX(double x){
        this.x = x;
    }

    public void setY(double y) {
        this.y = y;
    }

    public void setRaio(double raio) {
        this.raio = raio;
    }

    public void alteraCentro(double x, double y){
        setX(x);
        setY(y);
    }

    public double calculaArea(){
        return Math.PI * Math.pow(this.raio,2);
    }

    public double calculaPerimetro(){
        return Math.PI * 2 * this.raio;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Circulo circulo = (Circulo) o;
        return Double.compare(circulo.x, x) == 0 && Double.compare(circulo.y, y) == 0 && Double.compare(circulo.raio, raio) == 0;
    }

    @Override
    public int hashCode() {
        return Objects.hash(x, y, raio);
    }

    @Override
    public String toString() {
        return "Circulo{" +
                "x=" + x +
                ", y=" + y +
                ", raio=" + raio +
                '}';
    }
}
