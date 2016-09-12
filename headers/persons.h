//
// Created by DynNoil on 03.09.2016.
//

#ifndef FIRST_PERSONS_H
#define FIRST_PERSONS_H

#include <string>
using namespace std;

class MyPerson {
    string name_;
    unsigned age_;
public:
    MyPerson(string const &name, unsigned age);
    virtual ~MyPerson();
    virtual string name() const;
    virtual string occupation() const = 0;
};

class Teacher : public MyPerson {
    string course_;
public:
    Teacher(string const &nm, unsigned age, string const &course);
    virtual string occupation() const;
    virtual string course() const;
};

class Professor : public Teacher {
    string thesis_;
public:
    Professor(string const &name, unsigned age, string const &course, string const &thesis);
    virtual string thesis() const;
    virtual string name() const;
    virtual string occupation() const;
};

#endif //FIRST_PERSONS_H
