#include <iostream>
using namespace std;

class car{
	private: 
		string brand;
		string model;
		float rentPrice;
		bool availability;

	public:
		car(){
			brand="unknown";
			model="Generic";
			rentPrice=0.0;
			availability=true;
		}

		car(string brand,string model,float rentPrice,bool availabiltity){
			this->brand=brand;
			this->model=model;
			this->rentPrice=rentPrice;
			this->availability=availability;
		}

	    car(const car &obj){
    	    brand=obj.brand;
    	    model=obj.model;
    	    rentPrice=obj.rentPrice;
        	availability=obj.availability;
    	}

	    ~car(){
	        cout << "\nDestructor. " <<endl;
	    }

    	void updateCar(string brand, string model, float rentPrice){
    	    this->brand=brand;
    	    this->model=model;
        	this->rentPrice=rentPrice;
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
        if (availability){
        	cout<<"STatus : Available For Rent."<<endl;
		}else{
			cout <<"Status : Rented0"<<endl;
		}
    }
};

int main()
{
    car car1("Toyota","Carolla", 5999.99, true);
    car car2(car1);
    car1.displayDetails();
    car2.displayDetails();
    car1.updateCar("suzuki", "alto", 1499.99);
    car1.displayDetails();
    car2.displayDetails();
}
