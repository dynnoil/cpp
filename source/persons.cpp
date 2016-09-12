//
// Created by DynNoil on 03.09.2016.
//
#include <string>
#include "../headers/persons.h"

using namespace std;

MyPerson::MyPerson(string const &name, unsigned age)
        : name_(name), age_(age)
{}

MyPerson::~MyPerson() {}

string MyPerson::name() const {
    return name_;
}

Teacher::Teacher(string const &nm, unsigned age, string const &course)
        : MyPerson(nm, age), course_(course)
{}

string Teacher::occupation() const {
    return "teacher";
}

string Teacher::course() const {
    return course_;
}

Professor::Professor(string const &name, unsigned age, string const &course, string const &thesis)
        : Teacher(name, age, course), thesis_(thesis)
{}

string Professor::thesis() const {
    return thesis_;
}

string Professor::name() const {
    return "Prof. " + MyPerson::name();
}

string Professor::occupation() const {
    return "professor";
}