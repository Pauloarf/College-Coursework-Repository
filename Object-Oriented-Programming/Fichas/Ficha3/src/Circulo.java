public class Circulo {
    private double x;
    private double y;
    private double raio;

    public Circulo(){
        this.x = 0;
        this.y = 0;
        this.raio = 0;
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

    public void setX(double x){
        this.x = x;
    }

    public double getY(){
        return this.y;
    }

    public void setY(double y) {
        this.y = y;
    }

    public double getRaio() {
        return raio;
    }

    public void setRaio(double raio) {
        this.raio = raio;
    }

    public void alteraCentro(double x, double y){
        this.setX(x);
        this.setY(y);
    }

    public double calculaArea(){
        return Math.PI * Math.pow(this.getRaio(), 2);
    }

    public double calculaPerimetro(){
        return 2 * Math.PI * this.getRaio();
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