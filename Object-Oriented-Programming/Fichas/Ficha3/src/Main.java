import java.util.Scanner;

public class Main {
    public static void main(String[] args){

        System.out.println("Escolha o exercicio que pretende realizar: (1-10)");

        Scanner sc = new Scanner(System.in);
        int exercise = sc.nextInt();
        sc.nextLine();
        switch (exercise){
            case 1:
                System.out.println("Foi criado um circulo com a seguinte innformação: ");
                Circulo ci = new Circulo(5,5,2.5);
                System.out.println(ci.toString());
                System.out.println("A area deste circulo é: " + ci.calculaArea());
                System.out.println("O perimetro deste circulo é: " + ci.calculaPerimetro());
                break;
            case 2:
                System.out.println("Criando sensor com valor negativo...");
                Sensor sensor1 = new Sensor(-25);
                System.out.println(sensor1.toString());
                System.out.println("Criando sensor...");
                Sensor sensor2 = new Sensor();
                System.out.println(sensor2.toString());
                System.out.println("Lida pressão de 25...");
                System.out.println(sensor2.setPressao(25));
                System.out.println(sensor2.toString());
                System.out.println("Lida pressão de -25...");
                System.out.println(sensor2.setPressao(-25));
                System.out.println(sensor2.toString());
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
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
                break;
            case 9:
                break;
            case 10:
                break;
            default:
                System.out.println("O numero que introduziu nao corresponde a nenhum exercicio!");
                System.out.println("Tente novamente...");
        }
    }
}