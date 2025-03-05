#include <iostream>
#include <cstring>
using namespace std;

class apartment {
private:
    int id;
    string address;
    char* owner;

public:
    apartment(int aptID, const string& aptAddress, const char* aptOwner) : id(aptID), address(aptAddress) {
        owner=new char[strlen(aptOwner)+1];
        strcpy(owner,aptOwner);
    }

    apartment(const apartment& source) : id(source.id),address(source.address),owner(source.owner){}

    void showDetails() const {
        cout<<"apartment ID: "<<id<<"\nLocation: "<<address<<"\nOwner: "<<owner<<"\n\n";
    }
    
    ~apartment() {
        delete[] owner;
    }
};

int main(){
    apartment apt1(402, "21 street", "Ali Ahmed");
    cout<<"Apartment Details:\n";
    apt1.showDetails();

    apartment apt2 = apt1;
    cout<<"Copied apartment Details for New Agent:\n";
    apt2.showDetails();

    return 0;
}
