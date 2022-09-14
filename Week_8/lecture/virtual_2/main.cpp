#include<iostream>

class Base
{
public:
    virtual void show() = 0;
};

int main()
{
    std::cout << "Week 8 - Lecture: virtual 2" << std::endl;

    Base b;
    Base *bp;

    return 0;
}