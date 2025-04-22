// LabCourse.h
#ifndef LABCOURSE_H
#define LABCOURSE_H

#include "Course.h"

class LabCourse : public Course {
private:
    double projectScore;
    double labWorkScore;

public:
    LabCourse(string code, int cred, double project, double labWork);
    void displayInfo() override;
    double calculateGrade() override;
};

#endif
