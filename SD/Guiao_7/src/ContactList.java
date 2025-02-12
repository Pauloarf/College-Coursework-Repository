import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.util.ArrayList;

class ContactList extends ArrayList<Contact> {

    // @TODO
    public void serialize(DataOutputStream out) throws IOException {
        out.writeInt(size());
        for (Contact c : this) {
            c.serialize(out);
        }
    }

    // @TODO
    public static ContactList deserialize(DataInputStream in) throws IOException {
        int size = in.readInt();
        ContactList list = new ContactList();
        for (int i = 0; i < size; i++) {
            list.add(Contact.deserialize(in));
        }
        return list;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Contact c : this) {
            sb.append(c.toString());
            sb.append("\n");
        }
        return sb.toString();
    }

}
