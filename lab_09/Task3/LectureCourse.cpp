// LectureCourse.cpp
#include "LectureCourse.h"
#include <iostream>

using namespace std;

LectureCourse::LectureCourse(string code, int cred, double midterm, double finalExam)
    : Course(code, cred), midtermScore(midterm), finalExamScore(finalExam) {}

void LectureCourse::displayInfo() {
    cout << "Lecture Course: " << courseCode << " | Credits: " << credits << endl;
}

double LectureCourse::calculateGrade() {
    return (midtermScore * 0.4) + (finalExamScore * 0.6);
}
