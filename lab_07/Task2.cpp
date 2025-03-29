#include "iostream"
using namespace std ;



class product{
    protected:
        int productId;
        string name ;
        double price ;
        int stockQuantity;

    public :
        product(int id,string name,double price,int stock = 0)
        :productId(id),name(name),price(price),stockQuantity(stock){}

        virtual void  applyDiscount(){
            price =price*(80/100);
        }
        virtual double calculatePrice(int quantity){
            return price*quantity;
        }

        virtual void displayProductInfo(){
            cout <<"---Product Info---"<<endl;
            cout << "ID : "<<productId<<endl;
            cout <<"Name : "<<name<<endl;
            cout <<"Price : "<<price<<endl;
            cout <<"Stock Quantity : "<<stockQuantity<<endl;
        }
        friend ostream &operator<<(ostream &o, const product &p) {
            o << "Product ID: " << p.productId << "\nName: " << p.name
                << "\nPrice: Rs" << p.price << "\nStock: " << p.stockQuantity << "\n";
            return o;
        }
        product operator+(const product &o) {
            return product(0,"Bulk Purchase",price + o.price);
        }

};


class electronic : public product {
    string warrantyPeriod, brand;

public:
    electronic(int id, string name, double price, string warranty, string brand,int stockqty=0)
        : product(id, name, price,stockqty), warrantyPeriod(warranty), brand(brand) {}

    void displayProductInfo() override {
        product::displayProductInfo();
        cout << "Brand: " << brand << "\nWarranty: " << warrantyPeriod << "\n";
    }
};


class clothing :public product{
    private:
        string size;
        string color;
        string material ;

    public :
        clothing(int id, string name, double price,string size,string color,string material,int stockqty=0)
        :product (id,name,price,stockqty),size(size),color(color),material(material){}

        void applyDiscount() override {
            cout << "Clearance Sale flat 50 %"<<endl;
            price =price*0.5;
        }

        void displayProductInfo() override {
            product::displayProductInfo();
            cout << "Size: " << size << "\nColor: " << color << "\nFabric: " << material << "\n";
        }   
};

class foodItem:public product{
    private:
        string expdate;
        int calories;

    public:
        foodItem(int id, string name, double price,string expdate,int calories,int stockqty=0)
        :product(id,name,price,stockqty),expdate(expdate),calories(calories){}

        double calculatePrice(int quantity)override {
            if(quantity > 10)return price*quantity*0.6;
            return product::calculatePrice(quantity);
        }
};

class book:public product {
    private :
        string author;
        string genre;

    public :
        book(int id, string name, double price,string author,string genre,int stockqty=0)
        :product(id,name,price,stockqty),author(author),genre(genre){}


        void displayProductInfo()override{
            product::displayProductInfo();
            cout << "Author : "<<author<<endl;
            cout << "Genre : "<<genre<<endl;
        }
};

int main (){
    product p1(1,"T-shirts",1500);
    product p2(2,"Jeans",2500);
    product p3=p1+p2;
    cout<<p3<<endl;

    electronic e(3,"TV",3500,"6 months","Samsung",20);
    e.displayProductInfo();

    clothing c(4, "Pant", 550, "M", "blue", "denim",100);
    c.applyDiscount();

    foodItem f(5, "Burger", 150,"4-6-2025", 1000,70);
    cout << "Total Price: " << f.calculatePrice(5) << endl;

    book b(6, "aTOMIC hABBITS", 450, "srk", "phsycology");
    b.displayProductInfo();

    return 0;
}
