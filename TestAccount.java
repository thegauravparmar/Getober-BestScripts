class Account {
    private int Account_No;
    private String Name;
    private double Balance;
    private String History;
    public static int count = 0;

    public int getAccount_No() {
        return this.Account_No;
    }

    public void setAccount_No(int Account_No) {
        this.Account_No = Account_No;
    }

    public String getName() {
        return this.Name;
    }

    public void setName(String Name) {
        this.Name = Name;
    }

    public double getBalance() {
        return this.Balance;
    }

    public void setBalance(double Balance) {
        if (Balance > 0)
            this.Balance = Balance;
        else
            this.Balance = 0;
    }

    public String getAccountHistory() {
        return this.History;
    }

    public void setHistory(String History) {
        this.History = History;
    }

    @Override
    public String toString() {
        return "{" +
                " Account_No='" + getAccount_No() + "'" +
                ", Name='" + getName() + "'" +
                ", Balance='" + getBalance() + "'" +
                "}";
    }

    public void Deposit(int amount) {
        amount = amount > 0 ? amount : 0;
        setBalance(getBalance() + amount);
        setHistory(String.valueOf(amount) + "amount is depsoited\n");
    }

    public void Withdraw(int amount) {
        if (amount < getBalance()) {
            setBalance(getBalance() - amount);
            setHistory(String.valueOf(amount) + "amount is withdrawn\n");
        }
    }

    public static int getNumberOfAccountCreated() {
        return count;
    }

    public Account() {
        this.History = "Welcome Mr/Miss." + Name + " Your Account is created with $" + String.valueOf(getBalance())
                + " balance\n";
        count++;
    }

    public Account(int Account_No, String Name, double Balance, String History) {
        this.Account_No = Account_No;
        this.Name = Name;
        this.Balance = Balance > 0 ? Balance : 0;
        this.History = "Welcome Mr/Miss." + Name + " Your Account is created with $" + String.valueOf(getBalance())
                + " balance\n";
        count++;
    }

}

public class TestAccount {
    public static void main(String[] args) {
        Account A = new Account();
        Account B = new Account();
        Account C = new Account(123, "Aman", 450, "");
        Account D = new Account(456, "Gaurav", 600, "");
        Account E = new Account(789, "Subham", 150, "");
        A.Deposit(200);
        C.Deposit(700);
        D.Withdraw(300);
        E.Withdraw(150);
        System.out.println(A.toString());
        System.out.println(B.toString());
        System.out.println(C.toString());
        System.out.println(D.toString());
        System.out.println(E.toString());
    }
}
