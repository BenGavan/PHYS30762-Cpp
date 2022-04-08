#include<iostream>

void triple_value(double& ref)
{
    ref *= 2;
}

int main()
{
    std::cout << "ref 2" << std::endl;

    double number{5.4};

    std::cout << number << std::endl;

    triple_value(number);

    std::cout << number << std::endl;

    return 0;
}

