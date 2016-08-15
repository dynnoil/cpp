//
// Created by DynNoil on 14.08.2016.
//
#include "../headers/stack.h"
#include <iostream>
using namespace std;

int factorial(int n);
int fibonacci(int n);
int foo1(int n);

int main() {
    cout << foo1(3);
    return 0;
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