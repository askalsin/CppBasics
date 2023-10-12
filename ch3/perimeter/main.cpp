#include <iostream>

class Figure {
public:
    virtual int Perimeter() const = 0;

    virtual ~Figure() {}
};

class Triangle : public Figure {
private:
    int a, b, c;

public:
    Triangle(int a, int b, int c) : a(a), b(b), c(c) {}

    int Perimeter() const override
    {
        return a + b + c;
    }
};

class Rectangle : public Figure {
private:
    int a, b;

public:
    Rectangle(int a, int b) : a(a), b(b) {}

    int Perimeter() const override
    {
        return (a + b) * 2;
    }
};

int main() {}