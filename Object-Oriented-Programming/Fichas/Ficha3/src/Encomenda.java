import java.time.LocalDate;

public class Encomenda {
    public static final int CAPACIDADA_INICIAL = 10;
    private String name;
    private int nif;
    private String address;
    private int numEncomenda;
    private LocalDate data;
    private int ocupacao;
    private int capacidade;
    private LinhaEncomenda [] linhas;

    public Encomenda(String name, int nif, String address, int numEncomenda, LocalDate data, int ocupacao, LinhaEncomenda [] linhas){
        this.name = name;
        this.nif = nif;
        this.address = address;
        this.numEncomenda = numEncomenda;
        this.data = data;
        this.ocupacao = ocupacao;
        capacidade = linhas.length;
        this.linhas = new LinhaEncomenda[capacidade];

        for(int i = 0; i < this.ocupacao; i++){
            this.linhas[i] = linhas[i].clone();
        }
    }


}
