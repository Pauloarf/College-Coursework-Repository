import java.util.Objects;

public class Carro {
    private String marca;
    private String modelo;
    private int anoConstrucao;
    private double consumo100Kmh;
    private double kmsTotais;
    private double mediaConsumoTotal;
    private double kmsUltimaViagem;
    private double mediaConsumoUltimaViagem;
    private double capacidadeRegeneracao;
    private boolean ligado;

    public Carro() {
        this.marca = "N/a";
        this.modelo = "N/a";
        this.anoConstrucao = 0;
        this.consumo100Kmh = 0;
        this.kmsTotais = 0;
        this.mediaConsumoTotal = 0;
        this.kmsUltimaViagem = 0;
        this.mediaConsumoUltimaViagem = 0;
        this.capacidadeRegeneracao = 0;
        this.ligado = false;
    }

    public Carro(String marca, String modelo, int anoConstrucao, double consumo100Kmh, double capacidadeRegeneracao) {
        this.marca = marca;
        this.modelo = modelo;
        this.anoConstrucao = anoConstrucao;
        this.consumo100Kmh = consumo100Kmh;
        this.kmsTotais = 0;
        this.mediaConsumoTotal = 0;
        this.kmsUltimaViagem = 0;
        this.mediaConsumoUltimaViagem = 0;
        this.capacidadeRegeneracao = capacidadeRegeneracao;
        this.ligado = false;
    }

    public Carro(Carro c) {
        this.marca = c.getMarca();
        this.modelo = c.getModelo();
        this.anoConstrucao = c.getAnoConstrucao();
        this.consumo100Kmh = c.getConsumo100Kmh();
        this.kmsTotais = c.getKmsTotais();
        this.mediaConsumoTotal = c.getMediaConsumoTotal();
        this.kmsUltimaViagem = c.getKmsUltimaViagem();
        this.mediaConsumoUltimaViagem = c.getMediaConsumoUltimaViagem();
        this.capacidadeRegeneracao = c.getCapacidadeRegeneracao();
        this.ligado = c.isLigado();
    }

    public String getMarca() {
        return this.marca;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public String getModelo() {
        return this.modelo;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public int getAnoConstrucao() {
        return this.anoConstrucao;
    }

    public void setAnoConstrucao(int anoConstrucao) {
        this.anoConstrucao = anoConstrucao;
    }

    public double getConsumo100Kmh() {
        return this.consumo100Kmh;
    }

    public void setConsumo100Kmh(double consumo100Kmh) {
        this.consumo100Kmh = consumo100Kmh;
    }

    public double getKmsTotais() {
        return this.kmsTotais;
    }

    public void setKmsTotais(double kmsTotais) {
        this.kmsTotais = kmsTotais;
    }

    public double getMediaConsumoTotal() {
        return this.mediaConsumoTotal;
    }

    public void setMediaConsumoTotal(double mediaConsumoTotal) {
        this.mediaConsumoTotal = mediaConsumoTotal;
    }

    public double getKmsUltimaViagem() {
        return this.kmsUltimaViagem;
    }

    public void setKmsUltimaViagem(double kmsUltimaViagem) {
        this.kmsUltimaViagem = kmsUltimaViagem;
    }

    public double getMediaConsumoUltimaViagem() {
        return this.mediaConsumoUltimaViagem;
    }

    public void setMediaConsumoUltimaViagem(double mediaConsumoUltimaViagem) {
        this.mediaConsumoUltimaViagem = mediaConsumoUltimaViagem;
    }

    public double getCapacidadeRegeneracao() {
        return this.capacidadeRegeneracao;
    }

    public void setCapacidadeRegeneracao(double capacidadeRegeneracao) {
        this.capacidadeRegeneracao = capacidadeRegeneracao;
    }

    public boolean isLigado() {
        return this.ligado;
    }

    public void ligaCarro() {
        ligado = true;
        resetUltimaViagem();
    }

    public void desligaCarro() {
        ligado = false;
    }

    public void resetUltimaViagem() {
        kmsUltimaViagem = 0;
        mediaConsumoUltimaViagem = 0;
    }

    public void avancaCarro(double metros, double velocidade) {
        if (!ligado) {
            System.out.println("O carro precisa ser ligado para avançar.");
            return;
        }
        double horas = metros / (velocidade / 3.6); // Convertendo velocidade de km/h para m/s
        double consumo = consumo100Kmh * (velocidade / 100.0);
        kmsUltimaViagem += metros / 1000.0; // Convertendo metros para quilômetros
        mediaConsumoUltimaViagem = (mediaConsumoUltimaViagem * (kmsUltimaViagem - (metros / 1000.0)) + consumo) / kmsUltimaViagem;
        kmsTotais += metros / 1000.0; // Convertendo metros para quilômetros
        mediaConsumoTotal = (mediaConsumoTotal * (kmsTotais - (metros / 1000.0)) + consumo) / kmsTotais;
    }

    public void travaCarro(double metros) {
        if (!ligado) {
            System.out.println("O carro precisa ser ligado para travar.");
            return;
        }
        double consumo = this.capacidadeRegeneracao * (metros / 1000.0); // Converter metros para Km
        this.kmsUltimaViagem += metros / 1000.0; // Converter metros para Km
        this.mediaConsumoUltimaViagem = (this.mediaConsumoUltimaViagem * (this.kmsUltimaViagem - (metros / 1000.0)) - consumo) / this.kmsUltimaViagem;
        this.kmsTotais += metros / 1000.0; // Converter metros para Km
        this.mediaConsumoTotal = (this.mediaConsumoTotal * (this.kmsTotais - (metros / 1000.0)) - consumo) / this.kmsTotais;
    }
    public Carro clone(){
        return new Carro(this);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Carro carro = (Carro) o;
        return anoConstrucao == carro.anoConstrucao &&
                Double.compare(consumo100Kmh, carro.consumo100Kmh) == 0 &&
                Double.compare(kmsTotais, carro.kmsTotais) == 0 &&
                Double.compare(mediaConsumoTotal, carro.mediaConsumoTotal) == 0 &&
                Double.compare(kmsUltimaViagem, carro.kmsUltimaViagem) == 0 &&
                Double.compare(mediaConsumoUltimaViagem, carro.mediaConsumoUltimaViagem) == 0 &&
                Double.compare(capacidadeRegeneracao, carro.capacidadeRegeneracao) == 0 &&
                ligado == carro.ligado &&
                Objects.equals(marca, carro.marca) &&
                Objects.equals(modelo, carro.modelo);
    }

    @Override
    public String toString() {
        return "Carro{" +
                "marca='" + marca + '\'' +
                ", modelo='" + modelo + '\'' +
                ", anoConstrucao=" + anoConstrucao +
                ", consumo100Kmh=" + consumo100Kmh +
                ", kmsTotais=" + kmsTotais +
                ", mediaConsumoTotal=" + mediaConsumoTotal +
                ", kmsUltimaViagem=" + kmsUltimaViagem +
                ", mediaConsumoUltimaViagem=" + mediaConsumoUltimaViagem +
                ", capacidadeRegeneracao=" + capacidadeRegeneracao +
                ", ligado=" + ligado +
                '}';
    }
}
