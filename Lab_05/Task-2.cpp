#include <iostream>
#include <cstring>
using namespace std;

class Student {
private:
    int id;
    char* name;
    int* scores;
    int numScores;

public:
    Student(int studentID, const char* studentName, const int* examScores, int scoreCount) : id(studentID),numScores(scoreCount) {
        name =new char[strlen(studentName)+1];
        strcpy(name,studentName);
        
        scores =new int[numScores];
        for(int i=0;i<numScores;i++) {
            scores[i]=examScores[i];
        }
    }

    Student(const Student& source) : id(source.id), numScores(source.numScores) {
        name = new char[strlen(source.name) + 1];
        strcpy(name, source.name);        
        scores=new int[numScores];
        for (int i=0;i<numScores;i++) {
            scores[i]=source.scores[i];
        }
    }

    void display() const {
        cout<<"Student ID: "<<id<<"\nName: "<<name<<"\nScores: ";
        for (int i = 0; i < numScores; i++) {
            cout<<scores[i]<<" ";
        }
        cout<<"\n\n";
    }

    ~Student() {
        delete[] name;
        delete[] scores;
    }
};

int main() {
    int scores1[]={92, 89, 84};
    Student student1(111, "Ali Asgher", scores1, 3);
    
    cout<<"Original Student Record:\n";
    student1.display();
    
    Student student2=student1;
    cout<<"Copied Student Record for Verification:\n";
    student2.display();
    
    return 0;
}
