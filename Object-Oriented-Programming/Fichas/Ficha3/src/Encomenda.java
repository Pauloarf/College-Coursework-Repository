import java.util.Arrays;
import java.util.Objects;

public class Encomenda {
    private String nomeCliente;
    private String numeroFiscalCliente;
    private String moradaCliente;
    private int numeroEncomenda;
    private String dataEncomenda;
    private LinhaEncomenda[] linhasEncomenda;
    private int numLinhas;

    public Encomenda() {
        this.nomeCliente = "N/a";
        this.numeroFiscalCliente = "N/a";
        this.moradaCliente = "N/a";
        this.numeroEncomenda = 0;
        this.dataEncomenda = "N/a";
        this.linhasEncomenda = new LinhaEncomenda[0];
        this.numLinhas = 0;
    }

    public Encomenda(String nomeCliente, String numeroFiscalCliente, String moradaCliente, int numeroEncomenda, String dataEncomenda, int capacidade) {
        this.nomeCliente = nomeCliente;
        this.numeroFiscalCliente = numeroFiscalCliente;
        this.moradaCliente = moradaCliente;
        this.numeroEncomenda = numeroEncomenda;
        this.dataEncomenda = dataEncomenda;
        this.linhasEncomenda = new LinhaEncomenda[capacidade];
        this.numLinhas = 0;
    }

    public Encomenda(Encomenda enc){
        this.nomeCliente = enc.getNomeCliente();
        this.numeroFiscalCliente = enc.getNumeroFiscalCliente();
        this.moradaCliente = enc.getMoradaCliente();
        this.numeroEncomenda = enc.getNumeroEncomenda();
        this.dataEncomenda = enc.getDataEncomenda();
        this.linhasEncomenda = enc.getLinhasEncomenda();
        this.numLinhas = enc.getNumLinhas();
    }

    public String getNomeCliente() {
        return this.nomeCliente;
    }

    public void setNomeCliente(String nomeCliente) {
        this.nomeCliente = nomeCliente;
    }

    public String getNumeroFiscalCliente() {
        return this.numeroFiscalCliente;
    }

    public void setNumeroFiscalCliente(String numeroFiscalCliente) {
        this.numeroFiscalCliente = numeroFiscalCliente;
    }

    public String getMoradaCliente() {
        return this.moradaCliente;
    }

    public void setMoradaCliente(String moradaCliente) {
        this.moradaCliente = moradaCliente;
    }

    public int getNumeroEncomenda() {
        return this.numeroEncomenda;
    }

    public void setNumeroEncomenda(int numeroEncomenda) {
        this.numeroEncomenda = numeroEncomenda;
    }

    public String getDataEncomenda() {
        return this.dataEncomenda;
    }

    public void setDataEncomenda(String dataEncomenda) {
        this.dataEncomenda = dataEncomenda;
    }

    public LinhaEncomenda[] getLinhasEncomenda() {
        return Arrays.copyOf(this.linhasEncomenda, this.linhasEncomenda.length);
    }

    public int getNumLinhas() {
        return this.numLinhas;
    }

    public double calculaValorTotal() {
        double valorTotal = 0;
        for (int i = 0; i < numLinhas; i++) {
            valorTotal += linhasEncomenda[i].calculaValorLinhaEnc();
        }
        return valorTotal;
    }

    public double calculaValorDesconto() {
        double valorDescontoTotal = 0;
        for (int i = 0; i < numLinhas; i++) {
            valorDescontoTotal += linhasEncomenda[i].calculaValorDesconto();
        }
        return valorDescontoTotal;
    }

    public int numeroTotalProdutos() {
        int totalProdutos = 0;
        for (int i = 0; i < numLinhas; i++) {
            totalProdutos += linhasEncomenda[i].getQuantidadeEncomendada();
        }
        return totalProdutos;
    }

    public boolean existeProdutoEncomenda(String refProduto) {
        for (int i = 0; i < numLinhas; i++) {
            if (linhasEncomenda[i].getReferenciaProduto().equals(refProduto)) {
                return true;
            }
        }
        return false;
    }

    public void adicionaLinha(LinhaEncomenda linha) {
        if (numLinhas < linhasEncomenda.length) {
            linhasEncomenda[numLinhas] = linha;
            numLinhas++;
        } else {
            System.out.println("Capacidade da encomenda excedida. Não foi possível adicionar a linha de encomenda.");
        }
    }

    public void removeProduto(String codProd) {
        for (int i = 0; i < numLinhas; i++) {
            if (linhasEncomenda[i].getReferenciaProduto().equals(codProd)) {
                for (int j = i; j < numLinhas - 1; j++) {
                    linhasEncomenda[j] = linhasEncomenda[j + 1];
                }
                linhasEncomenda[numLinhas - 1] = null;
                numLinhas--;
                return;
            }
        }
        System.out.println("Produto não encontrado na encomenda.");
    }

    public Encomenda clone(){
        return new Encomenda(this);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Encomenda encomenda = (Encomenda) o;
        return numeroEncomenda == encomenda.numeroEncomenda && numLinhas == encomenda.numLinhas && Objects.equals(nomeCliente, encomenda.nomeCliente) && Objects.equals(numeroFiscalCliente, encomenda.numeroFiscalCliente) && Objects.equals(moradaCliente, encomenda.moradaCliente) && Objects.equals(dataEncomenda, encomenda.dataEncomenda) && Arrays.equals(linhasEncomenda, encomenda.linhasEncomenda);
    }

    @Override
    public String toString() {
        return "Encomenda{" +
                "nomeCliente='" + nomeCliente + '\'' +
                ", numeroFiscalCliente='" + numeroFiscalCliente + '\'' +
                ", moradaCliente='" + moradaCliente + '\'' +
                ", numeroEncomenda=" + numeroEncomenda +
                ", dataEncomenda='" + dataEncomenda + '\'' +
                ", linhasEncomenda=" + Arrays.toString(linhasEncomenda) +
                ", numLinhas=" + numLinhas +
                '}';
    }
}

