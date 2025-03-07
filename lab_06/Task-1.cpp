#include<iostream>
using namespace std;

class employee{
	protected:
		string name;
		float salary;
		
	public:
		employee(string name,float salary):name(name),salary(salary){}
		
		virtual void displayDetails(){
			cout <<"Name : "<<name <<endl;
			cout <<"Salary : "<<salary<<endl;
		}
		
};

class manager :public employee{
	private:
		float bonus;
		
	public:
		manager(string name, float salary,float bonus):employee(name,salary),bonus(bonus){}
		
		
		void displayDetails() override{
			cout<< "Name : "<<name<<endl;
			cout << "Salary : "<<salary <<endl;
			cout <<"Bonus : "<<bonus<< endl ;
		}
		
};

int main (){
	
	string name;
	float salary,bonus;
	cout<<"Enter Manager's name: ";
    getline(cin, name);
    cout<<"Enter manager's salary: ";
    cin>>salary;
    cout<<"Enter manager' bonus: ";
    cin>>bonus;
	
	
	manager m1(name,salary,bonus);
	m1.displayDetails();
	
}

