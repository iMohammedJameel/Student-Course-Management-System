// Student Management System
// Mohammed Jameel

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>
#include "Student.h"

using namespace std;

map<int, Student> students;

// -------------------------------------------------------
void addStudent() {
    int id;
    string name;
    double gpa;

    cout << "Enter ID: ";
    if (!(cin >> id)) {
        cout << "Invalid input\n";
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }

    if (students.count(id)) {
        cout << "ID already exists\n";
        return;
    }

    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter GPA (0.0 - 4.0): ";
    if (!(cin >> gpa) || gpa < 0.0 || gpa > 4.0) {
        cout << "Invalid GPA\n";
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }

    students[id] = Student(id, name, gpa);
    cout << "Student added successfully\n";
}

// -------------------------------------------------------
void removeStudent() {
    int id;
    cout << "Enter ID: ";
    if (!(cin >> id)) {
        cin.clear(); cin.ignore(1000, '\n');
        cout << "Invalid input\n";
        return;
    }

    if (!students.count(id)) {
        cout << "Student not found\n";
        return;
    }

    students.erase(id);
    cout << "Student removed\n";
}

// -------------------------------------------------------
void searchStudent() {
    int id;
    cout << "Enter ID: ";
    if (!(cin >> id)) {
        cin.clear(); cin.ignore(1000, '\n');
        cout << "Invalid input\n";
        return;
    }

    if (!students.count(id)) {
        cout << "Student not found\n";
        return;
    }

    Student& s = students[id];
    cout << "\nID   : " << s.getId()   << "\n";
    cout << "Name : " << s.getName() << "\n";
    cout << "GPA  : " << fixed << setprecision(2) << s.getGpa() << "\n";
    cout << "Courses:\n";
    s.showCourses();
}

// -------------------------------------------------------
void displayAll() {
    if (students.empty()) {
        cout << "No students found\n";
        return;
    }

    cout << "\n" << left << setw(8) << "ID" << setw(20) << "Name" << "GPA\n";
    cout << string(34, '-') << "\n";

    for (auto& p : students)
        p.second.display();
}

// -------------------------------------------------------
void enrollCourse() {
    int id;
    string course;

    cout << "Enter ID: ";
    if (!(cin >> id)) {
        cin.clear(); cin.ignore(1000, '\n');
        cout << "Invalid input\n";
        return;
    }

    if (!students.count(id)) {
        cout << "Student not found\n";
        return;
    }

    cin.ignore();
    cout << "Enter Course: ";
    getline(cin, course);

    if (course.empty()) {
        cout << "Course name cannot be empty\n";
        return;
    }

    if (students[id].addCourse(course))
        cout << "Enrolled successfully\n";
    else
        cout << "Already enrolled in this course\n";
}

// -------------------------------------------------------
void showCourses() {
    int id;
    cout << "Enter ID: ";
    if (!(cin >> id)) {
        cin.clear(); cin.ignore(1000, '\n');
        cout << "Invalid input\n";
        return;
    }

    if (!students.count(id)) {
        cout << "Student not found\n";
        return;
    }

    cout << "Courses for " << students[id].getName() << ":\n";
    students[id].showCourses();
}

// -------------------------------------------------------
void sortByGpa() {
    if (students.empty()) {
        cout << "No students found\n";
        return;
    }

    vector<Student*> v;
    for (auto& p : students)
        v.push_back(&p.second);

    sort(v.begin(), v.end(), [](Student* a, Student* b) {
        return a->getGpa() > b->getGpa();
    });

    cout << "\n" << left << setw(6) << "Rank" << setw(8) << "ID"
         << setw(20) << "Name" << "GPA\n";
    cout << string(40, '-') << "\n";

    int rank = 1;
    for (auto s : v)
        cout << setw(6) << rank++ << setw(8) << s->getId()
             << setw(20) << s->getName()
             << fixed << setprecision(2) << s->getGpa() << "\n";

    int good = count_if(v.begin(), v.end(), [](Student* s) {
        return s->getGpa() >= 3.0;
    });
    cout << "\nStudents with GPA >= 3.0: " << good << "\n";
}

// -------------------------------------------------------
int main() {
    int choice;
    cout << "=== Student Management System ===\n";

    while (true) {
        cout << "\n1.Add  2.Remove  3.Search  4.Display  "
             << "5.Enroll  6.Courses  7.Sort  8.Exit\n";
        cout << "Choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid choice\n";
            continue;
        }

        switch (choice) {
            case 1: addStudent();    break;
            case 2: removeStudent(); break;
            case 3: searchStudent(); break;
            case 4: displayAll();    break;
            case 5: enrollCourse();  break;
            case 6: showCourses();   break;
            case 7: sortByGpa();     break;
            case 8: cout << "Goodbye!\n"; return 0;
            default: cout << "Invalid choice\n";
        }
    }
}
