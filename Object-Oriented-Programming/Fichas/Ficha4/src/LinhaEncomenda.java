import java.util.Objects;

public class LinhaEncomenda {
    private String referenciaProduto;
    private String descricaoProduto;
    private double precoProduto;
    private int quantidadeEncomendada;
    private double regimeImposto; // Em percentagem (ex: 6%, 13%, 23%, etc.)
    private double descontoComercial; // Em percentagem

    public LinhaEncomenda(){
        this.referenciaProduto = "N/a";
        this.descricaoProduto = "N/a";
        this.precoProduto = 0;
        this.quantidadeEncomendada = 0;
        this.regimeImposto = 0;
        this.descontoComercial = 0;
    }

    public LinhaEncomenda(String referenciaProduto, String descricaoProduto, double precoProduto, int quantidadeEncomendada, double regimeImposto, double descontoComercial) {
        this.referenciaProduto = referenciaProduto;
        this.descricaoProduto = descricaoProduto;
        this.precoProduto = precoProduto;
        this.quantidadeEncomendada = quantidadeEncomendada;
        this.regimeImposto = regimeImposto;
        this.descontoComercial = descontoComercial;
    }

    public LinhaEncomenda(LinhaEncomenda l){
        this.referenciaProduto = this.getReferenciaProduto();
        this.descricaoProduto = this.getDescricaoProduto();
        this.precoProduto = this.getPrecoProduto();
        this.quantidadeEncomendada = this.getQuantidadeEncomendada();
        this.regimeImposto = this.getRegimeImposto();
        this.descontoComercial = this.getDescontoComercial();
    }

    public String getReferenciaProduto() {
        return this.referenciaProduto;
    }

    public void setReferenciaProduto(String referenciaProduto) {
        this.referenciaProduto = referenciaProduto;
    }

    public String getDescricaoProduto() {
        return this.descricaoProduto;
    }

    public void setDescricaoProduto(String descricaoProduto) {
        this.descricaoProduto = descricaoProduto;
    }

    public double getPrecoProduto() {
        return this.precoProduto;
    }

    public void setPrecoProduto(double precoProduto) {
        this.precoProduto = precoProduto;
    }

    public int getQuantidadeEncomendada() {
        return this.quantidadeEncomendada;
    }

    public void setQuantidadeEncomendada(int quantidadeEncomendada) {
        this.quantidadeEncomendada = quantidadeEncomendada;
    }

    public double getRegimeImposto() {
        return this.regimeImposto;
    }

    public void setRegimeImposto(double regimeImposto) {
        this.regimeImposto = regimeImposto;
    }

    public double getDescontoComercial() {
        return this.descontoComercial;
    }

    public void setDescontoComercial(double descontoComercial) {
        this.descontoComercial = descontoComercial;
    }

    public double calculaValorLinhaEnc() {
        double precoSemImpostos = precoProduto * quantidadeEncomendada;
        double valorImpostos = precoSemImpostos * (regimeImposto / 100.0);
        double precoComImpostos = precoSemImpostos + valorImpostos;
        double valorDesconto = calculaValorDesconto();
        return precoComImpostos - valorDesconto;
    }

    public double calculaValorDesconto() {
        double precoSemImpostos = precoProduto * quantidadeEncomendada;
        return precoSemImpostos * (descontoComercial / 100.0);
    }

    public LinhaEncomenda clone(){
        return new LinhaEncomenda(this);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        LinhaEncomenda that = (LinhaEncomenda) o;
        return Double.compare(precoProduto, that.precoProduto) == 0 &&
                quantidadeEncomendada == that.quantidadeEncomendada &&
                Double.compare(regimeImposto, that.regimeImposto) == 0 &&
                Double.compare(descontoComercial, that.descontoComercial) == 0 &&
                Objects.equals(referenciaProduto, that.referenciaProduto) &&
                Objects.equals(descricaoProduto, that.descricaoProduto);
    }

    @Override
    public String toString() {
        return "LinhaEncomenda{" +
                "referenciaProduto='" + referenciaProduto + '\'' +
                ", descricaoProduto='" + descricaoProduto + '\'' +
                ", precoProduto=" + precoProduto +
                ", quantidadeEncomendada=" + quantidadeEncomendada +
                ", regimeImposto=" + regimeImposto +
                ", descontoComercial=" + descontoComercial +
                '}';
    }
}

