import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class BancoMultiplasContas {

    private static class Account {
        private Lock l = new ReentrantLock();
        private int balance;
        Account (int balance) { this.balance = balance; }
        int balance () {
            l.lock();
            try{
                return balance;
            } finally {
                l.unlock();
            }
        }
        boolean deposit (int value) {
            l.lock();
            try{
                balance += value;
                return true;
            } finally {
                l.unlock();
            }
        }
        boolean withdraw (int value) {
            l.lock();
            try{
                if (value > balance)
                    return false;
                balance -= value;
                return true;
            } finally {
                l.unlock();
            }
        }
    }

    // Bank lock
    //private Lock l = new ReentrantLock();

    // Bank slots and vector of accounts
    private final int slots;
    private Account[] av;

    public BancoMultiplasContas (int n) {
        slots=n;
        av=new Account[slots];
        for (int i=0; i<slots; i++)
            av[i]=new Account(0);
    }


    // Account balance
    public int balance (int id) {
        //l.lock();
        //try {
            if (id < 0 || id >= slots)
                return 0;
            return av[id].balance();
        //} finally {
        //    l.unlock();
        //}
    }

    // Deposit
    public boolean deposit (int id, int value) {
        //l.lock();
        //try{
            if (id < 0 || id >= slots)
                return false;
            return av[id].deposit(value);
        //} finally {
        //    l.unlock();
        //}
    }

    // Withdraw; fails if no such account or insufficient balance
    public boolean withdraw (int id, int value) {
        //l.lock();
        //try{
            // As slots é um valor imutável, por esta razão pode estar antes do lol
            if (id < 0 || id >= slots)
                return false;
            return av[id].withdraw(value);
        //} finally {
        //    l.unlock();
        //}
    }

    // Transfer
    /*
        Com a primeira solução:
                if (from < 0 || from >= slots || to < 0 || to >= slots){
            return withdraw(from, value) && deposit(from, value);
        A transferencia em si não é atomica, podendo um Withdraw começar logo a seguir a outro, isto faz com
        que o balanço final seja correto, mas o balanço em cada etapa de execução possa ser variavel.

        Utilizar Um lock nesta função resove o problema, mas não é a maneira mais eficiente de o fazer.
        (NOTA): Usando só locks na conta e usando a primeira solução os testes não funcionam... A tranfer continua a ser não atómica

        Esta solução faz com que cada metedo transfer tenha total controlo sobre as duas contas envolvidas, não deixando que ninhuma outra
        thread faça operações na mesma
     */
    public boolean transfer (int from, int to, int value) {
        if (from < 0 || from >= slots || to < 0 || to >= slots){
            return false;
        }
        Account fromAccount = av[from];
        Account toAccount = av[to];

        if(from < to){
            fromAccount.l.lock();
            toAccount.l.lock();
        } else {
            toAccount.l.lock();
            fromAccount.l.lock();
        }
        try {
            return toAccount.withdraw(value) && fromAccount.deposit(value);
        } finally {
            toAccount.l.unlock();
            fromAccount.l.unlock();
        }
    }

    // TotalBalance
    public int totalBalance () {
        int total=0;

        for (int i=0; i<slots; i++)
            av[i].l.lock();
        for (int i=0; i<slots; i++)
            total += av[i].balance();
        for (int i=0; i<slots; i++)
            av[i].l.unlock();
        return total;
    }
}
