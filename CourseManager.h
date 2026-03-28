#pragma once
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include "Student.h"
using namespace std;

class CourseManager {
private:
    map<int, Student> students;
public:
    void addStudent(Student s) {
        if (students.count(s.getId())) { cout << "ID already exists\n"; return; }
        students[s.getId()] = s;
        cout << "Student added successfully\n";
    }

    void removeStudent(int id) {
        if (!students.count(id)) { cout << "Student not found\n"; return; }
        students.erase(id);
        cout << "Student removed successfully\n";
    }

    Student* searchStudent(int id) {
        if (!students.count(id)) return nullptr;
        return &students[id];
    }

    void displayAll() {
        if (students.empty()) { cout << "No students\n"; return; }
        cout << left << setw(8) << "ID" << setw(20) << "Name" << "GPA\n";
        cout << string(34, '-') << "\n";
        for (auto& p : students) p.second.display();
    }

    void enrollInCourse(int id, string c) {
        if (!students.count(id)) { cout << "Student not found\n"; return; }
        if (students[id].addCourse(c)) cout << "Enrolled successfully\n";
        else cout << "Already enrolled\n";
    }

    void showCourses(int id) {
        if (!students.count(id)) { cout << "Student not found\n"; return; }
        cout << "Courses for " << students[id].getName() << ":\n";
        students[id].showCourses();
    }

    void sortByGpa() {
        if (students.empty()) { cout << "No students\n"; return; }
        vector<Student*> v;
        for (auto& p : students) v.push_back(&p.second);
        sort(v.begin(), v.end(), [](Student* a, Student* b) {
            return a->getGpa() > b->getGpa();
        });
        cout << left << setw(6) << "Rank" << setw(8) << "ID" << setw(20) << "Name" << "GPA\n";
        cout << string(40, '-') << "\n";
        int rank = 1;
        for (auto s : v)
            cout << setw(6) << rank++ << setw(8) << s->getId()
                 << setw(20) << s->getName()
                 << fixed << setprecision(2) << s->getGpa() << "\n";
    }

    void run() {
        int choice;
        cout << "=== Student Course Management System ===\n";
        while (true) {
            cout << "\n1.Add  2.Remove  3.Search  4.Display  5.Enroll  6.Courses  7.Sort  8.Exit\n";
            cout << "Choice: "; cin >> choice;
            if (choice == 8) { cout << "Goodbye!\n"; return; }
            int id; string name; double gpa; string course;
            switch (choice) {
                case 1:
                    cout << "Enter Student ID: "; cin >> id;
                    cin.ignore();
                    cout << "Enter Name: "; getline(cin, name);
                    cout << "Enter GPA: "; cin >> gpa;
                    if (gpa < 0 || gpa > 4) { cout << "Invalid GPA\n"; break; }
                    addStudent(Student(id, name, gpa));
                    break;
                case 2:
                    cout << "Enter Student ID: "; cin >> id;
                    removeStudent(id);
                    break;
                case 3:
                    cout << "Enter Student ID: "; cin >> id;
                    if (Student* s = searchStudent(id))
                        cout << "ID: " << s->getId() << " | Name: " << s->getName()
                             << " | GPA: " << s->getGpa() << "\n";
                    else cout << "Student not found\n";
                    break;
                case 4: displayAll(); break;
                case 5:
                    cout << "Enter Student ID: "; cin >> id;
                    cin.ignore();
                    cout << "Enter Course: "; getline(cin, course);
                    enrollInCourse(id, course);
                    break;
                case 6:
                    cout << "Enter Student ID: "; cin >> id;
                    showCourses(id);
                    break;
                case 7: sortByGpa(); break;
                default: cout << "Invalid choice\n";
            }
        }
    }
};
