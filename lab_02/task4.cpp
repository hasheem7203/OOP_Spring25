#include <iostream>
using namespace std ;
string *allocate(int x){
	string *ptr=new string[x];
	return ptr;
}
void deallocate(string *ptr){
    delete[] ptr;
}
void input (string *ptr ,int x){
	cin.ignore();
	for(int i=0;i<x;i++){
		cout <<"enter string "<<i+1<<":";
		getline(cin, ptr[i]);
	}
}
void display(string *ptr,int x){
	for(int i=0;i<x;i++){
		cout <<ptr[i]<<endl;
	}
}
void sort(string *ptr ,int x){
	for(int i=0;i<x;i++){
		for (int J=0;J<x-i-1;J++){
			if(ptr[J+1]<ptr[J]){
				string Temp=ptr[J];
				ptr[J]=ptr[J+1];
				ptr[J+1]=Temp;
			}
		}
	}
}
int main(){
	int X;
	cout << "Enter The Number Of Strings : ";
	cin >>X;
	string *ptr=allocate(X);
	input(ptr,X);
	cout<<"++Sorted Strings++\n";
	sort(ptr,X);
	display(ptr,X);
	deallocate(ptr);
}
