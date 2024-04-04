public class Lugar {
    /*Matricula do veicculo*/
    private String matricula;
    /*nome do proprietario*/
    private String nome;
    /*Tempo atribuido ao lugar, em minutos*/
    private int minutos;
    /*Indica se o lugar é permanente*/
    private boolean permanente;

    public Lugar(){
        this.matricula = "N/a";
        this.nome = "N/a";
        this.minutos = 0;
        this.permanente = false;
    }

    public Lugar(String matricula, String nome, int minutos, boolean permanente){
        this.matricula = matricula;
        this.nome = nome;
        this.minutos = minutos;
        this.permanente = permanente;
    }

    public Lugar(Lugar parque){
        this.matricula = parque.getMatricula();
        this.nome = parque.getNome();
        this.minutos =  parque.getMinutos();
        this.permanente = parque.isPermanente();
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

    public boolean isPermanente() {
        return this.permanente;
    }

    public void setPermanente(boolean permanente) {
        this.permanente = permanente;
    }

    public Lugar clone(){
        return new Lugar(this);
    }

    @Override
    public String
    toString() {
        return "Lugar{\n" +
                "\tmatricula='" + matricula + "'\n" +
                "\tnome='" + nome + "'\n" +
                "\tminutos=" + minutos + "\n" +
                "\tpermanente=" + permanente + "\n" +
                '}';
    }
}
