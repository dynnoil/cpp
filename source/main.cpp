//
// Created by DynNoil on 14.08.2016.
//
#include <iostream>
#include "../headers/exercises.h"

using namespace std;

int factorial(int n);
int fibonacci(int n);
int foo1(int n);
void swap(int *a, int *b);
void printArray(int *m, unsigned size);

int main() {
    int m[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    rotateArray(m, 10, 5);
    printArray(m, 10);
    return 0;
}

void printArray(int *m, unsigned size) {
    for (int *p = m; p < m + size; p++) {
        cout << *p << " ";
    }
    cout << "\n";
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