//
// Created by DynNoil on 23.08.2016.
//

#ifndef FIRST_EXAMPLES_H
#define FIRST_EXAMPLES_H

class IntArray {
private:
    size_t size;
    int *data;

public:
    IntArray() {
        size = 0;
        data = new int[size];
    }

    explicit IntArray(size_t size) :
            size(size),
            data(new int[size]) {};

    ~IntArray() {
        delete[] data;
    }

    size_t getSize() {
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
