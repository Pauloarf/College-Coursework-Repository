class Bank {

    private static class Account {
        private int balance;

        Account(int balance) {
            this.balance = balance;
        }

        int balance() {
            return balance;
        }

        boolean deposit(int value) {
            balance += value;
            return true;
        }
    }

    // Our single account, for now
    private Account savings = new Account(0);

    // Account balance
    public int balance() {
        return savings.balance();
    }

    // Deposit
    boolean deposit(int value) {
        return savings.deposit(value);
    }
}

class Depositor implements Runnable {
    final int I;
    final Bank bank;

    public Depositor(int I, Bank bank) {
        this.I = I;
        this.bank = bank;
    }

    public void run() {
        for (long i = 0; i < this.I; i++)
            bank.deposit(1);
    }
}

class Increment implements Runnable {
    final int I;

    public Increment(int I) {
        this.I = I;
    }

    public void run() {
        for (long i = 0; i < this.I; i++)
            System.out.println(i);
    }
}

public class Main {
    public static void ex1(int N, int I) throws InterruptedException {
        Thread[] threadArray = new Thread[N];

        for (int i = 0; i < N-1; i++) {
            Thread mythread = new Thread(new Increment(I));
            threadArray[i] = mythread;
            threadArray[i].start();
        }
        for (int i = 0; i < N-1; i++) {
            threadArray[i].join();
        }
        System.out.println("FIM");
    }

    public static void ex2(int N, int I) throws InterruptedException {
        Bank bank = new Bank();
        Thread[] threadArray = new Thread[N];

        for (int i = 0; i < N-1; i++) {
            Thread mythread = new Thread(new Depositor(I,bank));
            threadArray[i] = mythread;
            threadArray[i].start();
        }
        for (int i = 0; i < N-1; i++) {
            threadArray[i].join();
        }
        System.out.println(bank.balance());
    }

    public static void main(String[] args) throws InterruptedException {
        int N = Integer.parseInt(args[0]);
        int I = Integer.parseInt(args[1]);
        ex1(N,I);
        ex2(N,I);
    }
}