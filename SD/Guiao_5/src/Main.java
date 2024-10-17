public class Main {
    public static void main(String[] args) {
        Warehouse warehouse = new Warehouse();

        for (int i = 0; i < 10; i++) {
            try {
                warehouse.supply("Martelo", 1);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }

        for (int i = 0; i < 10; i++) {
            try {
                warehouse.supply("Serra", 1);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }

        for (int i = 0; i < 10; i++) {
            try {
                warehouse.supply("Parafusos", 1);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }
}