#include <iostream>
using namespace std ;
struct student{
	string name;
	int rollno;
	int marks[3];
};
student *allocate(int x){
	student *ptr=new student[x];
	return ptr;
}
void deallocate(student *ptr,float *ptr1){
	delete[] ptr;
	delete[] ptr1;
}
void input(student *ptr,int x){
	cout<<"Enter Details Of Students \n";
	for(int i=0; i<x;i++){
		cin.ignore();
		cout <<"Enter Name Of Student "<<i+1<<": ";
		getline(cin,ptr[i].name);
		cout <<"Enter RollNo Of Student : ";
		cin>>ptr[i].rollno;
		for(int j=0;j<3;j++){
			cout<<"Enter Marks "<<j+1<<" Of Student : ";
			cin>>ptr[i].marks[j];
		}
		cout<<endl;
	}
}
float *avg(student *ptr,int x){
	float *avgptr=new float[x];
	for (int i=0 ; i<x;i++){
		int sum =0 ;
		for(int j=0 ;j<3;j++){
			sum+=ptr[i].marks[j];
		}
		avgptr[i]=sum/3.0;
	}
	return avgptr;
}
void display(student *ptr,float *avg,int x){
	cout<<"====Details Of Student====\n";
	for (int i=0;i<x;i++){
		cout <<"Student Name : "<<ptr[i].name<<endl;
		cout <<"Student Roll_No : "<<ptr[i].rollno<<endl;
		cout <<"Student Average Marks : "<<avg[i]<<endl;
	}
}
int main (){
	int x;
	cout <<"Enter The Number Of Students : ";
	cin >>x;
	student *ptr=allocate(x);
	input(ptr,x);
	float *avgptr=avg(ptr,x);
	display(ptr,avgptr,x);
	deallocate(ptr,avgptr);	
}
