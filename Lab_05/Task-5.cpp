#include <iostream>
#include <string>
using namespace std;

const int MAX_DOCTORS = 20;

class Doctor {
public:
    string name;
    string specialization;
    int experience;

    Doctor(string docName, string docSpecialization, int docExperience)
        : name(docName), specialization(docSpecialization), experience(docExperience) {}
};

class Hospital {
private:
    string hospitalName;
    Doctor* doctors[MAX_DOCTORS];
    int doctorCount;

public:
    Hospital(string name) : hospitalName(name), doctorCount(0) {}

    void assignDoctor(Doctor* doc) {
        if (doctorCount < MAX_DOCTORS) {
            doctors[doctorCount++] = doc;
        } else {
            cout<<"Maximum doctor capacity reached for "<<hospitalName<<"!\n";
        }
    }

    void showHospitalInfo() const {
        cout<<"\nHospital Name: "<< hospitalName<<"\nCurrently Assigned Doctors:\n";
        if (doctorCount == 0) {
            cout << "No doctors assigned yet.\n";
        } else {
            for (int i=0;i<doctorCount; i++) {
                cout <<"- "<<doctors[i]->name<<" | Specialization: "<<doctors[i]->specialization <<" | Experience: "<<doctors[i]->experience<<" years\n";
            }
        }
    }
};

int main() {
    Doctor doc1("Dr. Ahmed Khan", "psychiatrist", 22);
    Doctor doc2("Dr. Saima Malik", "Neurology", 12);
    Doctor doc3("Dr. Bilal Hussain", "Orthopedics", 9);

    Hospital hospitalA("Jinnah Medical Complex");
    Hospital hospitalB("Liaquat National Hospital");

    hospitalA.assignDoctor(&doc1);
    hospitalA.assignDoctor(&doc2);
    hospitalB.assignDoctor(&doc3);
    hospitalB.assignDoctor(&doc1);

    cout << "\nHospital Database:\n";
    hospitalA.showHospitalInfo();
    hospitalB.showHospitalInfo();
    
    return 0;
}
