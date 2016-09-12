//
// Created by DynNoil on 23.08.2016.
//
#include <iostream>
#include <cmath>
#include <malloc.h>
#include "../headers/examples.h"

void FormattedFile::write(int i) {
    std::cout << "write of FormattedFile\n";
}

void FormattedFile::write(double d) {
    std::cout << "write of FormattedFile\n";
}

void File::write(const char *s) {
    std::cout << "write of File\n";
}

void const_examples() {
    int a = 100;
    int b = 200;
    const int *p = &a; //указатель на константу
    //*p = 100; ошибка
    p = &b; // OK
    int * const p2 = &a; //константный указатель
    // p2 = &b; ошибка
    *p2 = b; // OK
    const int * const p3 = &a; //константный указатель на константу
    // p3 = 0; ошибка
    // p3 = &b; ошибка
}

void struct_examples() {
    IntArray2d intArray2d = {5, 4, create_array2d_effective(5, 4)};
    Point p1;
    Point p2(2, 3);
    // неявное преобразование конструктора от одного параметра можно
    // запретить с помощью ключевого слова explicit
    // Point p3 = 30;
    Segment segment(p1, p2);
    std::cout << segment.start.x << " " << segment.end.x;
}

void Point::shift(double x, double y) {
    this->x += x;
    this->y +=y;
}

double length_segment(Segment &segment) {
    double dx = segment.start.x - segment.end.x;
    double dy = segment.start.y - segment.end.y;
    return std::sqrt(dx * dx + dy * dy);
}

int **create_array2d_effective(size_t a, size_t b) {
    int **m = new int *[a];
    m[0] = new int [a * b];
    for (size_t i = 1; i < a; i++) {
        m[i] = m[i - 1] + b;
    }
    return m;
}

void free_array2d_effective(int **m) {
    delete [] m[0];
    delete [] m;
}

int **create_array2d(size_t a, size_t b) {
    int **m = new int *[a];
    for (size_t i = 0; i < a; i++) {
        m[i] = new int [b];
    }
    return m;
}

void free_array2d(int **m, size_t a) {
    for (size_t i = 0; i < a; i++) {
        delete [] m[i];
    }
    delete [] m;
}

void dynamic_memory_CPP_Style() {
    int *a = new int(5);
    delete a;

    int *b = new int[10];
    delete [] b;
}

void dynamic_memory_C_Style() {
    //выделение памяти под 1000 элементов типа int
    int *m = (int *) malloc(1000 * sizeof(int));
    //расширение памяти
    m = (int *) realloc(m, 2000 * sizeof(int));
    //освобождение памяти
    free(m);
    //выделение памяти под массив из 100 элементов типа int, заполненного нулями
    m = (int *) calloc(100, sizeof(int));
    free(m);
    m = 0;
}

void swap_refference(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

bool max_elem(int *p, int *q, int **res) {
    if (p == q) {
        return false;
    }
    *res = p;
    for(; p != q; p++) {
        if (*p > **res) {
            *res = p;
        }
    }
    return true;
}

int* getMaxElement(int *first, int *afterLast) {
    int *max = first;
    for (; first != afterLast; first++) {
        if (*first > *max) {
            *max = *first;
        }
    }
    return max;
}

bool contains(int *first, int *afterLast, int value) {
    for (; first != afterLast; first++) {
        if (*first == value) {
            return true;
        }
    }
    return false;
}

void printArray(int *m, unsigned size) {
    for (int *p = m; p < m + size; p++) {
        std::cout << *p << " ";
    }
    std::cout << "\n";
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return factorial(n - 1) * n;
}

int fibonacci(int n) {
    if (n < 2) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int foo1(int n) {
    if (n <= 0)
        return 1;
    return foo1((n * 2) / 3) + foo1(n - 2);
}
