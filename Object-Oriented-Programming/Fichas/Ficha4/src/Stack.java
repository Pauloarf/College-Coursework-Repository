import java.util.ArrayList;
import java.util.List;

public class Stack {
    private List<String> elements;

    public Stack() {
        this.elements = new ArrayList<>();
    }

    public String top() {
        if (empty()) {
            return null;
        }
        return elements.get(elements.size() - 1);
    }

    public void push(String s) {
        elements.add(s);
    }

    public void pop() {
        if (!empty()) {
            elements.removeLast();
        }
    }

    public boolean empty() {
        return elements.isEmpty();
    }

    public int length() {
        return elements.size();
    }
}
