import org.junit.jupiter.api.Test;
import java.util.HashSet;
import java.util.Set;

import static java.lang.Thread.sleep;
import static org.junit.jupiter.api.Assertions.*;

public class CasaInteligenteTest {

    @Test
    public void testAddLampada() {
        CasaInteligente casa = new CasaInteligente();
        Lampada lampada = new Lampada();
        casa.addLampada(lampada);
        assertEquals(1, casa.getLampadas().size());
    }

    @Test
    public void testLigaLampadaNormal() {
        CasaInteligente casa = new CasaInteligente();
        Lampada lampada = new Lampada();
        casa.addLampada(lampada);
        casa.ligaLampadaNormal(0);
        assertEquals(Lampada.State.ON, lampada.getModo());
    }

    @Test
    public void testLigaLampadaEco() {
        CasaInteligente casa = new CasaInteligente();
        Lampada lampada = new Lampada();
        casa.addLampada(lampada);
        casa.ligaLampadaEco(0);
        assertEquals(Lampada.State.ECO, lampada.getModo());
    }

    @Test
    public void testQtEmEco() {
        CasaInteligente casa = new CasaInteligente();
        Lampada lampada1 = new Lampada();
        Lampada lampada2 = new Lampada();
        casa.addLampada(lampada1);
        casa.addLampada(lampada2);
        casa.ligaLampadaEco(0);
        assertEquals(1, casa.qtEmEco());
        casa.ligaLampadaEco(1);
        assertEquals(2, casa.qtEmEco());
    }

    @Test
    public void testRemoveLampada() {
        CasaInteligente casa = new CasaInteligente();
        Lampada lampada1 = new Lampada();
        Lampada lampada2 = new Lampada();
        casa.addLampada(lampada1);
        casa.addLampada(lampada2);
        casa.removeLampada(1);
        assertEquals(1, casa.getLampadas().size());
        assertFalse(casa.getLampadas().contains(lampada2));
    }

    @Test
    public void testLigaTodasEco() {
        CasaInteligente casa = new CasaInteligente();
        Lampada lampada1 = new Lampada();
        Lampada lampada2 = new Lampada();
        casa.addLampada(lampada1);
        casa.addLampada(lampada2);
        casa.ligaTodasEco();
        assertEquals(Lampada.State.ECO, lampada1.getModo());
        assertEquals(Lampada.State.ECO, lampada2.getModo());
    }

    @Test
    public void testLigaTodasMax() {
        CasaInteligente casa = new CasaInteligente();
        Lampada lampada1 = new Lampada();
        Lampada lampada2 = new Lampada();
        casa.addLampada(lampada1);
        casa.addLampada(lampada2);
        casa.ligaTodasMax();
        assertEquals(Lampada.State.ON, lampada1.getModo());
        assertEquals(Lampada.State.ON, lampada2.getModo());
    }

    @Test
    public void testConsumoTotal() {
        CasaInteligente casa = new CasaInteligente();
        Lampada lampada1 = new Lampada();
        Lampada lampada2 = new Lampada();
        casa.addLampada(lampada1);
        casa.addLampada(lampada2);

        lampada1.lampON();
        lampada2.lampON();
        double consumoTotalEsperado = (lampada1.getConsumoTotal()) + (lampada2.getConsumoTotal());
        assertEquals(consumoTotalEsperado, casa.consumoTotal(), 0.001);
    }

    @Test
    public void testMaisGastadora() throws InterruptedException {
        CasaInteligente casa = new CasaInteligente();
        Lampada lampada1 = new Lampada();
        Lampada lampada2 = new Lampada();
        casa.addLampada(lampada1);
        casa.addLampada(lampada2);
        lampada1.lampON();
        sleep(2);
        lampada1.getConsumoTotal(); //atualiza o consumo
        lampada2.lampON();
        assertEquals(lampada1, casa.maisGastadora());
    }

    @Test
    public void testLampadasEmModoEco() {
        CasaInteligente casa = new CasaInteligente();
        Lampada lampada1 = new Lampada();
        Lampada lampada2 = new Lampada();
        casa.addLampada(lampada1);
        casa.addLampada(lampada2);
        casa.ligaLampadaEco(0);
        Set<Lampada> esperado = new HashSet<>();
        esperado.add(lampada1);
        assertEquals(esperado, casa.lampadasEmModoEco());
    }

    @Test
    public void testReset() {
        CasaInteligente casa = new CasaInteligente();
        Lampada lampada = new Lampada();
        casa.addLampada(lampada);
        lampada.lampON();
        casa.reset();
        assertEquals(0, lampada.totalConsumo());
    }

    @Test
    public void testPodiumEconomia() {
        CasaInteligente casa = new CasaInteligente();
        Lampada lampada1 = new Lampada();
        Lampada lampada2 = new Lampada();
        Lampada lampada3 = new Lampada();
        casa.addLampada(lampada1);
        casa.addLampada(lampada2);
        casa.addLampada(lampada3);
        lampada1.lampON();
        lampada2.lampON();
        lampada3.lampON(); 
        Set<Lampada> esperado = new HashSet<>();
        esperado.add(lampada3);
        esperado.add(lampada1);
        esperado.add(lampada2);
        assertEquals(esperado, casa.podiumEconomia());
    }
}
