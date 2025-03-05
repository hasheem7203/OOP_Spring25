#include <iostream>
#include <string>
using namespace std;

class AlarmSystem {
private:
    string securityLevel;

public:
    AlarmSystem(const string& level) : securityLevel(level) {}

    void display() const {
        cout<<"Security Level: "<<securityLevel<<endl;
    }
};

class SmartHome {
private:
    string homeID;
    AlarmSystem alarm;
public:
    SmartHome(const string& id,const string& securityLevel) : homeID(id),alarm(securityLevel) {}

    void display() const {
        cout<<"Smart Home ID: "<<homeID<<endl;
        alarm.display();
        cout<<endl;
    }
};

int main() {
    SmartHome home1("1034", "Low");    
    cout<<"Smart Home Details:\n";
    home1.display();
    
    return 0;
}
