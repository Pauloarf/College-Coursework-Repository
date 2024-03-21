import com.sun.source.tree.AssertTree;
import org.junit.Assert;
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
        LinhaEncomenda linha1 = new LinhaEncomenda("REF001", "Product 1", 10.50, 2, 0.5, 1.0);
        LinhaEncomenda linha2 = new LinhaEncomenda("REF002", "Product 2", 20.75, 1, 0.75, 1.5);
        LinhaEncomenda linha3 = new LinhaEncomenda("REF003", "Product 3", 15.25, 3, 0.25, 0.75);
        LinhaEncomenda linha4 = new LinhaEncomenda("REF004", "Product 4", 30.00, 2, 0.0, 0.0);
        LinhaEncomenda linha5 = new LinhaEncomenda("REF005", "Product 5", 12.99, 1, 0.1, 0.25);
        EncEficiente encEficiente = new EncEficiente("Paulo Ferreira", 242242242, "Rua dos lirios", LocalDate.now(), new ArrayList<LinhaEncomenda>());
        encEficiente.adicionaLinha(linha1);
        encEficiente.adicionaLinha(linha2);
        encEficiente.adicionaLinha(linha3);
        encEficiente.adicionaLinha(linha5);
        boolean verdade = encEficiente.existeProdutoEncomenda(linha1.getReferencia());
        boolean falso = encEficiente.existeProdutoEncomenda(linha4.getReferencia());
        assertTrue(verdade);
        assertFalse(falso);
    }

    @Test
    void adicionaLinha() {
    }

    @Test
    void removeProduto() {
    }
}