#include<iostream>

class Base
{
public:
    virtual void show() { std::cout << "In base\n"; }
    virtual void print();
};

class Derived: public Base
{
public:
    void show() { std::cout << "In Derived\n"; }
    void print() { std::cout << "print\n"; }
};

//class Something: public Derived
//{
//public:
//    void show() { std::cout << "In Derived\n"; }
//    void print() { std::cout << "print\n"; }
//    void del() { std::cout << "del\n"; }
//};

int main() {
    std::cout << "Week 8 - Lecture: virtual 1" << std::endl;

    Base *bp;
    Base b;
    Derived d;

    bp = &d;
    bp->show();

    b.show();
    
    bp = &b;
    bp->show();

    return 0;
}