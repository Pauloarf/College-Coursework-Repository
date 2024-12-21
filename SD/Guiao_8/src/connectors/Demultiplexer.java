package connectors;

import java.io.IOException;
import java.util.ArrayDeque;
import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;


//TODO: O que falta seria implementar o Garbage collector
// Como verificamos que uma entrada pode ser removida ou nao do mapa... isto para não estourar com a memoria do map
// Não podemos simplesmente remover a entrada pq algumas threads poderiam estar a espera... e o start iria criar outra entrada... deixando as threads a olhar para uma entry que já nao existe
// O ideal seria ter um contador de threads a espera... deste modo, podemos concluir que, se uma entry já não tiver threads a espera, então já a podemos remover
public class Demultiplexer implements AutoCloseable {
    private TaggedConnection connection;
    private Map<Integer, Entry> map = new HashMap<>();
    private final Lock l = new ReentrantLock();
    private IOException exception = null;

    private class Entry{
        ArrayDeque<byte[]> queue = new ArrayDeque<>();
        Condition cond = l.newCondition();
    }

    private Entry get(int tag){
        Entry entry = map.get(tag);
        if(entry == null){
            entry = new Entry();
            map.put(tag, entry);
        }
        return entry;
    }

    public Demultiplexer(TaggedConnection conn) {
        this.connection = conn;
    }

    public void start() {
        new Thread(() -> {
            try {
                for(;;){
                    TaggedConnection.Frame f = connection.receive();
                    l.lock();
                    try {
                        Entry e = get(f.tag);
                        e.queue.add(f.data);
                        e.cond.signal();
                    } finally {
                        l.unlock();
                    }
                }
            } catch (IOException e) {
                l.lock();
                try{
                    this.exception = e;
                    for(Entry entry : map.values()){
                        entry.cond.signalAll();
                    }
                } finally {
                    l.unlock();
                }
                throw new RuntimeException(e);
            }
        }).start();
    }

    public void send(TaggedConnection.Frame frame) throws IOException {
        connection.send(frame);
    }

    public void send(int tag, byte[] data) throws IOException {
        connection.send(tag, data);
    }

    public byte[] receive(int tag) throws IOException, InterruptedException {
        l.lock();
        try {
            Entry e = get(tag);
            while(!e.queue.isEmpty() && exception == null) e.cond.await();
            byte[] b = e.queue.poll();
            if(b != null){
                return b;
            } else {
                throw exception;
            }
        } finally {
            l.unlock();
        }
    }

    @Override
    public void close() throws Exception {
        this.connection.close();
    }
}
