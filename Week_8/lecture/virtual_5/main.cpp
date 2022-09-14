#include<iostream>

class Base {
public:
    virtual ~Base() { std::cout << "based destroyed\n"; }
};

int main() {
    std::cout << "Week 8 - Lecture: virtual 4" << std::endl;

    Base b;

    return 0;
}