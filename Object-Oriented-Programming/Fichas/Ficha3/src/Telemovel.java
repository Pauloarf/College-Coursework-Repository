import java.util.Arrays;

public class Telemovel {
    private String marca;
    private String modelo;
    private final int[] display = new int[2];
    private int smsStorage;
    private int photoStorage;
    private int appStorage;
    private int totalStorage;
    private int nPhotos;
    private int nApps;
    private String[] appNames;

    public Telemovel(){
        this.marca = "N/a";
        this.modelo = "N/a";
        //display is already 0
        this.smsStorage = 0;
        this.photoStorage = 0;
        this.appStorage = 0;
        this.totalStorage = 0;
        this.nPhotos = 0;
        this.nApps = 0;
        this.appNames = new String[0];
    }

    public Telemovel(
            String marca,
            String modelo,
            int displayX,
            int displayY,
            int smsStorage,
            int photoStorage,
            int appStorage,
            int totalStorage,
            int nPhotos,
            int nApps,
            String[] appNames) {

        this.marca = marca;
        this.modelo = modelo;
        this.display[0] = displayX;
        this.display[1] = displayY;
        this.smsStorage = smsStorage;
        this.photoStorage = photoStorage;
        this.appStorage = appStorage;
        this.totalStorage = totalStorage;
        this.nPhotos = nPhotos;
        this.nApps = nApps;
        this.appNames = appNames;
    }

    public Telemovel(Telemovel tele){
        this.marca = tele.getMarca();
        this.modelo = tele.getModelo();
        this.display[0] = tele.getDisplayX();
        this.display[1] = tele.getDisplayY();
        this.smsStorage = tele.getSmsStorage();
        this.photoStorage = tele.getPhotoStorage();
        this.appStorage = tele.getAppStorage();
        this.totalStorage = tele.getTotalStorage();
        this.nPhotos = tele.getnPhotos();
        this.nApps = tele.getnApps();
        this.appNames = tele.getAppNames();
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

    public void setModelo(String modelo){
        this.modelo = modelo;
    }

    public int getDisplayX(){
        return this.display[0];
    }

    public void setDisplayX(int x){
        this.display[0] = x;
    }

    public int getDisplayY(){
        return this.display[1];
    }

    public void setDisplayY(int y){
        this.display[1] = y;
    }

    public int getSmsStorage(){
        return this.smsStorage;
    }

    public void setSmsStorage(int smsStorage){
        this.smsStorage = smsStorage;
    }

    public int getPhotoStorage(){
        return this.photoStorage;
    }

    public void setPhotoStorage(int photoStorage){
        this.photoStorage = photoStorage;
    }

    public int getAppStorage(){
        return  this.appStorage;
    }

    public void setAppStorage(int appStorage) {
        this.appStorage = appStorage;
    }

    public int getTotalStorage(){
        return this.totalStorage;
    }

    public void setTotalStorage(int totalStorage) {
        this.totalStorage = totalStorage;
    }

    public int getnPhotos(){
        return this.nPhotos;
    }

    public void setnPhotos(int nPhotos){
        this.nPhotos = nPhotos;
    }

    public int getnApps() {
        return this.nApps;
    }

    public void setnApps(int nApps) {
        this.nApps = nApps;
    }

    public String[] getAppNames() {
        return this.appNames;
    }

    public void setAppNames(String[] appNames){
        this.appNames = appNames;
    }

    public String toString(){
        return ("Telemovel {\n" +
                "\tMarca - " + this.marca + "\n" +
                "\tModelo - " + this.modelo + "\n" +
                "\tDisplay - " + "[" + this.getDisplayX() + "x" + this.getDisplayY() + "]" + "\n" +
                "\tStorage(sms) - " + this.smsStorage + "\n" +
                "\tStorage(Photo) - " + this.photoStorage + "\n" +
                "\tStorage(Apps) - " + this.appStorage + "\n" +
                "\tStorage(Total) - " + this.totalStorage + "\n" +
                "\tnPhotos - " + this.nPhotos + "\n" +
                "\tnApps - " + this.nApps + "\n" +
                "\tApp Names - " + Arrays.toString(this.appNames) + "\n"
                );
    }
}
