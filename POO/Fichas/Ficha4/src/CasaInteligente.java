import java.awt.*;
import java.util.*;
import java.util.List;

public class CasaInteligente {
    private List<Lampada> lampadas;

    public CasaInteligente() {
        this.lampadas = new ArrayList<>();
    }

    public List<Lampada> getLampadas() {
        return new ArrayList<Lampada>(this.lampadas);
    }

    public void addLampada(Lampada l) {
        lampadas.add(l);
    }

    public void ligaLampadaNormal(int index) {
        if (index >= 0 && index < lampadas.size()) {
            lampadas.get(index).lampON();
        } else {
            System.out.println("Índice inválido.");
        }
    }

    public void ligaLampadaEco(int index) {
        if (index >= 0 && index < lampadas.size()) {
            lampadas.get(index).lampECO();
        } else {
            System.out.println("Índice inválido.");
        }
    }

    public int qtEmEco() {
        int count = 0;
        for (Lampada lampada : lampadas) {
            if (lampada.getModo() == Lampada.State.ECO) {
                count++;
            }
        }
        return count;
    }

    public void removeLampada(int index) {
        if (index >= 0 && index < lampadas.size()) {
            this.lampadas.remove(index);
        } else {
            System.out.println("Índice inválido.");
        }
    }

    public void ligaTodasEco() {
        for (Lampada lampada : lampadas) {
            lampada.lampECO();
        }
    }

    public void ligaTodasMax() {
        for (Lampada lampada : lampadas) {
            lampada.lampON();
        }
    }

    public double consumoTotal() {
        double consumoTotal = 0;
        for (Lampada lampada : this.lampadas) {
            consumoTotal += lampada.totalConsumo();
        }
        return consumoTotal;
    }

    public Lampada maisGastadora() {
        Lampada maisGastadora = null;
        double maxConsumo = Double.MIN_VALUE;
        for (Lampada lampada : lampadas) {
            if (lampada.totalConsumo() > maxConsumo) {
                maisGastadora = lampada;
                maxConsumo = lampada.totalConsumo();
            }
        }
        return maisGastadora;
    }

    public Set<Lampada> lampadasEmModoEco() {
        Set<Lampada> lampadasEco = new HashSet<>();
        for (Lampada lampada : lampadas) {
            if (lampada.getModo() == Lampada.State.ECO) {
                lampadasEco.add(lampada);
            }
        }
        return lampadasEco;
    }

    public void reset() {
        for (Lampada lampada : lampadas) {
            lampada.resetPeriodo();
        }
    }

    public Set<Lampada> podiumEconomia() {
        List<Lampada> sortedLampadas = new ArrayList<>(lampadas);
        sortedLampadas.sort(Comparator.comparingDouble(Lampada::totalConsumo));
        Set<Lampada> podium = new HashSet<>();
        int count = 0;
        for (Lampada lampada : sortedLampadas) {
            if (count >= sortedLampadas.size() - 3) {
                podium.add(lampada);
            }
            count++;
        }
        return podium;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        CasaInteligente that = (CasaInteligente) o;
        return Objects.equals(lampadas, that.lampadas);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("CasaInteligente{lampadas=[");
        for (Lampada lampada : lampadas) {
            sb.append(lampada.toString()).append(", ");
        }
        if (!lampadas.isEmpty()) {
            sb.delete(sb.length() - 2, sb.length());
        }
        sb.append("]}");
        return sb.toString();
    }

}
