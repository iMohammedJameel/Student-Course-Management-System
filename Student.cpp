#include "Student.h"

Student::Student() : id(0), gpa(0.0) {}

Student::Student(int i, string n, double g) : Person(n), id(i), gpa(g) {}

bool Student::addCourse(string c) {
    return courses.insert(c).second;
}

void Student::display() {
    cout << left << setw(8) << id
         << setw(20) << name
         << fixed << setprecision(2) << gpa << "\n";
}

void Student::showCourses() {
    if (courses.empty()) {
        cout << "  No courses enrolled\n";
        return;
    }
    int i = 1;
    for (auto& c : courses)
        cout << "  " << i++ << ". " << c << "\n";
}
