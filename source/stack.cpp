//
// Created by DynNoil on 15.08.2016.
//
// Данный код демонстрирует переполнение буфера
//
#include <iostream>

int foo() {
    std::cout << "Hello\n";
    return 2;
}

int bar() {
    int *m[1];
    m[2] = (int *) &foo;
    return 1;
}

