#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <set>
#include <iostream>
#include <iomanip>
using namespace std;

class Student : public Person {
    int    id;
    double gpa;
    set<string> courses;   // set = no duplicates automatically

public:
    Student();
    Student(int i, string n, double g);

    int    getId()  { return id;  }
    double getGpa() { return gpa; }

    bool addCourse(string c);
    void display() override;
    void showCourses();
};

#endif
