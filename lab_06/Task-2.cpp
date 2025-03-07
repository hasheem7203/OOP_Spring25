#include "iostream"
using namespace std ;

class vehicle{
	protected :
		string brand ;
		int speed;
		
	public :
		vehicle(string brand ,int speed):brand(brand),speed(speed){}
		virtual void displayDetails(){
			cout <<"Brand : "<<brand <<endl;
			cout <<"Speed : "<<speed<<endl;
		}
};


class car :protected vehicle{
	protected :
		int seats;
		
	public :
		car(string brand ,int speed,int seats):vehicle(brand,speed),seats(seats){}
		
		void displayDetails() override {
			cout <<"Brand : "<<brand <<endl;
			cout <<"Speed : "<<speed<<endl;
			cout <<"Seats : "<<seats<<endl;
		}
}; 


class electricCar :protected car{
	private :
		float batteryLife;
		
	public :
		electricCar(string brand ,int speed,int seats,float batteryLife): car(brand,speed,seats),batteryLife(batteryLife){}
		
		void displayDetails() override {
			cout <<"Brand : "<<brand <<endl;
			cout <<"Speed : "<<speed<<endl;
			cout <<"Seats : "<<seats<<endl;
			cout << "BatteryLife : "<<batteryLife<<endl;			
		}
};

int main(){
	
	string brand;
	int speed,seats;
	float batteryLife;
	
	cout<<"Enter Brand Of Car : ";
	getline(cin,brand);
	cout<<"Enter Max Speed : ";
	cin>>speed;
	cout<<"Enter No. Of Seats : ";
	cin>>seats;
	cout<<"Enter BatteryLife : ";
	cin >>batteryLife;
	cout<<endl ;
	
	
	electricCar e1(brand,speed,seats,batteryLife);
	e1.displayDetails();
}



