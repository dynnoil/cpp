//
// Exercises and tasks from C++ course by Stepic.org
//
// Created by DynNoil on 15.08.2016.
//
#include <iostream>

unsigned gcd(unsigned a, unsigned b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int reverseNumbersWithRecursion() {
    unsigned a;
    std::cin >> a;
    if (a != 0) {
        reverseNumbersWithRecursion();
        std::cout << a << " ";
    }
    return 0;
}

void rotateArray(int *m, unsigned size, int shift) {
    for (int i = 0; i < shift; i++) {
        int *first = m;
        int *last = &m[size - 1];
        int tempFirst = *first;
        for (int j = 0; j < size; j++) {
            m[j] = m[j + 1];
        }
        *last = tempFirst;
    }
}

