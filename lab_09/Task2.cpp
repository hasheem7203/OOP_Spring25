#include <iostream>
#include <string>

using namespace std;

class MenuItem {
protected:
    string dishName;
    double price;

public:
    MenuItem(string name, double cost) : dishName(name), price(cost) {}

    virtual void showDetails() = 0;
    virtual void prepare() = 0;

    virtual ~MenuItem() {}
};

class Appetizer : public MenuItem {
public:
    Appetizer(string name, double cost) : MenuItem(name, cost) {}

    void showDetails() override {
        cout << "Appetizer: " << dishName << " | Price: $" << price << endl;
    }

    void prepare() override {
        cout << "Preparing " << dishName << ": Light cooking and quick serving.\n";
    }
};

class MainCourse : public MenuItem {
public:
    MainCourse(string name, double cost) : MenuItem(name, cost) {}

    void showDetails() override {
        cout << "Main Course: " << dishName << " | Price: $" << price << endl;
    }

    void prepare() override {
        cout << "Preparing " << dishName << ": Full cooking with special spices.\n";
    }
};

int main() {
    Appetizer starter("Garlic Bread", 5.99);
    MainCourse entree("Grilled Chicken", 14.99);

    MenuItem* menu1 = &starter;
    MenuItem* menu2 = &entree;

    menu1->showDetails();
    menu1->prepare();

    cout << endl;

    menu2->showDetails();
    menu2->prepare();

    return 0;
}
