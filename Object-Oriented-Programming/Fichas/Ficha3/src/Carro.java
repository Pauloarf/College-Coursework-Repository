public class Carro {
    private String marca;
    private String modelo;
    private int ano;
    private double consumo; //consumo por km, a uma velocidade de 100km/h
    private double kmRealizados;
    private double mediaConsumo;
    private double lastKmRealizados;
    private double lastMediaConsumo;
    private int regeneration;

    public Carro(){
        this.marca = "N/a";
        this.modelo = "N/a";
        this.ano = 0;
        this.consumo = 0;
        this.kmRealizados = 0;
        this.mediaConsumo = 0;
        this.lastKmRealizados = 0;
        this.lastMediaConsumo = 0;
        this.regeneration = 0;
    }

    public Carro(String marca,
                 String modelo,
                 int ano,
                 int consumo,
                 int kmRealizados,
                 int mediaConsumo,
                 double lastKmRealizados,
                 int lastMediaConsumo,
                 int regeneration){
        this.marca = marca;
        this.modelo = modelo;
        this.ano = ano;
        this.consumo = consumo;
        this.kmRealizados = kmRealizados;
        this.mediaConsumo = mediaConsumo;
        this.lastKmRealizados = lastKmRealizados;
        this.lastMediaConsumo = lastMediaConsumo;
        this.regeneration = regeneration;
    }

    public Carro(Carro carro){
        this.marca = carro.getMarca();
        this.modelo = carro.getModelo();
        this.ano = carro.getAno();
        this.consumo = carro.getConsumo();
        this.kmRealizados = carro.getKmRealizados();
        this.mediaConsumo = carro.getMediaConsumo();
        this.lastKmRealizados = carro.getLastKmRealizados();
        this.lastMediaConsumo = carro.getLastMediaConsumo();
        this.regeneration = carro.getRegeneration();
    }

    public String getMarca(){
        return this.marca;
    }

    public void setMarca(String marca){
        this.marca = marca;
    }

    public String getModelo(){
        return this.modelo;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public int getAno(){
        return this.ano;
    }

    public void setAno(int ano) {
        this.ano = ano;
    }

    public double getConsumo(){
        return this.consumo;
    }

    public void setConsumo(double consumo) {
        this.consumo = consumo;
    }

    public double getKmRealizados(){
        return this.kmRealizados;
    }

    public void setKmRealizados(double kmRealizados) {
        this.kmRealizados = kmRealizados;
    }

    public double getMediaConsumo(){
        return this.mediaConsumo;
    }

    public void setMediaConsumo(double mediaConsumo) {
        this.mediaConsumo = mediaConsumo;
    }

    public double getLastKmRealizados(){
        return this.lastKmRealizados;
    }

    public void setLastKmRealizados(double lastKmRealizados) {
        this.lastKmRealizados = lastKmRealizados;
    }

    public double getLastMediaConsumo(){
        return this.lastMediaConsumo;
    }

    public void setLastMediaConsumo(double lastMediaConsumo) {
        this.lastMediaConsumo = lastMediaConsumo;
    }

    public int getRegeneration(){
        return this.regeneration;
    }

    public void setRegeneration(int regeneration) {
        this.regeneration = regeneration;
    }

    public void ligaCarro(){
        this.setLastKmRealizados(0);
        this.setLastMediaConsumo(0);
    }

    public void desligaCarro(){
        this.setKmRealizados(this.getKmRealizados() + this.getLastKmRealizados());
        this.setMediaConsumo((this.getMediaConsumo() + this.getLastMediaConsumo())/2);
    }

    public void resetUltimaViagem(){
        this.setKmRealizados(this.getKmRealizados() + this.getLastKmRealizados());
        this.setMediaConsumo((this.getMediaConsumo() + this.getLastMediaConsumo())/2);
        this.setLastKmRealizados(0);
        this.setLastMediaConsumo(0);
    }

    public void avancaCarro(double metros, double velocidade){
        double consumoAtual = ((metros*0.001*velocidade)*(this.getConsumo())/100);
        double kmAtual = this.getLastKmRealizados();
        this.setLastKmRealizados(kmAtual + metros*0.001);
        this.setLastMediaConsumo((consumoAtual + this.getLastMediaConsumo())/2);
    }

    public void travaCarro(double metros){
        double regen = (metros*0.001*this.getRegeneration());
        this.setLastMediaConsumo(this.getLastMediaConsumo() - regen);
    }

    public boolean equals(Object o){
        if(this == o) return true;
        if(o == null || this.getClass() != o.getClass()) return false;
        Carro carro = (Carro) o;
        return this.getMarca().equals(carro.getMarca()) &&
                this.getModelo().equals(carro.getModelo()) &&
                this.getAno() == carro.getAno() &&
                this.getConsumo() == carro.getConsumo() &&
                this.getKmRealizados() == carro.getKmRealizados() &&
                this.getMediaConsumo() == carro.getMediaConsumo() &&
                this.getLastKmRealizados() == carro.getLastKmRealizados() &&
                this.getLastMediaConsumo() == carro.getLastMediaConsumo() &&
                this.getRegeneration() == carro.getRegeneration();
    }

    public Carro clone(){
        return new Carro(this);
    }

    @Override
    public String toString() {
        return "Carro{\n" +
                "\tmarca='" + marca + "' \n" +
                "\tmodelo='" + modelo + "' \n" +
                "\tano=" + ano + '\n' +
                "\tconsumo=" + consumo + '\n' +
                "\tkmRealizados=" + kmRealizados + '\n' +
                "\tmediaConsumo=" + mediaConsumo + '\n' +
                "\tlastKmRealizados=" + lastKmRealizados + '\n' +
                "\tlastMediaConsumo=" + lastMediaConsumo + '\n' +
                "\tregeneration=" + regeneration + '\n' +
                '}';
    }
}
