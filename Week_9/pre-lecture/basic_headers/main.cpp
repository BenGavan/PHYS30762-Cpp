#include<iostream>
#include "myclass.h"

int main()
{
    std::cout << "Week 9 - Pre-lecture: Basic Header" << std::endl;
    namespace1::my_class c1{1};
    c1.show();
    return 0;
}