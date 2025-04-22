// LabCourse.cpp
#include "LabCourse.h"
#include <iostream>

using namespace std;

LabCourse::LabCourse(string code, int cred, double project, double labWork)
    : Course(code, cred), projectScore(project), labWorkScore(labWork) {}

void LabCourse::displayInfo() {
    cout << "Lab Course: " << courseCode << " | Credits: " << credits << endl;
}

double LabCourse::calculateGrade() {
    return (projectScore * 0.5) + (labWorkScore * 0.5);
}
