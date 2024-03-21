import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.Optional;

public class EncEficiente {
    private static int quantidade = 0;

    private String nomeCliente;
    private int nif;
    private String morada;
    private int nrEncomenda;
    private LocalDate dataEncomenda;
    private List<LinhaEncomenda> listEncomendas;

    public EncEficiente(){
        this.nomeCliente = "N/a";
        this.nif = 0;
        this.morada = "N/a";
        this.nrEncomenda = quantidade++;
        this.dataEncomenda = LocalDate.now();
        this.listEncomendas = new ArrayList<LinhaEncomenda>();
    }

    public EncEficiente(String nomeCliente,
                        int nif,
                        String morada,
                        LocalDate dataEncomenda,
                        List<LinhaEncomenda> listEncomendas){
        this.nomeCliente = nomeCliente;
        this.nif = nif;
        this.morada = morada;
        this.nrEncomenda = quantidade++;
        this.dataEncomenda = dataEncomenda;
        this.listEncomendas = listEncomendas;
    }

    public EncEficiente(EncEficiente encomenda){
        this.nomeCliente = encomenda.getNomeCliente();
        this.nif = encomenda.getNif();
        this.morada = encomenda.getMorada();
        this.nrEncomenda = encomenda.getNrEncomenda();
        this.dataEncomenda = encomenda.getDataEncomenda();
        this.listEncomendas =encomenda.getListEncomendas();
    }

    public String getNomeCliente(){
        return this.nomeCliente;
    }

    public void setNomeCliente(String nomeCliente) {
        this.nomeCliente = nomeCliente;
    }

    public int getNif(){
        return this.nif;
    }

    public void setNif(int nif) {
        this.nif = nif;
    }

    public String getMorada(){
        return this.morada;
    }

    public void setMorada(String morada) {
        this.morada = morada;
    }

    public int getNrEncomenda(){
        return this.nrEncomenda;
    }

    public void setNrEncomenda(int nrEncomenda) {
        this.nrEncomenda = nrEncomenda;
    }

    public LocalDate getDataEncomenda(){
        return this.dataEncomenda;
    }

    public void setDataEncomenda(LocalDate dataEncomenda) {
        this.dataEncomenda = dataEncomenda;
    }

    public List<LinhaEncomenda> getListEncomendas() {
        return new ArrayList<LinhaEncomenda>(this.listEncomendas);
    }

    public void setListEncomendas(List<LinhaEncomenda> listEncomendas) {
        this.listEncomendas = listEncomendas;
    }

    public double calculaValorTotal(){
        double total = 0;
        for(LinhaEncomenda enc : this.listEncomendas){
            total += enc.calculaValorLinhaEnc();
        }
        return total;
    }

    public double calculaValorDesconto(){
        double desconto = 0;
        for(LinhaEncomenda enc : this.listEncomendas){
            desconto += enc.calculaValorDesconto();
        }
        return desconto;
    }

    public int numeroTotalProdutos(){
        int nrProdutos = 0;
        for(LinhaEncomenda enc : this.listEncomendas){
            nrProdutos += enc.getQuantidade();
        }
        return nrProdutos;
    }

    public boolean existeProdutoEncomenda(String refProduto){
        Optional<LinhaEncomenda> l = this.listEncomendas.stream().filter(a -> refProduto.equals(a.getReferencia())).findFirst();
        return  l.isPresent();
    }

    public void adicionaLinha(LinhaEncomenda linha){
        this.listEncomendas.add(linha);
    }

    public void removeProduto(String codProd){
        for(LinhaEncomenda enc : this.listEncomendas){
            if (codProd.equals(enc.getReferencia())){
                this.listEncomendas.remove(enc);
            }
        }
    }

    public EncEficiente clone(){
        return new EncEficiente(this);
    }
}

