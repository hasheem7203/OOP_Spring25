#include <iostream>
using namespace std;

int *allocate(int x){
	int *ptr=new int[x];
	return ptr;
}
void deallocate(int *ptr){
    delete[] ptr;
}
void input(int *ptr,int x){
    for(int i=0;i<x;i++){
        cout<< "Enter any number:";
        cin>>*(ptr+i);
    }
}
void display(int *ptr,int x){
	for (int i=0;i<x;i++){
		cout<<*(ptr+i)<<endl;
	}
}
int main (){
	int x;
	cout<<"Enter the lentgh of string : ";
	cin >>x;
	int *ptr=allocate(x);
	input(ptr,x);
	display(ptr,x);
	deallocate(ptr);
}
