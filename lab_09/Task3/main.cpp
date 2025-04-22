// main.cpp
#include <iostream>
#include "LectureCourse.h"
#include "LabCourse.h"

using namespace std;

int main() {
    LectureCourse lec("CS101", 3, 75.0, 85.0);
    LabCourse lab("CS101L", 1, 80.0, 90.0);


    Course* course1 = &lec;
    Course* course2 = &lab;

    course1->displayInfo();
    cout << "Final Grade: " << course1->calculateGrade() << "%" << endl << endl;

    course2->displayInfo();
    cout << "Final Grade: " << course2->calculateGrade() << "%" << endl;

    return 0;
}
