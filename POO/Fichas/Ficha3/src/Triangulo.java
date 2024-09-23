import java.util.Objects;

public class Triangulo {
    private Ponto ponto1;
    private Ponto ponto2;
    private Ponto ponto3;

    public Triangulo(Ponto ponto1, Ponto ponto2, Ponto ponto3) {
        this.ponto1 = ponto1;
        this.ponto2 = ponto2;
        this.ponto3 = ponto3;
    }

    public Triangulo(Triangulo outro) {
        this.ponto1 = outro.getPonto1().clone();
        this.ponto2 = outro.getPonto2().clone();
        this.ponto3 = outro.getPonto3().clone();
    }

    public Triangulo() {
        this.ponto1 = new Ponto();
        this.ponto2 = new Ponto();
        this.ponto3 = new Ponto();
    }

    public Ponto getPonto1() {
        return this.ponto1;
    }

    public void setPonto1(Ponto ponto1) {
        this.ponto1 = ponto1;
    }

    public Ponto getPonto2() {
        return this.ponto2;
    }

    public void setPonto2(Ponto ponto2) {
        this.ponto2 = ponto2;
    }

    public Ponto getPonto3() {
        return this.ponto3;
    }

    public void setPonto3(Ponto ponto3) {
        this.ponto3 = ponto3;
    }

    //Usa a formula Area = sqrt(s*(s-a)*(s-b)*(s-c))
    //Onde s é o semiperimetro
    public double calculaAreaTriangulo() {
        double lado1 = ponto1.distancia(ponto2);
        double lado2 = ponto2.distancia(ponto3);
        double lado3 = ponto3.distancia(ponto1);

        double semiperimetro = (lado1 + lado2 + lado3) / 2;

        return Math.sqrt(semiperimetro * (semiperimetro - lado1) * (semiperimetro - lado2) * (semiperimetro - lado3));
    }

    public double calculaPerimetroTriangulo() {
        double lado1 = ponto1.distancia(ponto2);
        double lado2 = ponto2.distancia(ponto3);
        double lado3 = ponto3.distancia(ponto1);

        return lado1 + lado2 + lado3;
    }

    public double calculaAlturaTriangulo() {
        double minY = Math.min(ponto1.getY(), Math.min(ponto2.getY(), ponto3.getY()));
        double maxY = Math.max(ponto1.getY(), Math.max(ponto2.getY(), ponto3.getY()));

        return maxY - minY;
    }

    public Triangulo clone(){
        return new Triangulo(this);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Triangulo triangulo = (Triangulo) o;
        return Objects.equals(ponto1, triangulo.ponto1) && Objects.equals(ponto2, triangulo.ponto2) && Objects.equals(ponto3, triangulo.ponto3);
    }

    @Override
    public String toString() {
        return "Triangulo{" +
                "ponto1=" + ponto1 +
                ", ponto2=" + ponto2 +
                ", ponto3=" + ponto3 +
                '}';
    }
}
