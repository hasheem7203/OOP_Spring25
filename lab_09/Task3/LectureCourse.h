// LectureCourse.h
#ifndef LECTURECOURSE_H
#define LECTURECOURSE_H

#include "Course.h"

class LectureCourse : public Course {
private:
    double midtermScore;
    double finalExamScore;

public:
    LectureCourse(string code, int cred, double midterm, double finalExam);
    void displayInfo() override;
    double calculateGrade() override;
};

#endif
