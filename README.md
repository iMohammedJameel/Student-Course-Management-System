# Student Course Management System

A C++ console application to manage students and their course enrollments.

## Author
Mohammed Jameel

---

## Files
```
├── main.cpp          → Entry point
├── Student.h         → Person & Student classes
└── CourseManager.h   → Main logic & menu
```

---

## Classes

### Person
Base class that holds the student's name.

### Student (inherits Person)
| Field | Type | Description |
|-------|------|-------------|
| id | int | Unique student ID |
| gpa | double | GPA (0.0 - 4.0) |
| courses | set\<string\> | Enrolled courses |

### CourseManager
Manages all students using a `map<int, Student>`.

---

## Menu Options

| Option | Description |
|--------|-------------|
| 1 | Add a new student |
| 2 | Remove a student by ID |
| 3 | Search for a student by ID |
| 4 | Display all students |
| 5 | Enroll a student in a course |
| 6 | Show courses of a student |
| 7 | Sort and display students by GPA |
| 8 | Exit |

---

## How to Run

```bash
g++ main.cpp -o app
./app
```

---

## Example Output

```
=== Student Course Management System ===

1.Add  2.Remove  3.Search  4.Display  5.Enroll  6.Courses  7.Sort  8.Exit
Choice: 7

Rank  ID      Name                GPA
----------------------------------------
1     1002    Sara Mohamed        3.90
2     1004    Nour Ahmed          3.70
3     1001    Ahmed Ali           3.50
```
