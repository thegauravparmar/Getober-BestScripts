class BankAccount:
    def __init__(self, account_holder, balance=0):
        self.account_holder = account_holder
        self.balance = balance

    def deposit(self, amount):
        if amount > 0:
            self.balance += amount
            print(f"Deposited ${amount}. New balance: ${self.balance}")
        else:
            print("Invalid deposit amount. Amount must be greater than 0.")

    def withdraw(self, amount):
        if 0 < amount <= self.balance:
            self.balance -= amount
            print(f"Withdrew ${amount}. New balance: ${self.balance}")
        else:
            print("Invalid withdrawal amount or insufficient balance.")

    def get_balance(self):
        return self.balance

    def __str__(self):
        return f"Account holder: {self.account_holder}, Balance: ${self.balance}"


# Create two bank accounts
account1 = BankAccount("Alice", 1000)
account2 = BankAccount("Bob", 500)

# Perform transactions
print("Initial account information:")
print(account1)
print(account2)

account1.deposit(500)
account2.withdraw(200)

print("\nUpdated account information:")
print(account1)
print(account2)
