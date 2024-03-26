import java.util.ArrayList;
import java.util.Objects;

public class Telemovel {
    private String marca;
    private String modelo;
    private int displayX;
    private int displayY;
    private int dimensaoArmazenamentoMsg;
    private int dimensaoArmazenamentoTotal;
    private int dimensaoArmazenamentoFotos;
    private int dimensaoArmazenamentoApps;
    private int espacoTotalOcupado;
    private int numFotosGuardadas;
    private int numAppsInstaladas;
    private ArrayList<String> nomesApps;
    private ArrayList<String> mensagensTexto;

    public Telemovel() {
        this.marca = "N/a";
        this.modelo = "N/a";
        this.displayX = 0;
        this.displayY = 0;
        this.dimensaoArmazenamentoMsg = 0;
        this.dimensaoArmazenamentoTotal = 0;
        this.dimensaoArmazenamentoFotos = 0;
        this.dimensaoArmazenamentoApps = 0;
        this.espacoTotalOcupado = 0;
        this.numFotosGuardadas = 0;
        this.numAppsInstaladas = 0;
        this.nomesApps = new ArrayList<>();
        this.mensagensTexto = new ArrayList<>();
    }

    public Telemovel(String marca, String modelo, int displayX, int displayY, int dimensaoArmazenamentoMsg,
                     int dimensaoArmazenamentoTotal, int dimensaoArmazenamentoFotos, int dimensaoArmazenamentoApps) {
        this.marca = marca;
        this.modelo = modelo;
        this.displayX = displayX;
        this.displayY = displayY;
        this.dimensaoArmazenamentoMsg = dimensaoArmazenamentoMsg;
        this.dimensaoArmazenamentoTotal = dimensaoArmazenamentoTotal;
        this.dimensaoArmazenamentoFotos = dimensaoArmazenamentoFotos;
        this.dimensaoArmazenamentoApps = dimensaoArmazenamentoApps;
        this.espacoTotalOcupado = 0;
        this.numFotosGuardadas = 0;
        this.numAppsInstaladas = 0;
        this.nomesApps = new ArrayList<>();
        this.mensagensTexto = new ArrayList<>();
    }

    public Telemovel(Telemovel t) {
        this.marca = t.getMarca();
        this.modelo = t.getModelo();
        this.displayX = t.getDisplayX();
        this.displayY = t.getDisplayY();
        this.dimensaoArmazenamentoMsg = t.getDimensaoArmazenamentoMsg();
        this.dimensaoArmazenamentoTotal = t.getDimensaoArmazenamentoTotal();
        this.dimensaoArmazenamentoFotos = t.getDimensaoArmazenamentoFotos();
        this.dimensaoArmazenamentoApps = t.getDimensaoArmazenamentoApps();
        this.espacoTotalOcupado = t.getEspacoTotalOcupado();
        this.numFotosGuardadas = t.getNumFotosGuardadas();
        this.numAppsInstaladas = t.getNumAppsInstaladas();
        this.nomesApps = t.getNomesApps();
        this.mensagensTexto = t.getMensagensTexto();
    }

    public String getMarca() {
        return this.marca;
    }

    public String getModelo() {
        return this.modelo;
    }

    public int getDisplayX() {
        return this.displayX;
    }

    public int getDisplayY() {
        return this.displayY;
    }

    public int getDimensaoArmazenamentoMsg() {
        return this.dimensaoArmazenamentoMsg;
    }

    public int getDimensaoArmazenamentoTotal() {
        return this.dimensaoArmazenamentoTotal;
    }

    public int getDimensaoArmazenamentoFotos() {
        return this.dimensaoArmazenamentoFotos;
    }

    public int getDimensaoArmazenamentoApps() {
        return  this.dimensaoArmazenamentoApps;
    }

    public int getEspacoTotalOcupado() {
        return this.espacoTotalOcupado;
    }

    public int getNumFotosGuardadas() {
        return this.numFotosGuardadas;
    }

    public int getNumAppsInstaladas() {
        return this.numAppsInstaladas;
    }

    public ArrayList<String> getNomesApps() {
        return new ArrayList<String>(this.nomesApps);
    }

    public ArrayList<String> getMensagensTexto() {
        return new ArrayList<String>(this.mensagensTexto);
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public void setDisplayX(int displayX) {
        this.displayX = displayX;
    }

    public void setDisplayY(int displayY) {
        this.displayY = displayY;
    }

    public void setDimensaoArmazenamentoMsg(int dimensaoArmazenamentoMsg) {
        this.dimensaoArmazenamentoMsg = dimensaoArmazenamentoMsg;
    }

    public void setDimensaoArmazenamentoTotal(int dimensaoArmazenamentoTotal) {
        this.dimensaoArmazenamentoTotal = dimensaoArmazenamentoTotal;
    }

    public void setDimensaoArmazenamentoFotos(int dimensaoArmazenamentoFotos) {
        this.dimensaoArmazenamentoFotos = dimensaoArmazenamentoFotos;
    }

    public void setDimensaoArmazenamentoApps(int dimensaoArmazenamentoApps) {
        this.dimensaoArmazenamentoApps = dimensaoArmazenamentoApps;
    }

    public void setEspacoTotalOcupado(int espacoTotalOcupado) {
        this.espacoTotalOcupado = espacoTotalOcupado;
    }

    public void setNumFotosGuardadas(int numFotosGuardadas) {
        this.numFotosGuardadas = numFotosGuardadas;
    }

    public void setNumAppsInstaladas(int numAppsInstaladas) {
        this.numAppsInstaladas = numAppsInstaladas;
    }

    public void setNomesApps(ArrayList<String> nomesApps) {
        this.nomesApps = nomesApps;
    }

    public void setMensagensTexto(ArrayList<String> mensagensTexto) {
        this.mensagensTexto = mensagensTexto;
    }

    public boolean existeEspaco(int numeroBytes) {
        return (this.espacoTotalOcupado + numeroBytes) <= this.dimensaoArmazenamentoTotal;
    }

    public void instalaApp(String nome, int tamanho) {
        if (existeEspaco(tamanho)) {
            this.nomesApps.add(nome);
            this.espacoTotalOcupado += tamanho;
            this.dimensaoArmazenamentoApps -= tamanho;
            this.numAppsInstaladas++;
        } else {
            System.out.println("Não há espaço suficiente para instalar a aplicação " + nome);
        }
    }

    public void recebeMsg(String msg) {
        if (this.mensagensTexto.size() < this.dimensaoArmazenamentoMsg) {
            this.mensagensTexto.add(msg);
        } else {
            System.out.println("A capacidade de armazenamento de mensagens está cheia.");
        }
    }

    public double tamMedioApps() {
        if (this.numAppsInstaladas == 0) {
            return 0.0;
        }
        return (double) this.espacoTotalOcupado / this.numAppsInstaladas;
    }

    public String maiorMsg() {
        if (this.mensagensTexto.isEmpty()) {
            return null;
        }
        String maior = this.mensagensTexto.get(0);
        for (String msg : this.mensagensTexto) {
            if (msg.length() > maior.length()) {
                maior = msg;
            }
        }
        return maior;
    }

    public void removeApp(String nome, int tamanho) {
        if (this.nomesApps.contains(nome)) {
            this.nomesApps.remove(nome);
            this.espacoTotalOcupado -= tamanho;
            this.dimensaoArmazenamentoApps += tamanho;
            this.numAppsInstaladas--;
        } else {
            System.out.println("A aplicação " + nome + " não está instalada.");
        }
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Telemovel telemovel = (Telemovel) o;
        return displayX == telemovel.displayX &&
                displayY == telemovel.displayY &&
                dimensaoArmazenamentoMsg == telemovel.dimensaoArmazenamentoMsg &&
                dimensaoArmazenamentoTotal == telemovel.dimensaoArmazenamentoTotal &&
                dimensaoArmazenamentoFotos == telemovel.dimensaoArmazenamentoFotos &&
                dimensaoArmazenamentoApps == telemovel.dimensaoArmazenamentoApps &&
                espacoTotalOcupado == telemovel.espacoTotalOcupado &&
                numFotosGuardadas == telemovel.numFotosGuardadas &&
                numAppsInstaladas == telemovel.numAppsInstaladas &&
                Objects.equals(marca, telemovel.marca) &&
                Objects.equals(modelo, telemovel.modelo) &&
                Objects.equals(nomesApps, telemovel.nomesApps) &&
                Objects.equals(mensagensTexto, telemovel.mensagensTexto);
    }

    @Override
    public String toString() {
        return "Telemovel{\n" +
                "\tmarca='" + marca + "'\n" +
                "\tmodelo='" + modelo + "'\n" +
                "\tdisplayX=" + displayX + "\n" +
                "\tdisplayY=" + displayY + "\n" +
                "\tdimensaoArmazenamentoMsg=" + dimensaoArmazenamentoMsg + "\n" +
                "\tdimensaoArmazenamentoTotal=" + dimensaoArmazenamentoTotal + "\n" +
                "\tdimensaoArmazenamentoFotos=" + dimensaoArmazenamentoFotos + "\n" +
                "\tdimensaoArmazenamentoApps=" + dimensaoArmazenamentoApps + "\n" +
                "\tespacoTotalOcupado=" + espacoTotalOcupado + "\n" +
                "\tnumFotosGuardadas=" + numFotosGuardadas + "\n" +
                "\tnumAppsInstaladas=" + numAppsInstaladas + "\n" +
                "\tnomesApps=" + nomesApps + "\n" +
                "\tmensagensTexto=" + mensagensTexto + "\n" +
                '}';
    }

    public Telemovel clone(){
        return new Telemovel(this);
    }
}
