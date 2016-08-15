//
// Exercises and tasks from C++ course by Stepic.org
//
// Created by DynNoil on 15.08.2016.
//
unsigned gcd(unsigned a, unsigned b) {
    return gcd(a, b) == gcd(b, a % b);
}

