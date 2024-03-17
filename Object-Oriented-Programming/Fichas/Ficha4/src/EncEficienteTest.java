import org.junit.jupiter.api.Test;
import java.time.LocalDate;
import java.util.*;

import static org.junit.jupiter.api.Assertions.*;

class EncEficienteTest {

    @Test
    void calculaValorTotal() {
        EncEficiente encEficiente = new EncEficiente("Paulo Ferreira", 242242242, "Rua dos lirios", LocalDate.now(), new ArrayList<LinhaEncomenda>());
        double valor = encEficiente.calculaValorTotal();
        double sum = 0;
        assertTrue(valor >= 0);
        for(LinhaEncomenda a : encEficiente.getListEncomendas()){
            sum += a.calculaValorLinhaEnc();
            assertTrue(valor >= a.calculaValorLinhaEnc());
            assertEquals(valor, sum);
        }

    }

    @Test
    void calculaValorDesconto() {
    }

    @Test
    void numeroTotalProdutos() {
    }

    @Test
    void existeProdutoEncomenda() {
    }

    @Test
    void adicionaLinha() {
    }

    @Test
    void removeProduto() {
    }
}