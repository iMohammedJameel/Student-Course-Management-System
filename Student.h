#pragma once
#include <iostream>
#include <set>
#include <iomanip>
using namespace std;

class Person {
protected:
    string name;
public:
    Person(string n = "") : name(n) {}
    string getName() { return name; }
    void setName(string n) { name = n; }
    virtual void display() { cout << name << "\n"; }
};

class Student : public Person {
private:
    int id;
    double gpa;
    set<string> courses;
public:
    Student(int i = 0, string n = "", double g = 0) : Person(n), id(i), gpa(g) {}

    int getId() { return id; }
    double getGpa() { return gpa; }

    bool addCourse(string c) { return courses.insert(c).second; }

    void showCourses() {
        if (courses.empty()) { cout << "  No courses\n"; return; }
        for (string c : courses) cout << "  - " << c << "\n";
    }

    void display() {
        cout << left << setw(8) << id << setw(20) << name
             << fixed << setprecision(2) << gpa << "\n";
    }
};
