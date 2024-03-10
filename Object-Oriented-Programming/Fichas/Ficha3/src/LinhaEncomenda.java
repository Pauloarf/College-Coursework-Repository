import java.util.Objects;

public class LinhaEncomenda {
    private String reference;
    private String description;
    private double price;
    private int amount;
    private int tax; //valor em percentagem
    private int discount; // valor em percentagem

    public LinhaEncomenda(){
        this.reference = "";
        this.description = "";
        this.price = 0;
        this.amount = 0;
        this.tax = 0;
        this.discount = 0;
    }

    public LinhaEncomenda(String ref, String des, double price, int amount, int tax, int discount){
        this.reference = ref;
        this.description = des;
        this.price = price;
        this.amount = amount;
        this.tax = tax;
        this.discount = discount;
    }

    public LinhaEncomenda(LinhaEncomenda linha){
        this.reference = linha.getReference();
        this.description = linha.getDescription();
        this.price = linha.getPrice();
        this.amount = linha.getAmount();
        this.tax = linha.getTax();
        this.discount = linha.getDiscount();
    }

    public String getReference(){
        return this.reference;
    }

    public void setReference(String reference){
        this.reference = reference;
    }

    public String getDescription(){
        return this.description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public double getPrice(){
        return this.price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public int getAmount() {
        return this.amount;
    }

    public void setAmount(int amount) {
        this.amount = amount;
    }

    public int getTax() {
        return this.tax;
    }

    public void setTax(int tax) {
        this.tax = tax;
    }

    public int getDiscount() {
        return this.discount;
    }

    public void setDiscount(int discount) {
        this.discount = discount;
    }

    public double calculaValorLinhaEnc(){
        double valor = this.price * (1 + (double) this.tax /100);
        valor -= this.calculaValorDesconto();
        return valor;
    }

    public double calculaValorDesconto(){
        double valor = this.price * (1 + (double) this.tax /100);
        valor *= (double) this.discount /100;
        return valor*this.amount;
    }

    @Override
    public String toString() {
        return "LinhaEncomenda{" +
                "reference='" + this.reference + '\'' +
                ", description='" + this.description + '\'' +
                ", price=" + this.price +
                ", amount=" + this.amount +
                ", tax=" + this.tax +
                ", discount=" + this.discount +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        LinhaEncomenda that = (LinhaEncomenda) o;
        return Double.compare(price, that.price) == 0 && amount == that.amount && tax == that.tax && discount == that.discount && Objects.equals(reference, that.reference) && Objects.equals(description, that.description);
    }

}
