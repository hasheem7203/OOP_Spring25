#include <iostream>
using namespace std;

class car{
	private: 
		string brand;
		string model;
		float rentPrice;
		bool availability;
		float revenue;

	public:
		car(){
			brand="unknown";
			model="Generic";
			rentPrice=0.0;
			availability=true;
			revenue=0.0;
		}

		car(string brand,string model,float rentPrice,bool availability){
			this->brand=brand;
			this->model=model;
			this->rentPrice=rentPrice;
			this->availability=availability;
			revenue=0.0;
		}

	    car(const car &obj){
    	    brand=obj.brand;
    	    model=obj.model;
    	    rentPrice=obj.rentPrice;
        	availability=obj.availability;
        	revenue=obj.revenue;
    	}

	    ~car(){
	        cout << "\nDestructor. " <<endl;
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
    car car1("Toyota","Carolla", 5999.99, true);
    car1.generateRevenue(10);
    car1.rentalRequest();
    car1.generateRevenue(25);
    car car2(car1);
    car1.displayDetails();
    car2.displayDetails();
    car1.updateCar("suzuki", "alto", 1499.99);
    car1.generateRevenue(20);
    car1.displayDetails();
    car2.displayDetails();
}
