import java.time.LocalDate;
import java.time.temporal.ChronoUnit;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class VideoYT {
    private String nome;
    private byte[] conteudo;
    private LocalDate dataCarregamento;
    private int resolucao;
    private int duracao;
    private List<String> comentarios;
    private int likes;
    private int dislikes;

    public VideoYT(){
        this.nome = "N/a";
        this.conteudo = new byte[0];
        this.dataCarregamento= LocalDate.now();
        this.resolucao = 0;
        this.duracao = 0;
        this.comentarios = new ArrayList<String>();
        this.likes = 0;
        this.dislikes = 0;
    }

    public VideoYT(String nome,
                   byte[] conteudo,
                   LocalDate dataCarregamento,
                   int resolucao,
                   int duracao,
                   ArrayList<String> comentarios,
                   int likes,
                   int dislikes){
        this.nome = nome;
        this.conteudo = conteudo;
        this.dataCarregamento = dataCarregamento;
        this.resolucao = resolucao;
        this.duracao = duracao;
        this.comentarios = comentarios;
        this.likes = likes;
        this.dislikes = dislikes;
    }

    public VideoYT(VideoYT video){
        this.nome = video.getNome();
        this.conteudo = video.getConteudo();
        this.dataCarregamento = video.getDataCarregamento();
        this.resolucao = video.getResolucao();
        this.duracao = video.getDuracao();
        this.comentarios = video.getComentarios();
        this.likes = video.getLikes();
        this.dislikes = video.getDislikes();
    }

    public String getNome() {
        return this.nome;
    }

    public byte[] getConteudo() {
        return Arrays.copyOf(this.conteudo, this.conteudo.length);
    }

    public LocalDate getDataCarregamento() {
        return this.dataCarregamento;
    }

    public int getResolucao() {
        return this.resolucao;
    }

    public int getDuracao() {
        return this.duracao;
    }

    public List<String> getComentarios() {
        return new ArrayList<String>(this.comentarios);
    }

    public int getLikes() {
        return this.likes;
    }

    public int getDislikes() {
        return this.dislikes;
    }

    public void setComentarios(List<String> comentarios) {
        this.comentarios = comentarios;
    }

    public void setDataCarregamento(LocalDate dataCarregamento) {
        this.dataCarregamento = dataCarregamento;
    }

    public void setConteudo(byte[] conteudo) {
        this.conteudo = conteudo;
    }

    public void setDislikes(int dislikes) {
        this.dislikes = dislikes;
    }

    public void setDuracao(int duracao) {
        this.duracao = duracao;
    }

    public void setLikes(int likes) {
        this.likes = likes;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setResolucao(int resolucao) {
        this.resolucao = resolucao;
    }

    public void insereComentario(String comentario) {
        comentarios.add(comentario);
    }

    public long qtsDiasDepois() {
        LocalDate hoje = LocalDate.now();
        return ChronoUnit.DAYS.between(dataCarregamento, hoje);
    }

    public void thumbsUp() {
        this.likes++;
    }

    public String processa() {
        return new String(conteudo);
    }

    @Override
    public String toString() {
        return "VideoYT{\n" + "\n" +
                "\tnome='" + nome + "'\n" +
                "\tconteudo=" + Arrays.toString(conteudo) + "\n" +
                "\tdataCarregamento=" + dataCarregamento + "\n" +
                "\tresolucao='" + resolucao + "'\n" + "\n" +
                "\tduracao='" + duracao + "'\n" + "\n" +
                "\tcomentarios=" + comentarios + "\n" +
                "\tlikes=" + likes + "\n" +
                "\tdislikes=" + dislikes + "\n" +
                '}';
    }
}
