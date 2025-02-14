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
			void setbrand(string bran){
				brand=bran;
			}
			void setmodel(string mode){
				model=mode;
			}
			void setrentPric(float price){
				rentPrice=price;
			}
			void setavailability(bool a){
				availability=a;
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

			
			
			
			

};

int main(){
	car c1;
	c1.setbrand("toyota");
	c1.rentalRequest();

} 
