//
// Created by DynNoil on 14.08.2016.
//
#include <iostream>
#include <windows.h>
#include <string>
#include <cstring>
#include <algorithm>

#include "../headers/exercises.h"
//#include "../headers/tests.h"
#include "../headers/examples.h"

#define START_TIME() int start = GetTickCount();
#define END_TIME()  int end = GetTickCount(); cout <<"\nTime: " << end - start << " milisec";

using namespace std;

int main() {
    START_TIME();

    String const hello("Hellowa");
    String const str = hello[2][6];
    str.toString();
    END_TIME();
    return 0;
}