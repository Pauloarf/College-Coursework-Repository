import java.util.*;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;

class Warehouse {
    private Map<String, Product> map =  new HashMap<String, Product>();
    ReentrantLock l = new ReentrantLock();

    public class Product {
        int quantity = 0;
        Condition cond = l.newCondition();
    }

    public Map<String, Product> getMap() {
        return map;
    }

    private Product get(String item) {
        Product p = map.get(item);
        if (p != null) return p;
        p = new Product();
        map.put(item, p);
        return p;
    }

    public void supply(String item, int quantity) throws InterruptedException{
        l.lock();
        try{
            Product p = get(item);
            p.quantity += quantity;
            p.cond.signalAll();
        } finally {
            l.unlock();
        }
    }

    // Versão1 (Egoista)
    // Neste contexto, os produtos ficam adquiridos pela threads, e outras não podem usá-los
    public void consume(Set<String> items) throws InterruptedException{
        l.lock();
        try{
            for (String s : items) {
                Product p = get(s);
                while (p.quantity <= 0) {
                    p.cond.await();
                }
                p.quantity--;
            }
        } finally {
            l.unlock();
        }
    }

    //Versão2 (cooperativa)
    //Neste contexto, a ideia é que a thread só bloqueia quando tiver os produtos todos disponiveis
    //NOTE: Podemos sempre usar uma função auxiliar que nos verifique se há algum produto missing e retorna o mesmo para podermos usar a condition e o await
    public void consume2(Set<String> items) throws InterruptedException{
        l.lock();
        try{
            Product[] a = new Product[items.size()];
            int i = 0;
            for (String s : items) {
                a[i++] = get(s);
            }

            //Cuidado com a utilização de i++, se o colocarmos, no caso de rewind começamos no 1
            for (i = 0; i < a.length;) {
                while (a[i].quantity <= 0) {
                    a[i].cond.await();
                    i = 0;
                }
                    i++;
            }

            for(Product p : a){
                p.quantity--;
            }
        } finally {
            l.unlock();
        }
    }
}
