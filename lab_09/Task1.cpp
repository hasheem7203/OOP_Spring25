#include <iostream>
#include <string>

using namespace std;


class Patient {
protected:
    string name;
    string id;

public:

    Patient(string patientName, string patientId) : name(patientName), id(patientId) {}


    virtual void displayTreatment() = 0;
    virtual double calculateCost() = 0;

    string getName() const { return name; }
    string getId() const { return id; }
};


class InPatient : public Patient {
private:
    double roomCost;
    double procedureCost;

public:

    InPatient(string patientName, string patientId, double room, double procedure)
        : Patient(patientName, patientId), roomCost(room), procedureCost(procedure) {}


    void displayTreatment() override {
        cout <<"Patient Name (Inpatient): "<<name<<endl;
        cout <<"Patient Id : "<<id<<endl;
        cout <<"Room Cost : "<<roomCost<<endl;
        cout <<"Procedure ost : "<<procedureCost<<endl;
    }


    double calculateCost() override {
        return roomCost + procedureCost;
    }
};

class OutPatient : public Patient {
private:
    double consultationFee;
    double procedureCost;

public:

    OutPatient(string patientName, string patientId, double consultation, double procedure)
        : Patient(patientName, patientId), consultationFee(consultation), procedureCost(procedure) {}

    void displayTreatment() override {
        cout <<"Patient Name (Outpatient): "<<name<<endl;
        cout <<"Patient Id : "<<id<<endl;
        cout <<"Consultation Fee : "<<consultationFee<<endl;
        cout <<"Procedure Cost : "<<procedureCost<<endl;
    }


    double calculateCost() override {
        return consultationFee + procedureCost;
    }
};

int main() {

    InPatient inPatient1("Ali Asgher", "IP001", 200, 1500);
    OutPatient outPatient1("Mustafa Kamal", "OP001", 100, 500);


    Patient* patient1 = &inPatient1;
    patient1->displayTreatment();
    cout << "Total cost: Rs" << patient1->calculateCost() << "\n\n";

    Patient* patient2 = &outPatient1;
    patient2->displayTreatment();
    cout << "Total cost: Rs" << patient2->calculateCost() << endl;

    return 0;
}
