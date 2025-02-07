#include <iostream>
using namespace std ;
struct book {
	string title ;
	string author;
	int year;
};
void inputDetails(book* bk,int x){
	cout <<"==DETAILS==\n";
    for (int i = 0; i < x; i++) {
    	cin.ignore();
        cout << "Book " << i + 1 << ":";
        cout << "\n\t Enter Title Of Book: ";
        cin.ignore();
        getline(cin, bk[i].title);
        cout << "\t Enter Author Of Book: ";
        getline(cin, bk[i].author);
        cout << "\t Enter Year Of Publication: ";
        cin >> bk[i].year;
        cin.ignore();
    }
}
void displayDetails(book* bk,int x){
	int year ;
	cout << "\n\nEnter Minimum Year Of Publication : ";
	cin >>year;
	for(int i =0;i<x;i++){
		if (bk[i].year>=year){
	        cout << "Book " << i + 1 << ":\n";
    	    cout << "\tTitle: " << bk[i].title << endl;
    	    cout << "\tAuthor: " << bk[i].author << endl;
        	cout << "\tYear: " << bk[i].year << endl;		
		}
	}
}
int main (){
	int n;
	cout <<"Enter The Number Of Books  : ";
	cin>>n;
	book * arr=new book[n];
	inputDetails(arr,n);
	displayDetails(arr,n);
	delete[] arr;
}
