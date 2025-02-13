#include <iostream>
#include<string>
#include <sstream>
using namespace std;

#define max 100


class car{
	private :
		string brand;
		string model;
		float fuelCapacity;
		float currentFuelLevel;
		float carFuelAvg; //(km/litre)
		
	public :
		car(string brand,string model,float fuelCapacity,float curFuelLevel){
			this->brand=brand;
			this->model=model;
			this->fuelCapacity=fuelCapacity;
			currentFuelLevel=curFuelLevel;
			carFuelAvg=10.00;
		}
		car(string brand,string model,float fuelCapacity,float curFuelLevel,float carFuelAvg){
			this->brand=brand;
			this->model=model;
			this->fuelCapacity=fuelCapacity;
			currentFuelLevel=curFuelLevel;
			this->carFuelAvg=carFuelAvg;
		}
		void driving(float distance){
			float fuelNeeded = distance / carFuelAvg;
			if(fuelNeeded<=currentFuelLevel){
				currentFuelLevel-=distance/carFuelAvg;
				cout<<"Current Fuel Level : "<<currentFuelLevel<<" Ltr Out Of "<<fuelCapacity<<endl;
			}else{
			cout << "Not enough fuel to drive " << distance << " km!\n";
            cout << "Current Fuel Level: " << currentFuelLevel << " Ltr\n";
            return;
			}
		}
		void refuel(float fuelRefill){
	        if (fuelRefill <= 0) {
    	        cout<<" Invalid fuel amount!\n";
        	    return;
        	}
			if((fuelRefill+currentFuelLevel)<=fuelCapacity){
				currentFuelLevel+=fuelRefill;
				cout << "Fuel Refilled Quantity : "<<fuelRefill<<endl;
				cout << "Current Fuel Level : "<<currentFuelLevel<<" Ltr"<<endl;
			}else{
				cout<<"Tank Fulled In  : "<<fuelCapacity-currentFuelLevel<<" Ltr"<<endl;
				cout <<"Fuel Saved : "<<fuelRefill-(fuelCapacity-currentFuelLevel)<<" Ltr"<<endl;
				currentFuelLevel+=(fuelCapacity-currentFuelLevel);
			}
		}
		void fuelStatus(){
			cout<<"___Fuel Status___\n";
			cout<<"---Current Fuel Level : "<<currentFuelLevel<<" Ltr"<<endl;
			cout<<"---Maximum Capacity : "<<fuelCapacity<<endl;
		}
		void alert(){
			if (currentFuelLevel<=5.00){
				cout <<"--LOW FUEL--"<<endl;
				cout<<"Remaining Fuel : "<<currentFuelLevel<<" Ltr"<<endl;
			}
		}

};




int main (){
	car car1=car("Toyota","Carrolla",50.00,30.00,11.00);;
   
    while(1){
    	car1.alert();
    	int choice;
    	cout<<"1.Drive \n";
    	cout<<"2.Refuel \n";
    	cout<<"3.Fuel Status\n";
    	cout<<"4.Exit\n";
    	cout<<"--Choice : ";
    	cin>>choice;
    	switch(choice){
    		case 1:{
    			float distance;
    			cout<<"Enter Distance To Drive (Km) : ";
    			cin>>distance;
    			car1.driving(distance);
				break;
			}
			case 2:{
				float fuel;
				cout<<"Enter The Fuel Quantity To Be Refilled : ";
				cin >>fuel;
				car1.refuel(fuel);
				break;
			}
			case 3:{
				car1.fuelStatus();
				break;
			}
			case 4:{
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
