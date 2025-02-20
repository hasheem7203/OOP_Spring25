#include <iostream>
using namespace std;

class car{
	private: 
		string brand;
		string model;
		float rentPrice;
		bool availability;
		float revenue;
		int id;

	public:
		car(){
			id=1;
			brand="unknown";
			model="Generic";
			rentPrice=0.0;
			availability=true;
			revenue=0.0;
		}

		car(int id,string brand,string model,float rentPrice,bool availability){
			this->id=id;
			this->brand=brand;
			this->model=model;
			this->rentPrice=rentPrice;
			this->availability=availability;
			revenue=0.0;
		}

    	void updateCar(string brand, string model, float rentPrice){
    	    this->brand=brand;
    	    this->model=model;
        	this->rentPrice=rentPrice;
        	this->revenue=0.0;
    	}

		void rentalRequest(){
			if (availability){
				cout << "available for rent \n";
				cout<<"car rented\n";
				availability=false;
			}else{
				cout <<"car allready rented\n";
			}			
		}

    void displayDetails(){
        cout<<"\nBrand :"<<brand<<endl;
        cout<<"Car ID : "<<id<<endl;
        cout<<"Model :"<< model<<endl;
        cout<<"Rental price :"<<rentPrice<<endl;
        cout << "Revenue Generated : "<<revenue<<endl;
        if (availability){
        	cout<<"STatus : Available For Rent."<<endl;
		}else{
			cout <<"Status : Rented0"<<endl;
		}
    }
    void generateRevenue(int days){
    	float discount;
    	if (availability){
    		cout<<"Car wasn't rented .\n";
		}else{
			if (days>10){
				discount=0.1;
			}else if (days>5){
				discount=0.05;
			}
			this->revenue+=rentPrice*days*(1-discount);
		}
	}
};

int main()
{
    car car1(101,"Toyota","Carolla", 5999.99, true);
    car1.rentalRequest();
    car1.generateRevenue(25);
    car car2(102,"suzuki","alto",1299.99,true);
    car2.rentalRequest();
    car2.generateRevenue(25);
    car car3(103,"suzuki", "cultus", 1499.99,true);
    car3.rentalRequest();
    car3.generateRevenue(20);
    car3.generateRevenue(40);
    car car4(104,"Honda","Civic",6999.99,true);
    car4.rentalRequest();
    car4.generateRevenue(25);
	car1.displayDetails();
    car2.displayDetails();
    car3.displayDetails();
    car4.displayDetails();
}
