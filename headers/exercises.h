//
// Created by DynNoil on 15.08.2016.
//

#ifndef FIRST_EXERSICES_H
#define FIRST_EXERSICES_H

#include <cstring>
#include <iostream>
#include <algorithm>

class Rational {
    int numerator_;
    unsigned denominator_;
protected:
    void reduceRational();
public:
    Rational(int numerator = 0, unsigned denominator = 1);
    void add(Rational rational);
    void sub(Rational rational);
    void mul(Rational rational);
    void div(Rational rational);
    Rational& operator+=(Rational const &other);
    Rational& operator-=(Rational const &other);
    Rational& operator*=(Rational const &other);
    Rational& operator/=(Rational const &other);
    Rational operator-() const;
    Rational operator+() const;
    operator double() const;

    void neg();
    void pos();
    double to_double() const;

    void toString() const;
};

Rational operator+(Rational rational1, Rational const &rational2);
Rational operator-(Rational rational1, Rational const &rational2);
Rational operator*(Rational rational1, Rational const &rational2);
Rational operator/(Rational rational1, Rational const &rational2);

bool operator==(Rational const &rational1, Rational const &rational2);
bool operator!=(Rational const &rational1, Rational const &rational2);
bool operator<(Rational const &rational1, Rational const &rational2);
bool operator>(Rational const &rational1, Rational const &rational2);
bool operator<=(Rational const &rational1, Rational const &rational2);
bool operator>=(Rational const &rational1, Rational const &rational2);

struct Number;
struct BinaryOperation;

struct Visitor {
    virtual void visitNumber(Number const *number) = 0;

    virtual void visitBinaryOperation(BinaryOperation const *binaryOperation) = 0;

    virtual ~Visitor();
};

struct PrintBinaryOperationsVisitor : Visitor {
    void visitNumber(Number const *number);

    void visitBinaryOperation(BinaryOperation const *binaryOperation);
};

struct PrintVisitor : Visitor {
    void visitNumber(Number const *number);

    void visitBinaryOperation(BinaryOperation const *binaryOperation);
};


struct Expression {
    virtual void accept(Visitor *visitor) const = 0;

    virtual ~Expression();
};

struct Number : Expression {
    Number(double value);

    void accept(Visitor *visitor) const;

    double get_value() const;

private:
    double value;
};

struct BinaryOperation : Expression {
    BinaryOperation(Expression const *left, char op, Expression const *right);

    ~BinaryOperation();

    void accept(Visitor *visitor) const;

    Expression const *get_left() const;

    Expression const *get_right() const;

    char get_op() const;

private:
    Expression const *left;
    Expression const *right;
    char op;
};

struct Foo {
    void say() const {
        std::cout << "Foo says: " << msg << std::endl;
    }

protected:
    Foo(const char *msg) :
            msg(msg) {};

private:
    const char *msg;
};

struct Bar : Foo {
    Bar(const char *msg) :
            Foo(msg) {}
};

void foo_says(const Foo &foo);

Foo get_foo(const char *msg);

class String;

class StringAgent {
private:
    static StringAgent * p_instance;
    unsigned operatorCallCounter;
    size_t previousSize;
    StringAgent() {
        operatorCallCounter = 0;
        previousSize = 0;
    }
public:
    static StringAgent * getInstance() {
        if(!p_instance)
            p_instance = new StringAgent();
        return p_instance;
    }

    void setPreviousSize(size_t previousSize) {
        this->previousSize = previousSize;
    }

    size_t getPreviousSize() const {
        return previousSize;
    }

    void callOperator() {
        operatorCallCounter++;
    }

    unsigned getOperatorCallCounter() const {
        return operatorCallCounter;
    }
};

class String {
    size_t size;
    char *str_;
public:
    String(const char *str = "");
    String(size_t n, char c);
    String(String const &other);
    ~String();
    String &operator=(String const &other);
    String operator[](size_t index) const;
    operator bool() const;
    operator char const *() const;
    String &operator+=(String const &other);
    void append(String &other);
    void swap(String &other);
    void toString() const {
        std::cout << str_ << std::endl;
    }

};

struct Cls {
    explicit Cls(char c = 0, double d = 0, int i = 0)
            : c(c), d(d), i(i) {};
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

int **transpose(const int *const *m, unsigned rows, unsigned cols);

void swap_min(int *m[], unsigned rows, unsigned cols);

bool check_equals(Expression const *left, Expression const *right);

#endif //FIRST_EXERSICES_H
