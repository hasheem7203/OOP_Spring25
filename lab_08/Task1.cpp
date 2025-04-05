#include "iostream"
#include <cmath>
using namespace std ;

class comp{
    double real,img;

    public:
        comp(double r=0,double i=0):real(r),img(i){}

        friend comp operator+(comp& c1,comp& c2);
        friend comp operator-(comp& c1,comp& c2);
        friend comp operator*(comp& c1,comp& c2);
        friend comp operator/(comp& c1,comp& c2);
        friend ostream& operator<<(ostream& COUT,comp& obj);
        friend double magnitude(const comp& c);
};


comp operator+(comp& c1,comp& c2){
    comp res;
    res.real=c1.real+c2.real;
    res.img=c1.img+c2.img;
    return res;
}
comp operator-(comp& c1,comp& c2){
    comp res;
    res.real=c1.real-c2.real;
    res.img=c1.img-c2.img;
    return res;
}
comp operator*(comp& c1,comp& c2){
    comp res;
    res.real=c1.real*c2.real-c1.img*c2.img;
    res.img=c1.img*c2.real+c1.real*c2.img;
    return res;
}
comp operator/(comp& c1,comp& c2){
    comp res;
    double denom = c2.real * c2.real + c2.img * c2.img;
    res.real = (c1.real * c2.real + c1.img * c2.img) / denom;
    res.img = (c1.img * c2.real - c1.real * c2.img) / denom;
    return res;
}

ostream& operator<<(ostream& COUT,comp& obj){
    COUT<<" = ("<<obj.real<<"+"<<obj.img<<"i)\n" ;
    return COUT;
}

double magnitude(const comp& c) {
    return sqrt(c.real * c.real + c.img * c.img);
}


int main (){
    comp c1(4,5);
    comp c2(2,4);
    comp c3=c1+c2;
    comp c4=c1-c2;
    comp c5=c1*c2;
    comp c6=c1/c2;
    cout <<"C1 "<<c1<<endl;
    cout <<"C2 "<<c2<<endl;
    cout <<"Sum "<<c3<<endl;
    cout <<"Diff "<<c4<<endl;
    cout <<"Product "<<c5<<endl;
    cout <<"Quotient "<<c6<<endl;
    cout <<"Magnitude of c2: " << magnitude(c1) << endl;
    cout <<"Magnitude of c1: " << magnitude(c2) << endl;

}
