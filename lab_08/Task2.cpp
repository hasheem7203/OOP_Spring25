# include <iostream>
using namespace std ;


class account {
    private:
        int accNumber;
        double balance;
    public:
        account(int num,double bal):accNumber(num),balance(bal){};
        friend class manager;
        friend void transferFunds(account &a1, account &a2, double amount);
};

class manager{
    public :
        void displayDetails(account& acc){
            cout <<"Account Details : \n";
            cout << "Account Number : "<<acc.accNumber<<endl;
            cout << "Balance : "<<acc.balance<<endl;
        }
        void deposit(account& acc,double deposit){
            acc.balance+=deposit;
            cout <<"Amount Deposited successfuly ! "<<endl<<"Balance : "<<acc.balance<<endl;
        }
        void withdraw(account& acc,double withdraw){
            acc.balance-=withdraw;
            cout <<"Amount Withdrawn successfuly ! "<<endl<<"Balance : "<<acc.balance<<endl;
        }
        
};



void transferFunds(account &a1, account &a2, double amount){
    if (a1.balance >= amount && amount > 0) {
        a2.balance += amount;
        a1.balance -= amount;
        cout << "Transfer of " << amount << " successful!\n";
    } else {
        cout << "Transfer failed: Insufficient funds or invalid amount.\n";
    }
}

int main (){
        account a1(987654321,1500);
        account a2(123456789,900);
    
        manager m1;
    
        m1.displayDetails(a1);
        m1.deposit(a1,2000);
        m1.displayDetails(a1);
        m1.withdraw(a1,3000);
    
        m1.displayDetails(a2);
        m1.deposit(a2,2000);
        m1.displayDetails(a2);
        m1.withdraw(a2,300);
    
        cout << "\nTransferring 400 from A1 to A2...\n";
        transferFunds(a1, a2, 400);
    
        m1.displayDetails(a1);
        m1.displayDetails(a2);
    
        return 0;
}
