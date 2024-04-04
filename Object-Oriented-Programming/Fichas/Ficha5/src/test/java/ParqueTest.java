import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ParqueTest {

    Lugar lugar1 = new Lugar("123ABC", "Lugar A", 30, true);
    Lugar lugar2 = new Lugar("456DEF", "Lugar B", 60, false);
    Lugar lugar3 = new Lugar("789GHI", "Lugar C", 15, true);
    Lugar lugar4 = new Lugar("ABC123", "Lugar D", 45, false);
    Lugar lugar5 = new Lugar("DEF456", "Lugar E", 90, true);

    Parque parque1 = new Parque("Parque das coives");
    @Test
    void allMatriculas() {
        parque1.addLugar(lugar1);
        parque1.addLugar(lugar2);
        parque1.addLugar(lugar3);
        parque1.addLugar(lugar4);
        parque1.addLugar(lugar5);

        parque1.allMatriculas();
    }

    @Test
    void addLugar() {
    }

    @Test
    void testToString() {

        System.out.println(parque1.toString());
    }

}