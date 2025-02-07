#include <iostream>
using namespace std;

struct product{
	int productid;
	string name;
	int quantity;
	float price;
};
product *allocate(int x){
	product *ptr=new product[x];
	return ptr;
}
void deallocate(product *ptr, float *tvalue){
    delete[] ptr;
    delete[] tvalue;
}
void input(product *ptr,int x){
	for(int i=0;i<x;i++){
        cout << "Enter Product ID:";
        cin >>ptr[i].productid;
        cout<< "Enter Product Name:";
        cin>>ptr[i].name;
        cout<<"Enter Product Quantity:";
        cin>> ptr[i].quantity;
        cout<< "Enter Unit Price:";
        cin>>ptr[i].price;
        cout<< endl;
	}
}
float* totalvalue(product *ptr,int x){
	float* tvalue=new float[x];
	for (int i=0;i<x;i++){
		tvalue[i]=ptr[i].price*ptr[i].quantity;
	}
	return tvalue;
}
void display(product *ptr,float *tvalue,int x){
    for (int i=0;i<x;i++){
        cout << "Product ID:" <<ptr[i].productid << endl;
        cout << "Product Name:" <<ptr[i].name << endl;
        cout << "Quantity:" <<ptr[i].quantity << endl;
        cout << "Price per unit:" <<ptr[i].price << endl;
        cout << "Total inventory Value :" <<tvalue[i] << endl;
        cout << endl;
    }
}
int main(){
	int x;
	cout <<"Enter Number Of Products : ";
	cin >>x;
	product* ptr=allocate(x);
	input(ptr,x);
	float* tvalue=totalvalue(ptr,x);
	display(ptr,tvalue,x);
	deallocate(ptr, tvalue);
}

