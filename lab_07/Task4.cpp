#include "iostream"
using namespace std ;

#define max 10
class person {
    protected:
        string name ;
        int age ;
        string contactNumber;
        string address;

    public:
        person(string name ,int age ,string number,string address="No Record ")
        :name(name),age(age),contactNumber(number),address(address){}

        virtual void displayInfo(){
            cout <<"Name : "<<name<<endl;
            cout <<"Age : "<<age << endl;
            cout <<"Contact Number : "<<contactNumber<<endl;
            cout << "Address : "<<address<<endl;
        }

        virtual void updateInfo(string name ,int age ,string number,string address){
            this->name=name;
            this->age=age;
            this->contactNumber=number;
            this->address=address;
        }

};

class patient : public person{
    private:
        int patientID;
        string medicalHistory;
        string doctorAssigned;


    public:
        patient(string name ,int age ,string number,string address,int patientID,string medHistory,string doctorAssigned):
        person(name,age,number,address),patientID(patientID),medicalHistory(medHistory),doctorAssigned(doctorAssigned){}

        void displayInfo() override{
            cout << "PATIENT INFO :"<<endl;
            person::displayInfo();
            cout <<"Patient ID : "<<patientID<<endl;
            cout << "Medical History : "<<medicalHistory<<endl;
            cout << "Doctor Assigned : "<<doctorAssigned<<endl;
        }
};


class doctor : public person{
    private:
        string specialization;
        int fee;
        string patients[max];
        int patientCount;

    public:
        doctor(string name ,int age ,string number,string address,string specialization,int fee)
        :person(name,age,number,address),specialization(specialization),fee(fee),patientCount(0){}

        void addPatient(string patientName){
            if(patientCount<10){
                patients[patientCount++]=patientName;
            }else{
                cout <<"Maximum Patient Reached "<<endl;
            }
        }

        void displayInfo()override{
            person::displayInfo();
            cout << "Specialization: " << specialization << "\nConsultation Fee: Rs" << fee << "\nPatients: ";
            for (int i = 0; i < patientCount; i++) {
                cout << patients[i] << (i < patientCount - 1 ? ", " : "");
            }
            cout << endl;   
        }
};


class nurse : public person{
    private:
        string assignedWards;
        string shiftTimings;

    public:
        nurse(string name ,int age ,string number,string address,string assignedWards,string shiftTimings)
        :person(name,age,number,address),assignedWards(assignedWards),shiftTimings(shiftTimings){}

        void displayInfo() override{
            cout <<"Nurse Details : "<<endl;
            person::displayInfo();
            cout <<"Assigned Wards : "<<assignedWards<<endl;
            cout<<"Shift Times : "<<shiftTimings<<endl;
        }
};



class administrator : public person{
    private:
        string department ;
        int salary;

    public:
        administrator(string name ,int age ,string number,string address,string department ,int salary)
        :person(name,age,number,address),department(department),salary(salary){}


        void updateInfo(string name, int age, string number, string address) override {
            person::updateInfo(name, age, number, address);
        }
    
        void updateAdminInfo(string name, int age, string number, string address, string department, int salary) {
            updateInfo(name, age, number, address);
            this->department = department;
            this->salary = salary;
        }
        void displayInfo() override {
            cout << "ADMINISTRATOR INFO:" << endl;
            person::displayInfo();
            cout << "Department: " << department << endl;
            cout << "Salary: Rs" << salary << endl;
        }
};

int main(){
    patient p1("M.Hasheem Shuja",15,"03212576920","L1-67,block-B",10001,"No History","Dr.Ahmed");
    doctor d1("Dr. Ahmed", 45, "987654321", "Karachi", "Cardiologist", 5000);
    nurse n1("Ayesha", 28, "456789123", "Islamabad", "ICU", "Night Shift");
    administrator a1("Zeeshan", 50, "159357456", "Multan", "HR", 75000);

    cout << "\n--- Displaying Information ---\n";
    p1.displayInfo();
    cout <<endl;
    d1.addPatient("Hasheem");
    d1.displayInfo();
    cout << endl;
    n1.displayInfo();
    cout << endl;
    a1.displayInfo();

    return 0;
}
