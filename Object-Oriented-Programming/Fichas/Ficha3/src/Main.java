public class Main {
    public static void main(String[] args){
        System.out.println("A criar encomendas...");
        LinhaEncomenda lencomenda1 = new LinhaEncomenda("asv6919", "O melhor batao", 100, 1, 10, 30);
        LinhaEncomenda lencomenda2 = new LinhaEncomenda(lencomenda1);
        lencomenda2.setReference("asder219619");
        lencomenda2.setDescription("PCComponentes");
        lencomenda2.setPrice(300);

        System.out.println("Encomendas Criadas: ");
        System.out.println(lencomenda1.toString());
        System.out.println(lencomenda2.toString());

        System.out.println("Valores ecnomendas 1:");
        System.out.println("Valor = " + lencomenda1.calculaValorLinhaEnc());
        System.out.println("Desconto = " + lencomenda1.calculaValorDesconto());
        System.out.println();

        System.out.println("Valores ecnomendas 2:");
        System.out.println("Valor = " + lencomenda2.calculaValorLinhaEnc());
        System.out.println("Desconto = " + lencomenda2.calculaValorDesconto());
        System.out.println();
    }
}