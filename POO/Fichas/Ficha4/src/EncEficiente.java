import java.util.ArrayList;
import java.util.Objects;
import java.time.LocalDate;

public class EncEficiente {
    private String nomeCliente;
    private String numeroFiscalCliente;
    private String moradaCliente;
    private int numeroEncomenda;
    private LocalDate dataEncomenda;
    private ArrayList<LinhaEncomenda> linhasEncomenda;

    public EncEficiente() {
        this.nomeCliente = "";
        this.numeroFiscalCliente = "";
        this.moradaCliente = "";
        this.numeroEncomenda = 0;
        this.dataEncomenda = LocalDate.now();
        this.linhasEncomenda = new ArrayList<>();
    }

    public EncEficiente(String nomeCliente, String numeroFiscalCliente, String moradaCliente, int numeroEncomenda, LocalDate dataEncomenda) {
        this.nomeCliente = nomeCliente;
        this.numeroFiscalCliente = numeroFiscalCliente;
        this.moradaCliente = moradaCliente;
        this.numeroEncomenda = numeroEncomenda;
        this.dataEncomenda = dataEncomenda;
        this.linhasEncomenda = new ArrayList<>();
    }

    public EncEficiente(EncEficiente enc) {
        this.nomeCliente = enc.getNomeCliente();
        this.numeroFiscalCliente = enc.getNumeroFiscalCliente();
        this.moradaCliente = enc.getMoradaCliente();
        this.numeroEncomenda = enc.getNumeroEncomenda();
        this.dataEncomenda = enc.getDataEncomenda();
        this.linhasEncomenda = enc.getLinhasEncomenda();
    }

    public String getNomeCliente() {
        return nomeCliente;
    }

    public void setNomeCliente(String nomeCliente) {
        this.nomeCliente = nomeCliente;
    }

    public String getNumeroFiscalCliente() {
        return numeroFiscalCliente;
    }

    public void setNumeroFiscalCliente(String numeroFiscalCliente) {
        this.numeroFiscalCliente = numeroFiscalCliente;
    }

    public String getMoradaCliente() {
        return moradaCliente;
    }

    public void setMoradaCliente(String moradaCliente) {
        this.moradaCliente = moradaCliente;
    }

    public int getNumeroEncomenda() {
        return numeroEncomenda;
    }

    public void setNumeroEncomenda(int numeroEncomenda) {
        this.numeroEncomenda = numeroEncomenda;
    }

    public LocalDate getDataEncomenda() {
        return dataEncomenda;
    }

    public void setDataEncomenda(LocalDate dataEncomenda) {
        this.dataEncomenda = dataEncomenda;
    }

    public ArrayList<LinhaEncomenda> getLinhasEncomenda() {
        return new ArrayList<>(linhasEncomenda);
    }

    public double calculaValorTotal() {
        double valorTotal = 0;
        for (LinhaEncomenda linha : linhasEncomenda) {
            valorTotal += linha.calculaValorLinhaEnc();
        }
        return valorTotal;
    }

    public double calculaValorDesconto() {
        double valorDescontoTotal = 0;
        for (LinhaEncomenda linha : linhasEncomenda) {
            valorDescontoTotal += linha.calculaValorDesconto();
        }
        return valorDescontoTotal;
    }

    public int numeroTotalProdutos() {
        int totalProdutos = 0;
        for (LinhaEncomenda linha : linhasEncomenda) {
            totalProdutos += linha.getQuantidadeEncomendada();
        }
        return totalProdutos;
    }

    public boolean existeProdutoEncomenda(String refProduto) {
        for (LinhaEncomenda linha : linhasEncomenda) {
            if (linha.getReferenciaProduto().equals(refProduto)) {
                return true;
            }
        }
        return false;
    }

    public void adicionaLinha(LinhaEncomenda linha) {
        linhasEncomenda.add(linha);
    }

    public void removeProduto(String codProd) {
        linhasEncomenda.removeIf(linha -> linha.getReferenciaProduto().equals(codProd));
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        EncEficiente that = (EncEficiente) o;
        return numeroEncomenda == that.numeroEncomenda &&
                nomeCliente.equals(that.nomeCliente) &&
                numeroFiscalCliente.equals(that.numeroFiscalCliente) &&
                moradaCliente.equals(that.moradaCliente) &&
                dataEncomenda.equals(that.dataEncomenda) &&
                linhasEncomenda.equals(that.linhasEncomenda);
    }

    public EncEficiente clone(){
        return new EncEficiente(this);
    }

    @Override
    public String toString() {
        return "EncEficiente{" +
                "nomeCliente='" + nomeCliente + '\'' +
                ", numeroFiscalCliente='" + numeroFiscalCliente + '\'' +
                ", moradaCliente='" + moradaCliente + '\'' +
                ", numeroEncomenda=" + numeroEncomenda +
                ", dataEncomenda=" + dataEncomenda +
                ", linhasEncomenda=" + linhasEncomenda +
                '}';
    }
}
