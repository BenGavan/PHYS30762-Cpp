#include<iostream>

void double_value(double value)
{
    value *= 2;
}

int main()
{
    std::cout << "By value" << std::endl;

    double number{4.};

    std::cout << number << std::endl;

    double_value(number);

    std::cout << number << std::endl;

    return 0;
}
