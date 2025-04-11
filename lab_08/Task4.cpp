#include <iostream>
using namespace std;

class InventoryManager;

class Car {
private:
    string car_model;
    double car_price;

public:
    Car(string model = "", double value = 0.0) {
        car_model = model;
        car_price = value;
    }

    friend class InventoryManager;

    friend void comparePrice(Car car_one, Car car_two);
};

class InventoryManager {
public:
    void updateCarPrice(Car& target_car, double new_price) {
        target_car.car_price = new_price;
    }

    void showCarDetails(Car car_obj) {
        cout << "Model: " << car_obj.car_model << endl;
        cout << "Price: " << car_obj.car_price << endl;
    }
};

void comparePrice(Car car_one, Car car_two) {
    if (car_one.car_price > car_two.car_price) {
        cout << car_one.car_model << " is more expensive.\n";
    } else if (car_two.car_price > car_one.car_price) {
        cout << car_two.car_model << " is more expensive.\n";
    } else {
        cout << "Both have the same price.\n";
    }
}

int main() {

    Car carA("G-Wagon", 30000);
    Car carB("Carolla", 28000);

    InventoryManager manager;

    cout << "--- Initial Car Info ---\n";
    manager.showCarDetails(carA);
    manager.showCarDetails(carB);

    manager.updateCarPrice(carB, 32000);

    cout << "\n--- Updated Car Info ---\n";
    manager.showCarDetails(carA);
    manager.showCarDetails(carB);

    cout << "\n--- Price Comparison ---\n";
    comparePrice(carA, carB);

    return 0;
}
