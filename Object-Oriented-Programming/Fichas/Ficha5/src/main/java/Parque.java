import java.util.*;

public class Parque {
    private String nome;
    //private List<Lugar> listaLugares;
    private Map<String,Lugar> listaLugaresOcupados;

    public Parque(){
        this.nome = "N/a";
        //this.listaLugares = new ArrayList<Lugar>();
        this.listaLugaresOcupados = new HashMap<String,Lugar>();
    }

    public Parque(String nome){
        this.nome = nome;
        //this.listaLugares = new ArrayList<Lugar>();
        this.listaLugaresOcupados = new HashMap<String,Lugar>();
    }

    public Parque(Parque p){
        this.nome = p.getNome();
        //this.listaLugares = p.getListaLugares();
        this.listaLugaresOcupados = p.getListaLugaresOcupados();
    }

    public String getNome() {
        return this.nome;
    }

    //public List<Lugar> getListaLugares(){
    //    return new ArrayList<>(this.listaLugares);
    //}

    public Map<String,Lugar> getListaLugaresOcupados(){
        return new HashMap<String,Lugar>(this.listaLugaresOcupados);
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setListaLugaresOcupados(Map<String, Lugar> listaLugaresOcupados) {
        this.listaLugaresOcupados = listaLugaresOcupados;
    }

    public List<String> allMatriculas(){
        List<String> matriculas = new ArrayList<String>();
        this.listaLugaresOcupados.forEach((k,v) -> matriculas.add(k));
        for(String s : matriculas){
            System.out.println(s);
        }
        return matriculas;
    }

    public void novaOcupacao(Lugar l){
        if(this.listaLugaresOcupados.containsKey(l.getMatricula())){
            this.listaLugaresOcupados.get(l.getMatricula()).setMinutos(0);
        }
    }

    public void addLugar(Lugar l){
        this.listaLugaresOcupados.put(l.getMatricula(),l.clone());
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append("Parque{\n");
        sb.append("\tNome = '").append(this.nome).append("'\n");
        sb.append("\tLugares = " );
        this.listaLugaresOcupados.forEach((k, v) -> sb.append(v.toString()));
        sb.append('}');
        return sb.toString();
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Parque parque = (Parque) o;
        return Objects.equals(nome, parque.nome) && Objects.equals(listaLugaresOcupados, parque.listaLugaresOcupados);
    }
}
