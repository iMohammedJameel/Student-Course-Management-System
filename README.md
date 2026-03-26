# Student Course Management System

A C++ console application that manages students and their enrolled courses, built using Object-Oriented Programming (OOP) principles and the Standard Template Library (STL).

---

## 📋 Project Info

| Field | Details |
|-------|---------|
| **Student** | Mohammed Jameel Fouad |
| **Course** | Foundations of Software Development |
| **Assignment** | Individual Assignment |

---

## 🚀 Features

- Add a student (unique ID, name, GPA validated 0.0–4.0)
- Remove a student by ID
- Search for a student by ID
- Display all students in a formatted table
- Enroll a student in a course (no duplicate courses)
- Show all courses for a student
- Sort all students by GPA (descending) with high-achiever count

---

## 🗂️ Project Structure

```
Student-Course-Management-System/
├── main.cpp        # Main program and menu logic
├── Person.h        # Abstract base class Person
├── Student.h       # Student class declaration
├── Student.cpp     # Student class implementation
└── README.md
```

---

## ⚙️ Requirements

| Tool | Version |
|------|---------|
| C++ Compiler | g++ / MSVC / clang++ |
| C++ Standard | C++17 or later |
| OS | Windows / Linux / macOS |

---

## 🔧 How to Compile and Run

### Linux / macOS

```bash
g++ -std=c++17 -Wall -o scms main.cpp Student.cpp
./scms
```

### Windows (Command Prompt)

```cmd
g++ -std=c++17 -Wall -o scms.exe main.cpp Student.cpp
scms.exe
```

### Windows (Visual Studio)

1. Open Visual Studio → Create new **Empty C++ Project**
2. Add all `.cpp` and `.h` files to the project
3. Set C++ Standard to **C++17** in Project Properties
4. Press **Ctrl+F5** to build and run

---

## 📖 Usage

Once the program runs, a menu appears:

```
=== Student Management System ===

1.Add  2.Remove  3.Search  4.Display  5.Enroll  6.Courses  7.Sort  8.Exit
Choice:
```

### Example Session

```
Choice: 1
Enter ID: 1001
Enter Name: Ali Ahmed
Enter GPA (0.0 - 4.0): 3.5
Student added successfully

Choice: 5
Enter ID: 1001
Enter Course: Data Structures
Enrolled successfully

Choice: 7
Rank  ID    Name           GPA
1     1001  Ali Ahmed      3.50
Students with GPA >= 3.0: 1
```

---

## 🧱 OOP Concepts Used

| Concept | Where |
|---------|-------|
| **Encapsulation** | Private members in `Student` class |
| **Inheritance** | `Student` extends abstract `Person` |
| **Polymorphism** | `display()` overridden in `Student` |
| **Abstraction** | Pure virtual `display()` in `Person` |

---

## 📦 STL Used

| Container / Algorithm | Purpose |
|-----------------------|---------|
| `map<int, Student>` | Student registry — O(log n) lookup by ID |
| `set<string>` | Course list per student — no duplicates |
| `vector<Student*>` | Temporary list for sorting |
| `sort()` | Sort students by GPA descending |
| `count_if()` | Count high achievers (GPA ≥ 3.0) |

---

## ✅ Input Validation

- Student ID must be a unique integer
- GPA must be between **0.0 and 4.0**
- Course name cannot be empty
- Duplicate courses are automatically rejected
- Non-numeric input is handled without crashing

---

## 📄 License

This project is submitted as an academic assignment. All code was written independently.
