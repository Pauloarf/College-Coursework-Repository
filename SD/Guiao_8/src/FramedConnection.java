import java.io.*;
import java.net.Socket;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class FramedConnection implements AutoCloseable {
    private final Socket socket;
    private final DataOutputStream out;
    private final DataInputStream in;
    private final Lock lr = new ReentrantLock();
    private final Lock ls = new ReentrantLock();

    public FramedConnection(Socket socket) throws IOException {
        this.socket = socket;
        this.out = new DataOutputStream(socket.getOutputStream());
        this.in = new DataInputStream(socket.getInputStream());
    }

    public void send(byte[] data) throws IOException {
        ls.lock();
        try{
            this.out.writeInt(data.length);
            this.out.write(data);
            this.out.flush();
        } finally {
            ls.unlock();
        }
    }

    public byte[] receive() throws IOException {
        lr.lock();
        try{
            int length = this.in.readInt();
            byte[] data = new byte[length];
            this.in.readFully(data);
            return data;
        } finally {
            lr.unlock();
        }
    }

    public void close() throws IOException {
        this.socket.close();
    }
}