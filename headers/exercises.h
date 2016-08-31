//
// Created by DynNoil on 15.08.2016.
//

#ifndef FIRST_EXERSICES_H
#define FIRST_EXERSICES_H
#include <cstring>

struct String {
    size_t size;
    char *str;

    String(const char *str = "") {
        size = strlen(str);
        this->str = new char[size + 1];
        strcpy(this->str, str);
    }

    String(size_t n, char c) {
        size = n;
        str = new char[size + 1];
        for (size_t i = 0; i < size; i++) {
            str[i] = c;
        }
        str[n] = '\0';
    }

    ~String() {
        delete[] str;
    }

    void append(String &other);

};

struct Cls {
    explicit Cls(char c = 0, double d = 0, int i = 0)
            : c(c), d(d), i(i)
    {};
private:
    char c;
    double d;
    int i;
};

/*
 * Эта функция должна предоставить доступ к полю c объекта cls.
 * Обратите внимание, что возвращается ссылка на char, т. е.
 * доступ предоставляется на чтение и запись.
 */
char &get_c(Cls &cls);

/*
 * Эта функция должна предоставить доступ к полю d объекта cls.
 * Обратите внимание, что возвращается ссылка на double, т. е.
 * доступ предоставляется на чтение и запись.
 */
double &get_d(Cls &cls);

/*
 * Эта функция должна предоставить доступ к полю i объекта cls.
 * Обратите внимание, что возвращается ссылка на int, т. е.
 * доступ предоставляется на чтение и запись.
 */
int &get_i(Cls &cls);

unsigned gcd(unsigned a, unsigned b);
int reverseNumbersWithRecursion();
void rotateArray(int *m, unsigned size, int shift);
unsigned getStringLength(const char *str);
void my_strcat(char *to, const char *from);
int my_strstr(const char *text, const char *pattern);
char *resize(const char *str, unsigned size, unsigned new_size);
char *getLine();
int **transpose(const int * const *m, unsigned rows, unsigned cols);
void swap_min(int *m[], unsigned rows, unsigned cols);

#endif //FIRST_EXERSICES_H
