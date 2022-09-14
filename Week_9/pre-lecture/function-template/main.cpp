#include<iostream>

template <class c_type> c_type maxval(c_type a, c_type b)
{
    return (a > b) ? a : b;
}

template <class T> T minval(T a, T b)
{
    return (a < b) ? a : b;
}

int main()
{
    std::cout << "Week 9 - Pre-lecture: Function Template" << std::endl;

    double x1{1};
    double x2{1.5};

    std::cout << "Max val (doubles) = " << maxval<double>(x1, x2) << std::endl;
    std::cout << "Min val (doubles) = " << minval<double>(x1, x2) << std::endl;

    int i1{3};
    int i2{4};

    std::cout << "Max val (int) = " << maxval<int>(i1, i2) << std::endl;
    std::cout << "Min val (int) = " << minval<int>(i1, i2) << std::endl;

    return 0;
}