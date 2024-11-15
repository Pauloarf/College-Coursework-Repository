package connections;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class TaggedConnection implements AutoCloseable {
    private final Socket socket;
    private final DataOutputStream out;
    private final DataInputStream in;
    private final Lock lr = new ReentrantLock();
    private final Lock ls = new ReentrantLock();

    public static class Frame {
        public final int tag;
        public final byte[] data;

        public Frame(int tag, byte[] data) {
            this.tag = tag;
            this.data = data;
        }
    }

    public TaggedConnection(Socket socket) throws IOException {
        this.socket = socket;
        this.out = new DataOutputStream(socket.getOutputStream());
        this.in = new DataInputStream(socket.getInputStream());
    }

    public void send(Frame frame) throws IOException {
        send(frame.tag, frame.data);
    }

    public void send(int tag, byte[] data) throws IOException {
        ls.lock();
        try{
            out.writeInt(data.length + 4);
            out.writeInt(tag);
            out.write(data);
            out.flush();
        } finally {
            ls.unlock();
        }
    }

    public Frame receive() throws IOException {
        lr.lock();
        try{
            int size = in.readInt();
            int tag = in.readInt();
            byte[] data = new byte[size-4];
            in.readFully(data);
            return new Frame(tag, data);
        } finally {
            lr.unlock();
        }
    }

    public void close() throws IOException {
        this.socket.close();
    }
}