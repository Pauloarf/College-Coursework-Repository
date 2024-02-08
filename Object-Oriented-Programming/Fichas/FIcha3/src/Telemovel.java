import java.util.ArrayList;
import java.util.List;

public class Telemovel {
    private final String marca;
    private final String modelo;
    private double displayX;
    private double displayY;
    private int armazenamentoSMS;
    private List<String> mensagens;
    private int armazenamentoFotos;
    private int armazenamentoApps;
    private int armazenamentoAppFotos = armazenamentoFotos + armazenamentoApps;
    private int armazenamentoUsado;
    private int numeroFotos;
    private int appsInstaladas;
    private List<String> nomeAppsInstaladas;

    public Telemovel(String marca, String modelo, int x, int y, int armazenamentoSMS, List<String> mensagens, int armazenamentoFotos, int armazenamentoApps){
        this.marca = marca;
        this.modelo = modelo;
        this.displayX = x;
        this.displayY = y;
        this.armazenamentoSMS = armazenamentoSMS;
        this.mensagens = new ArrayList<String>(mensagens.size());
        this.mensagens.addAll(mensagens);
        this.armazenamentoFotos = armazenamentoFotos;
        this.armazenamentoApps = armazenamentoApps;
        this.armazenamentoUsado = 0;
        this.numeroFotos = 0;
        this.appsInstaladas = 0;
        this.nomeAppsInstaladas = new ArrayList<String>(appsInstaladas);
    }

    public Telemovel(String marca, String modelo, int x, int y, int armazenamentoSMS, List<String> mensagens, int armazenamentoFotos, int armazenamentoApps, int armazenamentoUsado, int numeroFotos, int appsInstaladas, List<String> nomeAppsInstaladas) {
        this.marca = marca;
        this.modelo = modelo;
        this.displayX = x;
        this.displayY = y;
        this.armazenamentoSMS = armazenamentoSMS;
        this.mensagens = new ArrayList<String>(mensagens.size());
        this.mensagens.addAll(mensagens);
        this.armazenamentoFotos = armazenamentoFotos;
        this.armazenamentoApps = armazenamentoApps;
        this.armazenamentoUsado = armazenamentoUsado;
        this.numeroFotos = numeroFotos;
        this.appsInstaladas = appsInstaladas;
        this.nomeAppsInstaladas = new ArrayList<String>(nomeAppsInstaladas);
        this.nomeAppsInstaladas.addAll(nomeAppsInstaladas);
    }

    public Telemovel(Telemovel telemovel){
        this.marca = telemovel.getMarca();
        this.modelo = telemovel.getModelo();
    }

    public String getMarca() {
        return this.marca;
    }

    public String getModelo() {
        return this.modelo;
    }

    public double getDisplayX() {
        return this.displayX;
    }

    public void setDisplayX(double displayX){
        this.displayX =  displayX;
    }

    public double getDisplayY() {
        return this.displayY;
    }

    public void setDisplayY(double displayY){
        this.displayY = displayY;
    }

    public int getArmazenamentoSMS() {
        return this.armazenamentoSMS;
    }

    public void setArmazenamentoSMS(int armazenamentoSMS) {
        this.armazenamentoSMS = armazenamentoSMS;
    }

    public List<String> getMensagens() {
        return this.mensagens;
    }

    public void setMensagens(List<String> mensagens) {
        this.mensagens = new ArrayList<String>(mensagens.size());
        this.mensagens.addAll(mensagens);
    }

    public int getArmazenamentoFotos(){
        return this.armazenamentoFotos;
    }

    public void setArmazenamentoFotos(int armazenamentoFotos){
        this.armazenamentoFotos = armazenamentoFotos;
    }

    public int getArmazenamentoApps(){
        return this.armazenamentoApps;
    }

    public void setArmazenamentoApps(int armazenamentoApps) {
        this.armazenamentoApps = armazenamentoApps;
    }

    public int getArmazenamentoAppFotos(){
        return this.armazenamentoAppFotos;
    }

    public void setArmazenamentoAppFotos(int armazenamentoAppFotos) {
        this.armazenamentoAppFotos = armazenamentoAppFotos;
    }

    public int getArmazenamentoUsado(){
        return this.armazenamentoUsado;
    }

    public void setArmazenamentoUsado(int armazenamentoUsado) {
        this.armazenamentoUsado = armazenamentoUsado;
    }

    public int getNumeroFotos() {
        return this.numeroFotos;
    }

    public void setNumeroFotos(int numeroFotos) {
        this.numeroFotos = numeroFotos;
    }

    public int getAppsInstaladas() {
        return this.appsInstaladas;
    }

    public void setAppsInstaladas(int appsInstaladas) {
        this.appsInstaladas = appsInstaladas;
    }

    public List<String> getNomeAppsInstaladas() {
        return this.nomeAppsInstaladas;
    }

    public void setNomeAppsInstaladas(int appsInstaladas, List<String> nomeAppsInstaladas) {
        this.appsInstaladas = appsInstaladas;
        this.nomeAppsInstaladas = new ArrayList<String>(nomeAppsInstaladas.size());
        this.nomeAppsInstaladas.addAll(nomeAppsInstaladas);
    }

    public boolean existeEspaco(int numeroBytes){
        return false;
    }

    public void instalaApp(String nome, int tamanho){

    }

    public void recebeMsg(String msg){
    }

    public double tamMedioApps(){
        return 0;
    }

    public String maiorMsg(){
        return null;
    }

    public void removeApp(String nome, int tamanho){

    }
}


