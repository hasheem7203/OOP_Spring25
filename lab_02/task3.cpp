#include <iostream>
using namespace std;
struct employee{
	string name;
	int hoursworked;
	float hourlyrate ;
};
employee *allocate(int x)
{
    employee *ptr = new employee[x];
    return ptr;
}
void input(employee *ptr,int x){
	cout<<"Enter Details Of Employee\n";
	for(int i=0;i<x;i++){
		cin.ignore();
		cout<<"Employee"<<i+1<<endl;
		cout<<"Enter Name Of Employee : ";
		getline(cin,ptr[i].name);
		cout<<"\nEnter HoursWorked Of Employee : ";
		cin>>ptr[i].hoursworked;
		cout<<"\nEnter Hourlyrate Of Employee : ";
		cin>>ptr[i].hourlyrate;		
	}
}
float* salary(employee *ptr,int x){
	float *salaryArr=new float[x];
	for(int i=0;i<x;i++){
		salaryArr[i]=ptr[i].hourlyrate * ptr[i].hoursworked;
	}
	return salaryArr;
}
void display(employee *ptr,int x,float *sal){
	cout <<"Details Of Employee \n";
	for (int i=0;i<x;i++){
        cout << "Name: " <<ptr[i].name << endl;
        cout << "Hourly rate: " <<ptr[i].hourlyrate<< endl;
        cout << "Hours worked: " <<ptr[i].hoursworked<< endl;
        cout << "Salary: " <<sal[i]<<endl;
	}
	
}
void deallocate(employee *ptr){
    delete[] ptr;
}
int main(){
	int x;
	cout<<"Enter number of employees : ";
	cin>>x;
	employee *employees = allocate(x);
	input(employees,x);
	float *salptr=salary(employees,x);
	display(employees,x,salptr);
	deallocate(employees);
}
