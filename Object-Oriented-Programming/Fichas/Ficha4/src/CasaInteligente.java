import java.util.*;
import java.util.stream.Collectors;

public class CasaInteligente {

    private List<Lampada> lampadaList;

    public CasaInteligente(){
        this.lampadaList = new ArrayList<Lampada>();
    }

    public CasaInteligente(List<Lampada> lampadaList){
        this.lampadaList = new ArrayList<>(lampadaList);
    }

    public List<Lampada> getLampadaList(){
        return new ArrayList<>(lampadaList);
    }

    public void setLampadaList(List<Lampada> lampadaList) {
        this.lampadaList = new ArrayList<>(lampadaList);
    }

    public void addLampada(Lampada l){
        this.lampadaList.add(l);
    }

    public String toString() {
        return "CasaInteligente{" +
                "lampadaList=" + lampadaList +
                '}';
    }

    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || this.getClass() != o.getClass()) return false;
        CasaInteligente c = (CasaInteligente) o;
        return Objects.equals(lampadaList, c.lampadaList);
    }

    public void ligaLampadaNormal(int index){
        this.lampadaList.get(index).lampON();
    }

    public void ligaLampadaEco(int index){
        this.lampadaList.get(index).lampECO();
    }

    public int qtEmEco(){
        int qt = 0;
        if(lampadaList.stream().anyMatch(l -> l.getModo() == Lampada.Modo.ECO)){
            qt++;
        }
        return qt;
    }

    public Set<Lampada> lampadasEmModoEco(){
        return lampadaList.stream().filter(l -> l.getModo() == Lampada.Modo.ECO).collect(Collectors.toSet());
    }
}