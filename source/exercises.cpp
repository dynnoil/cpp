//
// Exercises and tasks from C++ course by Stepic.org
//
// Created by DynNoil on 15.08.2016.
//
#include <iostream>
#include "../headers/exercises.h"

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

void my_strcat(char *to, const char *from) {
    while (*to++ != '\0');
    to--;
    while (*from != '\0') {
        *to++ = *from;
        from++;
    }
    *to = '\0';
}

int my_strstr(const char *text, const char *pattern) {
    unsigned patternLength = getStringLength(pattern);
    unsigned position = 0;
    unsigned firstEntryPosition = 0;
    unsigned caught = 0;
    while (*text != '\0') {
        while (*pattern != '\0') {
            if (*text == *pattern) {
                caught++;
                pattern++;
            } else {
                for (int i = 0; i < caught; i++) {
                    pattern--;
                }
                caught = 0;
                if (*pattern == *text) {
                    text--;
                    position--;
                }
            }
            if (caught == 1) {
                firstEntryPosition = position;
            }
            break;
        }
        text++;
        position++;
    }
    return patternLength == caught
           ? firstEntryPosition:
           -1;
}

char *resize(const char *str, unsigned size, unsigned new_size) {
    char *new_str = new char[new_size];
    for (int i = 0; i < new_size; i++) {
        if (size != 0) {
            *(new_str + i) = *(str + i);
        }
        size--;
    }
    delete []str;
    return new_str;
}

char *getLine() {
    unsigned size = 1;
    char *line = new char[size];
    char symbol = 0;
    unsigned counter = 0;
    while (std::cin.get(symbol)) {
        if (symbol == '\0' || symbol == '\n') {
            break;
        }
        *(line + counter) = symbol;
        if (counter == (size - 1)) {
            line = resize(line, size, ++size);
        }
        counter++;
    }
    *(line + size - 1) = '\0';
    return line;
}

int **transpose(const int * const *m, unsigned rows, unsigned cols) {
    int **transposedMatrix = new int * [cols];
    transposedMatrix[0] = new int [cols * rows];
    for (unsigned i = 1; i < cols; i++) {
        transposedMatrix[i] = transposedMatrix[i - 1] + rows;
    }
    for (unsigned i = 0; i < cols; i++) {
        for (unsigned j = 0; j < rows; j++) {
            transposedMatrix[i][j] = m[j][i];
        }
    }
    return transposedMatrix;
}

void swap_min(int *m[], unsigned rows, unsigned cols) {
    int min = m[0][0];
    unsigned rowWithMin = 0;
    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            if (min > m[i][j]) {
                min = m[i][j];
                rowWithMin = i;
            }
        }
    }
    int *tempFirstRow = m[0];
    m[0] = m[rowWithMin];
    m[rowWithMin] = tempFirstRow;
    tempFirstRow = 0;
}

void String::append(String &other) {
    size_t sizeOfOther = strlen(other.str);
    size_t oldSize = size;
    size += sizeOfOther;
    str = resize(str, oldSize, size + 1);
    for (size_t i = oldSize, j = 0; i < size, j < other.size; i++, j++) {
        str[i] = other.str[j];
    }
    str[size] = '\0';
}

char &get_c(Cls &cls) {
    return *(char *)(&cls);
}

double &get_d(Cls &cls) {
    size_t shift = sizeof(double);
    char *p = (char *)(&cls);
    for (size_t i = 0; i < shift; i++) {
        p++;
    }
    return *(double *) (p);
}

int &get_i(Cls &cls) {
    size_t shift = sizeof(double);
    char *p = (char *)(&cls);
    for (size_t i = 0; i < shift * 2; i++) {
        p++;
    }
    return *(int *) (p);
}