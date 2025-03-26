#include <iostream>
using namespace std;


class device{
	protected:
		int deviceId;
		string deviceName;
		bool status;
		string location;
		
	public:
		device(int deviceId,string deviceName,bool status,string location = "Unknown"):deviceId(deviceId),deviceName(deviceName),location(location),status(false){}
		
    virtual void turnOn() { status = true; }
    virtual void turnOff() { status = false; }
    virtual void getStatus() const {
        cout<<deviceName<<" is "<<(status ? "ON" : "OFF")<< endl;
    }
    virtual void displayInfo() const {
        cout<<"Device ID: "<<deviceId<<"\nName: "<<deviceName<<"\nLocation: "<<location<<"\nStatus: "<<(status ? "ON" : "OFF")<<"\n";
    }
    
};

class light : public device {
	private:
		int brightnessLevel;
		string colorMode;
		
	public :
		light(int deviceId,string deviceName,bool status,string location,int blevel,string cmode)
		:device(deviceId,deviceName,status,location),brightnessLevel(blevel),colorMode(cmode){}
		void displayInfo() const override{
			device::displayInfo();
			cout<<"Brightness Level : "<<brightnessLevel<<endl;
			cout <<"Color Mode : "<<colorMode<<endl;
		}
};

class thermostat: public device{
	private:
		double temperature;
		string mode;
		double targetTemperature;
		
	public:
	 thermostat(int deviceId,string deviceName,bool status,string location, double temp, string mod, double target)
        :device(deviceId, deviceName,status, location), temperature(temp), mode(mod), targetTemperature(target) {}

    void getStatus() const override {
        cout << deviceName <<" : "<<endl<< "Mode : "<<mode<<"\nCurrent temperature : " <<temperature << "`C";
    }	
};

class securityCamera : public device {
private:
    string resolution;
    bool recordingStatus;
    bool nightVisionEnabled;

public:
    securityCamera(int deviceId,string deviceName,bool status,string location, string res, bool nightVision)
	:device(deviceId, deviceName,status, location), resolution(res), nightVisionEnabled(nightVision), recordingStatus(false) {}

    void turnOn() override {
        status = true;
        recordingStatus = true;
        cout << deviceName <<" : "<< endl<<"Status : Recording." << endl;
    }
};

class SmartPlug : public device {
private:
    double powerConsumption;
    int timerSetting;

public:
    SmartPlug(int deviceId,string deviceName,bool status,string location, double power, int timer)
        : device(deviceId, deviceName,status, location), powerConsumption(power), timerSetting(timer) {}

    void turnOff() override{
        status=false;
        cout<<deviceName<<" : "<<endl<<"Status : OFF."<<powerConsumption<<" kWh\n";
    }
    
};

int main() {
    light RoomLight(1,"LED 1",1,"BedRoom",50,"warm");
    thermostat Thermostat(2, "Room Thermostat",1, "BedRoom", 22.5, "Cooling", 24.0);
    securityCamera garageCam(3, "Garage Camera",0, "Entrance", "1080p", true);
    SmartPlug microwave(4, "Microwave Plug",1, "Kitchen", 1.5, 30);

    RoomLight.displayInfo();
    Thermostat.getStatus();
    garageCam.turnOn();
    microwave.turnOff();

    return 0;
}


