import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

public class StackTest {

    @Test
    void testEmptyStack() {
        Stack stack = new Stack();
        assertTrue(stack.empty());
        assertNull(stack.top());
        assertEquals(0, stack.length());
    }

    @Test
    void testPushAndPop() {
        Stack stack = new Stack();

        stack.push("A");
        assertFalse(stack.empty());
        assertEquals("A", stack.top());
        assertEquals(1, stack.length());

        stack.push("B");
        assertEquals("B", stack.top());
        assertEquals(2, stack.length());

        stack.pop();
        assertEquals("A", stack.top());
        assertEquals(1, stack.length());

        stack.pop();
        assertTrue(stack.empty());
        assertNull(stack.top());
        assertEquals(0, stack.length());
    }

    @Test
    void testTopOnEmptyStack() {
        Stack stack = new Stack();
        assertNull(stack.top());
    }

    @Test
    void testPopOnEmptyStack() {
        Stack stack = new Stack();
        stack.pop();
        assertTrue(stack.empty());
    }

    @Test
    void testLength() {
        Stack stack = new Stack();
        stack.push("A");
        stack.push("B");
        stack.push("C");
        assertEquals(3, stack.length());
    }
}
