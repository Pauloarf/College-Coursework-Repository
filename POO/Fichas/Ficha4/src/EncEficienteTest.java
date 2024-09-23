import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.time.LocalDate;

import static org.junit.jupiter.api.Assertions.*;

public class EncEficienteTest {

    private EncEficiente encomenda;
    private LinhaEncomenda linha1;
    private LinhaEncomenda linha2;
    private LinhaEncomenda linha3;

    @BeforeEach
    void setUp() {
        encomenda = new EncEficiente();
        linha1 = new LinhaEncomenda("001", "Produto 1", 10, 5, 0.1, 0.05);
        linha2 = new LinhaEncomenda("002", "Produto 2", 20, 3, 0.15, 0.0);
        linha3 = new LinhaEncomenda("003", "Produto 3", 15, 2, 0.2, 0.1);
    }

    @Test
    void testAdicionaLinha() {
        encomenda.adicionaLinha(linha1);
        encomenda.adicionaLinha(linha2);
        assertEquals(2, encomenda.getLinhasEncomenda().size());
    }

    @Test
    void testRemoveProduto() {
        encomenda.adicionaLinha(linha1);
        encomenda.adicionaLinha(linha2);
        encomenda.removeProduto("002");
        assertEquals(1,  encomenda.getLinhasEncomenda().size());
    }

    @Test
    void testCalculaValorTotal() {
        encomenda.adicionaLinha(linha1);
        encomenda.adicionaLinha(linha2);
        encomenda.adicionaLinha(linha3);
        assertEquals(155.0, encomenda.calculaValorTotal());
    }

    @Test
    void testCalculaValorDesconto() {
        encomenda.adicionaLinha(linha1);
        encomenda.adicionaLinha(linha2);
        encomenda.adicionaLinha(linha3);
        assertEquals(11.0, encomenda.calculaValorDesconto());
    }

    @Test
    void testNumeroTotalProdutos() {
        encomenda.adicionaLinha(linha1);
        encomenda.adicionaLinha(linha2);
        encomenda.adicionaLinha(linha3);
        assertEquals(10, encomenda.numeroTotalProdutos());
    }

    @Test
    void testExisteProdutoEncomenda() {
        encomenda.adicionaLinha(linha1);
        encomenda.adicionaLinha(linha2);
        assertTrue(encomenda.existeProdutoEncomenda("002"));
        assertFalse(encomenda.existeProdutoEncomenda("004"));
    }
}
