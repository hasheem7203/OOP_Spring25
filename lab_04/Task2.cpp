#include <iostream >
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
			void rentalRequest(){
				if (availability){
					cout << "available for rent \n";
					cout<<"car rented\n";
					availability=false;
				}else{
					cout <<"car allready rented\n";
				}
				
			}
			void applyDiscount(int days){
				if(availability){
					cout <<"car isnt rented";
					return;
				}
				if (days>10){
					cout <<"10 percent discount applied";
				}else if (days>5){
					cout <<"5 percent discount applied";
				}
			}
			
			
			
			

};

int main(){
	car c1("toy","carol",1100.9,true);
	c1.rentalRequest();
	c1.applyDiscount(6);
}
