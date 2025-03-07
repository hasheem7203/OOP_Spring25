#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string name, int age) : name(name), age(age) {}
    
    virtual void showDetails() {
        cout<<"Name: "<< name << endl;
        cout<<"Age: "<<age<<" years"<< endl;
    }
};

class Teacher : virtual public Person {
protected:
    string subject;

public:
    Teacher(string name, int age, string subject) : Person(name, age), subject(subject) {}
    
    void showDetails() override {
        Person::showDetails();
        cout<<"Subject: "<<subject<< endl;
    }
};

class Researcher : virtual public Person {
protected:
    string researchArea;

public:
    Researcher(string name, int age, string researchArea) : Person(name, age), researchArea(researchArea) {}
    
    void showDetails() override {
        Person::showDetails();
        cout<<"Research Field: "<<researchArea<< endl;
    }
};

class Professor : public Teacher, public Researcher {
private:
    int publications;

public:
    Professor(string name, int age, string subject, string researchArea, int publications)
        : Person(name, age), Teacher(name, age, subject), Researcher(name, age, researchArea), publications(publications) {}
    
    void showDetails() override {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << " years" << endl;
        cout << "Subject: " << subject << endl;
        cout << "Publications: " << publications << endl;
    }
};

int main() {
    string name, subject, researchField;
    int age, publications;

    cout << "Enter professor's name: ";
    getline(cin, name);
    cout << "Enter age: ";
    cin >> age;
    cin.ignore();
    cout << "Enter subject specialization: ";
    getline(cin, subject);
    cout << "Enter research field: ";
    getline(cin, researchField);
    cout << "Enter number of publications: ";
    cin >> publications;

    Professor p1(name, age, subject, researchField, publications);
    
    p1.showDetails();

}
