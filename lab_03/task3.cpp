#include <iostream>
#include<string>
#include <sstream>
using namespace std;

#define max 100

class library{
	private :
		string librarianName ;
		string bookList[max];
		string borrowerName[max];
		int bookCount;
		bool status[max];
	public :
		library(string name){
			librarianName=name;
			bookCount=0;
		}
		string getname(){
			return librarianName;
		}
		void availableBooks(){
			cout <<"**Available Books**\n";
			int found =0;
    	    for (int i = 0; i < bookCount; i++) {
        	    if (status[i]) {
            	    cout <<"->"<<bookList[i] << endl;
                	found = 1;
            	}
			}
			if (!found ){
				cout <<"No Books Available\n";
			}
		}
		void borrowedBooks(){
			cout <<"**Borrowed Books**\n";
			int found =0;
    	    for(int i=0;i<bookCount;i++) {
        	    if(!status[i]) {
            	    cout <<"->"<<bookList[i] << endl;
                	found = 1;
            	}
			}
			if (!found ){
				cout <<"No Books Borrowed\n";
			}
		}
		void addBook(){
    		string bkname;
    		cin.ignore();
    		cout<<"Enter The Name Of Book : ";
    		getline(cin,bkname);
			if (bookCount<max){
				bookList[bookCount]=bkname;
				status[bookCount]=true;
				cout << "Book '" <<bkname<< "' added to the library.\n";
            	borrowerName[bookCount]="";	
				bookCount++;
			}else{
				cout<<"Library Is Full.";
			}
		}

    	void lendBooks(){
    		string bkname;
    		cin.ignore();
    		cout<<"Enter The Name Of Book : ";
    		getline(cin,bkname);
    		for (int i=0;i<bookCount ;i++){
    			if(bookList[i]==bkname){
    				if(status[i]){
    					cout <<"Enter Your Name : ";
    					getline(cin,borrowerName[i]);
    					cout<<"Book lended To "<<borrowerName[i]<<". Kindly Return in 7 Days ";
    					status[i]=false;
						return;
					}else{
						cout<<"Sorry Book Is Unavailable Currently. ";
						return;
					}
				}
			}	
			cout<<"Book Not Found";
		}
		void returnBooks(){
    		string bkname;
    		cin.ignore();
    		cout<<"Enter The Name Of Book : ";
    		getline(cin,bkname);
    		for(int i=0;i<bookCount;i++){
    			if(bookList[i]==bkname && !status[i]){
    				status[i]=true;
    				cout<<"Book Returned\n";
    				borrowerName[i]="";
    				return;
				}
			}
			cout <<"The Book Was Not Found Or Borrowed\n";
		}
};




int main (){
	library lib("Hamza");
   
    while(1){

    	int choice;
    	cout <<"WELCOME "<<lib.getname()<<endl;
    	cout<<"1.Available Books \n";
    	cout<<"2.Borrowed Books \n";
    	cout<<"3.Add Book\n";
    	cout<<"4.Lend Book\n";
		cout<<"5.Return Book\n";
		cout<<"6.Exit\n";
    	cout<<"--Choice : ";
    	cin>>choice;
    	switch(choice){
    		case 1:{
    			lib.availableBooks();
				break;
			}
			case 2:{
				lib.borrowedBooks();
				break;
			}
			case 3:{
				lib.addBook();
				break;
			}
			case 4:{
				lib.lendBooks();
				break;
			}
			case 5:{
				lib.returnBooks();
				break;
			}
			case 6:{
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
