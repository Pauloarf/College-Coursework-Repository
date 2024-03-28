import java.util.Objects;

public class JogoFutebol {
    public enum Estado {
        POR_INICIAR,
        A_DECORRER,
        TERMINADO
    }

    private Estado estado;
    private int golosVisitado;
    private int golosVisitante;

    public Estado getEstado() {
        return this.estado;
    }

    public void setEstado(Estado estado) {
        this.estado = estado;
    }

    public int getGolosVisitado() {
        return this.golosVisitado;
    }

    public void setGolosVisitado(int golosVisitado) {
        this.golosVisitado = golosVisitado;
    }

    public int getGolosVisitante() {
        return this.golosVisitante;
    }

    public void setGolosVisitante(int golosVisitante) {
        this.golosVisitante = golosVisitante;
    }

    public JogoFutebol() {
        this.estado = Estado.POR_INICIAR;
        this.golosVisitado = 0;
        this.golosVisitante = 0;
    }

    public JogoFutebol(JogoFutebol fut) {
        this.estado = fut.getEstado();
        this.golosVisitado = fut.getGolosVisitado();
        this.golosVisitante = fut.getGolosVisitante();
    }

    public void startGame() {
        if (estado == Estado.POR_INICIAR) {
            estado = Estado.A_DECORRER;
        } else {
            System.out.println("O jogo já está em andamento.");
        }
    }

    public void endGame() {
        if (estado == Estado.A_DECORRER) {
            estado = Estado.TERMINADO;
        } else {
            System.out.println("O jogo já terminou.");
        }
    }

    public void goloVisitado() {
        if (estado == Estado.A_DECORRER) {
            golosVisitado++;
        } else {
            System.out.println("Não é possível marcar golo nesta fase do jogo.");
        }
    }

    public void goloVisitante() {
        if (estado == Estado.A_DECORRER) {
            golosVisitante++;
        } else {
            System.out.println("Não é possível marcar golo nesta fase do jogo.");
        }
    }

    public String resultadoActual() {
        if (estado == Estado.POR_INICIAR) {
            return "Jogo ainda não começou.";
        } else if (estado == Estado.A_DECORRER) {
            return "Resultado atual: Visitado " + golosVisitado + " - " + golosVisitante + " Visitante";
        } else {
            return "Resultado final: Visitado " + golosVisitado + " - " + golosVisitante + " Visitante";
        }
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        JogoFutebol that = (JogoFutebol) o;
        return golosVisitado == that.golosVisitado && golosVisitante == that.golosVisitante && estado == that.estado;
    }

    @Override
    public int hashCode() {
        return Objects.hash(estado, golosVisitado, golosVisitante);
    }

    public JogoFutebol clone(){
        return new JogoFutebol(this);
    }

    @Override
    public String toString() {
        return "JogoFutebol{" +
                "estado=" + estado +
                ", golosVisitado=" + golosVisitado +
                ", golosVisitante=" + golosVisitante +
                '}';
    }
}
