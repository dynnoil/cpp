//
// Exercises and tasks from C++ course by Stepic.org
//
// Created by DynNoil on 15.08.2016.
//
#include <iostream>
#include "../headers/exercises.h"

Rational::Rational(int numerator, unsigned denominator)
        : numerator_(numerator), denominator_(denominator)
{
    reduceRational();
}

void Rational::reduceRational() {
    int tempNumerator = numerator_ < 0
                             ? -1 * numerator_
                             : numerator_;
    unsigned gcd_ = gcd(tempNumerator, denominator_);
    if (gcd_ != 1) {
        numerator_ /= gcd_;
        denominator_ /= gcd_;
    }
}

void Rational::add(Rational rational) {
    numerator_ *= rational.denominator_;
    numerator_ += rational.numerator_ * denominator_;
    denominator_ *= rational.denominator_;
    reduceRational();
}

void Rational::sub(Rational rational) {
    numerator_ *= rational.denominator_;
    numerator_ -= rational.numerator_ * denominator_;
    denominator_ *= rational.denominator_;
    reduceRational();
}

void Rational::mul(Rational rational) {
    numerator_ *= rational.numerator_;
    denominator_ *= rational.denominator_;
    reduceRational();
}

void Rational::div(Rational rational) {
    numerator_ *= rational.denominator_;
    denominator_ *= rational.numerator_;
    reduceRational();
}

void Rational::neg() {
    numerator_ = numerator_ < 0
                 ? numerator_
                 : -1 * numerator_;
}

void Rational::pos() {
    numerator_  =  numerator_ > 0
                   ? numerator_
                   : -1 * numerator_;
}

double Rational::to_double() const {
    return 1.0 * numerator_ / denominator_;
}

Rational& Rational::operator+=(Rational const &other) {
    this->add(other);
    return *this;
}

Rational operator+(Rational rational1, Rational const &rational2) {
    return rational1 += rational2;
}

Rational& Rational::operator-=(Rational const &other) {
    this->sub(other);
    return *this;
}

Rational operator-(Rational rational1, Rational const &rational2) {
    return rational1 -= rational2;
}

Rational& Rational::operator*=(Rational const &other) {
    this->mul(other);
    return *this;
}

Rational operator*(Rational rational1, Rational const &rational2) {
    return rational1 *= rational2;
}

Rational& Rational::operator/=(Rational const &other) {
    this->div(other);
    return *this;
}

Rational operator/(Rational rational1, Rational const &rational2) {
    return rational1 /= rational2;
}

Rational Rational::operator-() const {
    Rational tempRational(*this);
    tempRational.neg();
    return tempRational;
}

Rational Rational::operator+() const {
    Rational tempRational(*this);
    tempRational.pos();
    return tempRational;
}

Rational::operator double() const {
    return to_double();
}

bool operator==(Rational const &rational1, Rational const &rational2) {
    return rational1.to_double() == rational2.to_double();
}

bool operator!=(Rational const &rational1, Rational const &rational2) {
    return !(rational1 == rational2);
}

bool operator<(Rational const &rational1, Rational const &rational2) {
    return rational1.to_double() < rational2.to_double();
}

bool operator>(Rational const &rational1, Rational const &rational2) {
    return rational2 < rational1;
}

bool operator<=(Rational const &rational1, Rational const &rational2) {
    return !(rational2 < rational1);
}

bool operator>=(Rational const &rational1, Rational const &rational2) {
    return !(rational1 < rational2);
}

void Rational::toString() const {
    std::cout << numerator_ << "/" << denominator_ << std::endl;
}

Visitor::~Visitor() {}

void PrintBinaryOperationsVisitor::visitNumber(Number const *number) {
    std::cout << number->get_value() << " ";
}

void PrintBinaryOperationsVisitor::visitBinaryOperation(BinaryOperation const *binaryOperation) {
    binaryOperation->get_left()->accept(this);
    std::cout << binaryOperation->get_op() << " ";
    binaryOperation->get_right()->accept(this);
}

void PrintVisitor::visitNumber(Number const *number) {
    std::cout << number->get_value();
}

void PrintVisitor::visitBinaryOperation(BinaryOperation const *binaryOperation) {
    std::cout << "(";
    binaryOperation->get_left()->accept(this);
    std::cout << binaryOperation->get_op();
    binaryOperation->get_right()->accept(this);
    std::cout << ")";
}

Expression::~Expression() {}

Number::Number(double value)
        : value(value) {}

void Number::accept(Visitor *visitor) const {
    visitor->visitNumber(this);
};

double Number::get_value() const {
    return value;
}

BinaryOperation::BinaryOperation(Expression const *left, char op, Expression const *right)
        : left(left), op(op), right(right) {}

BinaryOperation::~BinaryOperation() {
    delete left;
    delete right;
}

void BinaryOperation::accept(Visitor *visitor) const {
    visitor->visitBinaryOperation(this);
}

Expression const *BinaryOperation::get_left() const {
    return left;
}

Expression const *BinaryOperation::get_right() const {
    return right;
}

char BinaryOperation::get_op() const {
    return op;
}

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
           ? firstEntryPosition :
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
    delete[]str;
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

int **transpose(const int *const *m, unsigned rows, unsigned cols) {
    int **transposedMatrix = new int *[cols];
    transposedMatrix[0] = new int[cols * rows];
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

String::String(const char *str)
        : size(strlen(str)), str_(new char[size + 1])
{
    strcpy(str_, str);
}

String::String(size_t n, char c)
        : size(n), str_(new char[size + 1])
{
    for (size_t i = 0; i < size; i++) {
        str_[i] = c;
    }
    str_[n] = '\0';
}

String::String(String const &other)
        : size(other.size), str_(new char[size + 1])
{
    strcpy(str_, other.str_);
}

String::~String() {
    delete[] str_;
}

String& String::operator=(String const &other) {
    if (this != &other) {
        String(other).swap(*this);
    }
    return *this;
}

StringAgent * StringAgent::p_instance = 0;

String String::operator[](size_t index) const {
    StringAgent * substringAgent = StringAgent::getInstance();
    substringAgent->callOperator();
    unsigned callCounter = substringAgent->getOperatorCallCounter();
    char *substring = "";
    if (callCounter == 1) {
        substringAgent->setPreviousSize(size);
        substring = new char[size - index + 1];
        for (size_t i = 0, j = index; j < size; i++, j++) {
            substring[i] = str_[j];
        }
        substring[size - index] = '\0';
    } else if (callCounter == 2) {
        size_t sizeDiff = substringAgent->getPreviousSize() - size;
        if (sizeDiff != index) {
            substring = new char[index - sizeDiff + 1];
            for (size_t i = 0; i < index - sizeDiff; i++) {
                substring[i] = str_[i];
            }
            substring[index - sizeDiff] = '\0';
        }
        delete substringAgent;
    }
    String startSubstring(substring);
    delete[] substring;
    return startSubstring;
}

String::operator bool() const {
    return size != 0;
}

String::operator char const *() const {
    if (*this) {
        return str_;
    }
    return "";
}

String& String::operator+=(String const &other) {
    size_t oldSize = size;
    size += strlen(other.str_);
    str_ = resize(str_, oldSize, size + 1);
    for (size_t i = oldSize, j = 0; i < size, j < other.size; i++, j++) {
        str_[i] = other.str_[j];
    }
    str_[size - 1] = '\0';
    return *this;
}

String operator+(String s1, String const& s2) {
    return s1 += s2;
}

void String::swap(String &other) {
    std::swap(size, other.size);
    std::swap(str_, other.str_);
}

void String::append(String &other) {
    size_t sizeOfOther = strlen(other.str_);
    size_t oldSize = size;
    size += sizeOfOther;
    str_ = resize(str_, oldSize, size + 1);
    for (size_t i = oldSize, j = 0; i < size, j < other.size; i++, j++) {
        str_[i] = other.str_[j];
    }
    str_[size] = '\0';
}

char &get_c(Cls &cls) {
    return *(char *) (&cls);
}

double &get_d(Cls &cls) {
    size_t shift = sizeof(double);
    char *p = (char *) (&cls);
    for (size_t i = 0; i < shift; i++) {
        p++;
    }
    return *(double *) (p);
}

int &get_i(Cls &cls) {
    size_t shift = sizeof(double);
    char *p = (char *) (&cls);
    for (size_t i = 0; i < shift * 2; i++) {
        p++;
    }
    return *(int *) (p);
}

void foo_says(const Foo &foo) {
    foo.say();
}

Foo get_foo(const char *msg) {
    Bar bar(msg);
    Foo foo = bar;
    return foo;
}

bool check_equals(Expression const *left, Expression const *right) {
    return (*(int **) left) == (*(int **) right);
}