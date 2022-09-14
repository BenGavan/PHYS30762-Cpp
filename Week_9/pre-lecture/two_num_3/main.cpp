#include<iostream>
#include "two_num.h"

int main()
{
    std::cout << "Week 9 - Pre-lecture: Two num 3" << std::endl;

    int x{1};
    int y{2};

    double a{-1.5};
    double b{-2.5};

    two_num::pair_of_numbers<int> int_pair{x, y};
    std::cout << "x + y = " << int_pair.add() << std::endl;
    std::cout << "x - y = " << int_pair.sub() << std::endl;

    using namespace two_num;

    // Use class template for object representing pair of doubles
    pair_of_numbers<double> double_pair{a, b};
    std::cout << "x + y = " << double_pair.add() << std::endl;
    std::cout << "x - y = " << double_pair.sub() << std::endl;


    return 0;
}