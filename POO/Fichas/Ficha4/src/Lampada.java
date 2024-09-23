import java.util.Objects;

public class Lampada
{
    public enum State {
        ON,
        OFF,
        ECO
    }

    private State state;

    private double cpSOn;
    private double cpSEco;
    private double consumoTotal;
    private double consumoPeriodo;
    private long stamp;

    public Lampada() {
        this.state = State.OFF;
        this.cpSEco = 1;
        this.cpSOn = 2;
        this.consumoTotal = 0;
        this.consumoPeriodo = 0;
        this.stamp = System.currentTimeMillis();
    }

    public Lampada(Lampada l){
        this.state = l.getModo();
        this.cpSEco = l.getCpSEco();
        this.cpSOn = l.getCpSOn();
        this.consumoTotal = l.totalConsumo();
        this.consumoPeriodo = l.periodoConsumo();
        this.stamp = l.getStamp();
    }

    public Lampada(State x, double cpsE, double cpsO, double cT, double pC) {
        this.cpSEco = cpsE;
        this.cpSOn = cpsO;
        this.state = x;
        this.consumoTotal = cT;
        this.consumoPeriodo = pC;
        this.stamp = System.currentTimeMillis();
    }

    public State getModo() {
        return state;
    }

    public void setModo(State m) {
        this.state = m;
    }

    public long getStamp() {
        return stamp;
    }

    public double getCpSEco(){
        return this.cpSEco;
    }

    public void setCpSEco(double x){
        this.cpSEco = x;
    }

    public double getCpSOn(){
        return this.cpSOn;
    }

    public void setCpSOn(double x){
        this.cpSOn = x;
    }

    public double getConsumoTotal() {
        return consumoTotal;
    }

    public void setConsumoTotal(double cT){
        this.consumoTotal = cT;
    }

    public double getConsumoPeriodo() {
        return consumoPeriodo;
    }

    public void setConsumoPeriodo(double pC){
        this.consumoPeriodo = pC;
    }

    public void lampON() {
        this.atualizaConsumo();
        this.state = State.ON;
    }

    public void lampOFF() {
        this.atualizaConsumo();
        this.state = State.OFF;
    }

    public void lampECO() {
        this.atualizaConsumo();
        this.state = State.ECO;
    }

    public void resetPeriodo(){
        atualizaConsumo();
        this.consumoPeriodo = 0;
    }

    public double periodoConsumo(){
        atualizaConsumo();
        return consumoPeriodo;
    }
    public double totalConsumo() {
        atualizaConsumo();
        return consumoTotal;
    }

    private void atualizaConsumo() {
        long periodo = System.currentTimeMillis() - stamp;

        if(this.state == State.ON) {
            this.consumoTotal += cpSOn *periodo;
            this.consumoPeriodo += cpSOn *periodo;
        } else if(this.state == State.ECO) {
            this.consumoTotal += cpSEco *periodo;
            this.consumoPeriodo += cpSEco *periodo;
        }

        this.stamp = System.currentTimeMillis();
    }

    public Lampada clone(){
        return new Lampada(this);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Lampada: ").append(this.state)
                .append("\nConsumo por segundo Eco: ").append(this.cpSEco)
                .append("\nConsumo por segundo On: ").append(this.cpSOn)
                .append("\nConsumoTotal: ").append(this.consumoTotal)
                .append("\nInicio de ultimo consumo: ").append(this.consumoPeriodo);
        return sb.toString();
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Lampada lampada = (Lampada) o;
        return Double.compare(cpSOn, lampada.cpSOn) == 0 && Double.compare(cpSEco, lampada.cpSEco) == 0 && Double.compare(consumoTotal, lampada.consumoTotal) == 0 && Double.compare(consumoPeriodo, lampada.consumoPeriodo) == 0 && stamp == lampada.stamp && state == lampada.state;
    }
}