//
// Created by DynNoil on 23.08.2016.
//

#ifndef FIRST_EXAMPLES_H
#define FIRST_EXAMPLES_H
#include <algorithm>
#include <string>
using namespace std;

class ICloneable {
public:
    virtual ~ICloneable() {}
    virtual ICloneable* clone() = 0;
};

class Employee {
public:
    virtual string occupation() const = 0;
    virtual ~Employee() {}
};

class Manager : public Employee {
    string name_;
    string occupation_;

public:
    Manager(string name, string occupation) :
            name_(name), occupation_(occupation)
    {}

    string occupation() const {
        return occupation_;
    }

};

class Coder : public Employee {
    string name_;
    string occupation_;

public:
    Coder(string name, string occupation) :
            name_(name), occupation_(occupation)
    {}

    string occupation() const {
        return occupation_;
    }
};

struct File {
    void write(const char *s);
};

struct FormattedFile : File {
    using File::write;
    void write(int i);
    void write(double d);
};

class Person : ICloneable {
    string name;
    unsigned age;
public:
    Person(string name, unsigned age) :
            name(name),
            age(age)
    {}
    Person* clone() {
        return new Person(*this);
    }
};

class Student : Person {
    string university;
public:
    Student(string name, unsigned age, string university):
            Person(name, age), university(university)
    {}

};

class IntArray {
private:
    size_t size;
    int *data;

public:
    explicit IntArray(size_t size) :
            size(size),
            data(new int[size])
    {
        for (size_t i = 0; i < size; i++) {
            data[i] = 0;
        }
    };

    // Конструктор копирования вызывается при копировании объекта:
    // - при создании нового объекта путем копирования
    // - при передаче объекта в функции по значению
    IntArray(IntArray const &array) :
            size(array.size),
            data(new int[size])
    {
        for (size_t i = 0; i < size; i++) {
            data[i] = array.data[i];
        }
    }

    ~IntArray() {
        delete[] data;
    }

    IntArray &operator=(IntArray const &array) {
        if (this != &array) {
            IntArray(array).swap(*this);
        }
        return *this;
    }

    void swap(IntArray &array) {
        std::swap(size, array.size);
        std::swap(data, array.data);
    }

    size_t getSize() const {
        return this->size;
    }

    int get(size_t i) const {
        return this->data[i];
    }

    int &get(size_t i) {
        return this->data[i];
    }

    void resize(size_t newSize) {
        int *newData = new int[newSize];
        size_t n = newSize > size ? size : newSize;
        for (size_t i = 0; i < n; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        size = newSize;
    }
};

struct Point {
    double x;
    double y;

    explicit Point(double x = 0, double y = 0)
            : x(x), y(y) {};

    void shift(double x, double y);
};

struct Segment {
    Point start;
    Point end;

    //Синтаксис списков инициализации
    Segment() : start(Point()), end(Point()) {};

    Segment(Point start, Point end) : start(start), end(end) {};
};

struct IntArray2d {
    size_t rows;
    size_t cols;
    int **data;
};

double length_segment(Segment &segment);

int **create_array2d_effective(size_t a, size_t b);

void free_array2d_effective(int **m);

void free_array2d(int **m, size_t a);

int **create_array2d(size_t a, size_t b);

void dynamic_memory_CPP_Style();

void dynamic_memory_C_Style();

int factorial(int n);

int fibonacci(int n);

int foo1(int n);

void swap(int *a, int *b);

void swap_refference(int &a, int &b);

void printArray(int *m, unsigned size);

bool contains(int *first, int *afterLast, int value);

int *getMaxElement(int *first, int *afterLast);

bool max_elem(int *p, int *q, int **res);

#endif //FIRST_EXAMPLES_H
