public class Parque {
    private String matricula;
    private String nome;
    private int minutos;
    private boolean permanente;

    public Parque(){
        this.matricula = "N/a";
        this.nome = "N/a";
        this.minutos = 0;
        this.permanente = false;
    }

    public Parque(String matricula, String nome, int minutos, boolean permanente){
        this.matricula = matricula;
        this.nome = nome;
        this.minutos = minutos;
        this.permanente = permanente;
    }

    public Parque(Parque parque){
        this.matricula = parque.getMatricula();
        this.nome = parque.getNome();
        this.minutos =  parque.getMinutos();
        this.permanente = parque.getPermanente();
    }

    public String getMatricula() {
        return this.matricula;
    }

    public void setMatricula(String matricula) {
        this.matricula = matricula;
    }

    public String getNome() {
        return this.nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getMinutos(){
        return this.minutos;
    }

    public void setMinutos(int minutos) {
        this.minutos = minutos;
    }

    public boolean getPermanente() {
        return this.permanente;
    }

    public void setPermanente(boolean permanente) {
        this.permanente = permanente;
    }

    public Parque clone(){
        return new Parque(this);
    }
}
