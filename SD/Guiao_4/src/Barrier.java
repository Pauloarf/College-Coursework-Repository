import java.util.concurrent.locks.*;

public class Barrier {
    private final int N;
    private Lock l = new ReentrantLock();
    private Condition c = l.newCondition();
    private int count = 0;
    private int returned = 0;
    private boolean open = false;

    public Barrier(int N){
        this.N = N;
    }

    void await() throws InterruptedException {
        // Saber a fase em que estavamos e a fase para que vamos...
        l.lock();
        try {
            if(open){
                while(open){
                    c.await();
                }
            } else {
                c.signal();
                // Este signal pode ser dado depois da linha 42, e evitamos este if, else...
            }

            count++;

            if(count < N){
                while(count < N)
                    c.await();
            } else {
                c.signalAll();
                open = true;
                //c = 0
                //Para recomeçar o loop (ex2), não podemos igualar o c a 0 nesta fase pq as outras threads ao sairem do await podem não verificar o while
            }
            returned++;
            if(returned == N){
                returned = 0;
                count = 0;
                open = false;
            }
        } finally {
            l.unlock();
        }
    }
}
