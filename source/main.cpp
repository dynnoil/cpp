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
bool contains(int *first, int *afterLast, int value);
int* getMaxElement(int *first, int *afterLast);
bool max_elem(int *p, int *q, int **res);

int main() {
    int m[10] = {1, 2, 3, 4, 5, 6, 7, 80, 9, 0};
    cout << *getMaxElement(m, m + 10) << endl;
    int *pMax = 0;
    max_elem(m, m + 10, &pMax);
    char str[] = "abcsabcdd";
    char str2[] = "abcdd";
    cout << strstr(str, str2);
    return 0;
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