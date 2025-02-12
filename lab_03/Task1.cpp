#include <iostream>
#include<string>
#include <sstream>
using namespace std;

string to_string(float num) {
    stringstream ss;
    ss<<num;
    return ss.str();
}

class wallet{
	private :
		string ownerName;
		int AccNo;
		float totalBalance;
		string transactionHistory[10];
		int transIndex;
		void history(string entry) {
        	if (transIndex < 10) {
    	        transactionHistory[transIndex] = entry;
	            transIndex++;
        	} else {
	            for (int i = 1; i < 10; i++) {
            	    transactionHistory[i-1]=transactionHistory[i];
        	    }
    	        transactionHistory[9]=entry;
	        }
    }	
	public :
		wallet(string name,int accno,float balance){
			ownerName= name;
			AccNo=accno;
			totalBalance=balance;
			transIndex=0;
		}
		string getname(){
			return ownerName;
		}
		float getBalance(){
			return totalBalance;
		}
		void alert(){
			if(totalBalance<10000){
				cout<<"***Notification***\n"<<"   Low In Cash\n";
			}
		}
		void deposit(float amount){
			if (amount>0){
				totalBalance+=amount;
				history("Deposited : Rs "+to_string(amount));
				cout<<"Amount Deposited Successfully!\nCurrent Balance : Rs "<<totalBalance<<endl;
			}else{
				 cout << "Invalid deposit amount!" << endl;
			}	
		}
		void withdraw(float amount){
			if (amount>0&&amount <=totalBalance){
				totalBalance-=amount;
				history("Withdrawed : Rs "+to_string(amount));
				cout<<"Amount Withdrawed Successfully!\nCurrent Balance : Rs "<<totalBalance<<endl;
			}else{
				cout << "Transaction failed! Insuffecient Balance." << endl;
			}
		}
		void displayHistory(){
			cout <<"\nTransaction History For Account Number : "<<AccNo<<endl;
	        for (int i=0;i<transIndex;i++) {
    	        cout<<transactionHistory[i]<<endl;
        	}
        	if (transIndex == 0) {
        	    cout<<"No Record Found."<<endl;
        	}			
		}
};




int main (){
	wallet SaadWallet("Saad",123456789,100000);
	float amt;
   
    while(1){
    	SaadWallet.alert();
    	int choice;
    	cout <<"WELCOME "<<SaadWallet.getname()<<endl;
    	cout<<"1.Check Balance\n";
    	cout<<"2.Deposit Amount\n";
    	cout<<"3.Withdraw Amount\n";
    	cout<<"4.Transaction History\n";
    	cout<<"5.Exit\n";
    	cout<<"--Choice : ";
    	cin>>choice;
    	switch(choice){
    		case 1:{
    			cout<<"Current Balance : Rs "<<SaadWallet.getBalance()<<endl;
				break;
			}
			case 2:{
				cout<<"Enter Amount To Be Deposited : ";
				cin>>amt;
				SaadWallet.deposit(amt);
				break;
			}
			case 3:{
				cout<<"Enter Amount To Be Withdrawn : ";
				cin>>amt;
				SaadWallet.withdraw(amt);
				break;
			}
			case 4:{
				SaadWallet.displayHistory();
				break;
			}
			case 5:{
				return 0;
				break;
			}
			default :{
				cout<<"Invalid Choice";
				break;
			}
		}
		system("pause");
		system("cls");
	}
    
}
