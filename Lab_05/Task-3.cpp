#include <iostream>
#include <string>
using namespace std;

const int MAX_EMPLOYEES=10;

class Employee {
public:
    string name;
    string designation;

    Employee(string empName,string empDesignation)
        : name(move(empName)), designation(move(empDesignation)) {}
};

class Project {
private:
    string title;
    string deadline;
    Employee* team[MAX_EMPLOYEES];
    int teamSize;

public:
    Project(string projTitle, string projDeadline)
        : title(move(projTitle)), deadline(move(projDeadline)), teamSize(0) {}

    void addEmployee(Employee* emp) {
        if (teamSize<MAX_EMPLOYEES) {
            team[teamSize++] = emp;
        } else {
            cout<<"Project "<<title<<" has reached the employee limit.\n";
        }
    }

    void display() const {
        cout << "\nProject: " << title << "\nDeadline: " << deadline << "\nTeam Members:\n";
        for (int i = 0; i < teamSize; i++) {
            cout << "- " << team[i]->name << " (" << team[i]->designation << ")\n";
        }
    }
};

int main() {
    Employee emp1("Hasheem shuja", "Software Engineer");
    Employee emp2("Mustafa Ismaol", "Project Manager");
    Employee emp3("Ali Asgher", "UI/UX Designer");

    Project proj1("AI Development", "28-10-2025");
    Project proj2("Mobile App Redesign", "11-02-2025");

    proj1.addEmployee(&emp1);
    proj1.addEmployee(&emp2);
    proj2.addEmployee(&emp1);
    proj2.addEmployee(&emp3);

    cout << "Company Projects:\n";
    proj1.display();
    proj2.display();
    
    return 0;
}
