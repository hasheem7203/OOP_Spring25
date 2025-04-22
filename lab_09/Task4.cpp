#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class WeatherSensor {
public:
    virtual void readData() = 0;
    virtual void displayReport() = 0;
    virtual ~WeatherSensor() {}
};

class Thermometer : public WeatherSensor {
private:
    double temperature;
public:
    Thermometer() : temperature(0.0) {}

    void readData() override {
        srand(time(0));
        temperature = 15 + rand() % 20;
    }

    void displayReport() override {
        cout << "Thermometer Reading: " << temperature << "°C" << endl;
    }
};

class Barometer : public WeatherSensor {
private:
    double pressure;
public:
    Barometer() : pressure(0.0) {}

    void readData() override {
        srand(time(0) + 1);
        pressure = 980 + rand() % 40;
    }

    void displayReport() override {
        cout << "Barometer Reading: " << pressure << " hPa" << endl;
    }
};

int main() {
    Thermometer thermo;
    Barometer baro;

    WeatherSensor* sensors[2];
    sensors[0] = &thermo;
    sensors[1] = &baro;

    for (int i = 0; i < 2; i++) {
        sensors[i]->readData();
        sensors[i]->displayReport();
        cout << endl;
    }

    return 0;
}
