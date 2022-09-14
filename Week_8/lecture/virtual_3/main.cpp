#include<iostream>

class Base
{
public:
    virtual void show() = 0;
};

class Derived : public Base {};

int main()
{
    std::cout << "Week 8 - Lecture: virtual 3" << std::endl;

    Derived q;

    return 0;
}