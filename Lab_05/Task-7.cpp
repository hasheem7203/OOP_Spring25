#include <iostream>
#include <string>
using namespace std;

const int MAX_PRODUCTS = 50;

class Product {
public:
    int productId;
    string productName;
    int stockQuantity;

    Product() {}
    Product(int id, string name, int quantity) : productId(id), productName(name), stockQuantity(quantity) {}
};

class Warehouse {
private:
    Product inventory[MAX_PRODUCTS];
    int totalProducts;

public:
    Warehouse() : totalProducts(0) {}

    void addProduct(int id,string name,int quantity) {
        if(totalProducts<MAX_PRODUCTS) {
            inventory[totalProducts++]=Product(id,name,quantity);
        }else{
            cout<<"Warehouse capacity reached! Cannot store more products.\n";
        }
    }

    void sortInventory() {
        for (int i=0;i<totalProducts-1;i++) {
            for (int j=i+1;j<totalProducts;j++) {
                if (inventory[i].productName>inventory[j].productName) {
                    swap(inventory[i],inventory[j]);
                }
            }
        }
    }

    void findProductById(int id) const {
        for (int i=0;i<totalProducts;i++) {
            if (inventory[i].productId==id) {
                cout<<"Product Found: "<<inventory[i].productName<<" | Available Stock: "<<inventory[i].stockQuantity<<"\n";
                return;
            }
        }
        cout<<"No product found with ID "<<id<<".\n";
    }

    void displayStock() const {
        cout << "\nCurrent Warehouse Inventory:\n";
        for (int i = 0; i < totalProducts; i++) {
            cout<<"ID: "<< inventory[i].productId << " | Name: " << inventory[i].productName << " | Stock: " << inventory[i].stockQuantity << "\n";
        }
    }
};

int main() {
    Warehouse warehouse;
    warehouse.addProduct(2001,"Chair",15);
    warehouse.addProduct(2002, "LED TV",10);
    warehouse.addProduct(2003,"Flour Bag",30);
    warehouse.addProduct(2004,"Study Table",7);
    warehouse.addProduct(2005,"Microwave",20);

    warehouse.sortInventory();
    warehouse.displayStock();
    
    int searchId;
    cout << "\nEnter Product ID to search: ";
    cin >> searchId;
    warehouse.findProductById(searchId);
    
    return 0;
}
