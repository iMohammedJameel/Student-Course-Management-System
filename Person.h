#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
protected:
    string name;

public:
    Person(string n = "") : name(n) {}
    virtual ~Person() {}

    string getName() { return name; }

    virtual void display() = 0;
};

#endif
