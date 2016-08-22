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

unsigned getStringLength(const char *str) {
    unsigned length = 0;
    while (*str++ != '\0') {
        length++;
    }
    return length;
}

void strcat(char *to, const char *from) {
    while (*to++ != '\0');
    to--;
    while (*from != '\0') {
        *to++ = *from;
        from++;
    }
    *to = '\0';
}

int strstr(const char *text, const char *pattern) {
    unsigned patternLength = getStringLength(pattern);
    unsigned position = 0;
    unsigned firstEntryPosition = 0;
    unsigned caught = 0;
    while (*text != '\0') {
        if (caught == 1) {
            firstEntryPosition = position - 1;
        }
        if (patternLength == caught) {
            return firstEntryPosition;
        }
        while (*pattern != '\0') {
            if (*text == *pattern) {
                caught++;
            } else {
                for (int i = 0; i < caught; i++) {
                    pattern--;
                }
                caught = 0;
                break;
            }
            pattern++;
            break;
        }
        text++;
        position++;
    }
    return -1;
}