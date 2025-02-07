#include <iostream>
using namespace std ;
int *allocate(int x){
	int *ptr =new int [x];
	return ptr;
}
void deallocate(int *ptr){
	delete[] ptr;
}
void input(int *ptr,int x){
	cout<<"Enter "<<x<<" Numbers :\n";
	for(int i=0;i<x;i++){
		cin>>*(ptr+i);
	}
}
void sum(int *ptr,int x){
	int Sum=0;
	for(int i=0;i<x;i++){
		Sum+=*(ptr+i);
	}
	cout <<"Sum of Numbers In Array Is : "<<Sum<<endl;
}
void display(int *ptr,int x){
	for ( int i =0 ;i<x ;i++){
		cout<<"Num "<<i+1<<" is "<<*(ptr+i)<<endl;
	}
}
int main (){
	int x;
	cout <<"Enter The Size Of Array : ";
	cin >>x;
	int *ptr =allocate(x);
	input(ptr,x);
	display(ptr,x);
	sum(ptr,x);
	deallocate(ptr);
}
