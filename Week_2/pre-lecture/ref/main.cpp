#include<iostream>

void double_value(double* ptr_double)
{
//    *ptr_double = *ptr_double * 2.;
    (*ptr_double) *= 2;
}

int main()
{
    std::cout << "ref" << std::endl;

    double number{4.1};

    std::cout << number << std::endl;

    double_value(&number);

    std::cout << number << std::endl;

    return 0;
}
