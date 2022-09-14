#include<iostream>

const int divide_flag{-1};

double divide(double x, double y)
{
    if (x == 0) throw divide_flag;
    return y / x;
}

int main()
{
    std::cout << "Week 10 - Pre-lecture: Exception" << std::endl;

    double x{3.}, y{4.};
    double result;

    try {
        result = divide(x, y);
        std::cout << "y / x = " << result << std::endl;

        x = 0;
        result = divide(x, y);
        std::cout << "y / x = " << result << std::endl;
    } catch(int error_flag) {
        if (error_flag == divide_flag) {
            std::cerr << "Error: divide by zero" << std::endl;
            exit(error_flag);
        }
    }

    return 0;
}