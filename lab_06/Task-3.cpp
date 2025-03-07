#include <iostream>
using namespace std;

class Account {
protected:
    int accNumber;
    float balance;

public:
    Account(int accNumber, float balance) : accNumber(accNumber), balance(balance) {}
    
    virtual void displayDetails() {
        cout << "Account Number: " << accNumber << endl;
        cout << "Balance: $" << balance << endl;
    }
};

class SavingsAccount : public Account {
protected:
    float interestRate;

public:
    SavingsAccount(int accNumber, float balance, float interestRate) : Account(accNumber, balance), interestRate(interestRate) {}

    void displayDetails() override {
        Account::displayDetails();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

class CheckingAccount : public Account {
protected:
    float overdraftLimit;

public:
    CheckingAccount(int accNumber, float balance, float overdraftLimit) : Account(accNumber, balance), overdraftLimit(overdraftLimit) {}

    void displayDetails() override {
        Account::displayDetails();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

int main() {
    int accNumber;
    float balance, interestRate, overdraftLimit;

    cout << "Enter Savings Account Number: ";
    cin >> accNumber;
    cout << "Enter Balance: ";
    cin >> balance;
    cout << "Enter Interest Rate (%): ";
    cin >> interestRate;
    SavingsAccount savings(accNumber, balance, interestRate);

    cout << "\nEnter Checking Account Number: ";
    cin >> accNumber;
    cout << "Enter Balance: ";
    cin >> balance;
    cout << "Enter Overdraft Limit: ";
    cin >> overdraftLimit;
    CheckingAccount checking(accNumber, balance, overdraftLimit);

    cout << "\nSavings Account Details:\n";
    savings.displayDetails();

    cout << "\nChecking Account Details:\n";
    checking.displayDetails();

    return 0;
}
