#include<iostream>

union numeric_type {
    int int_value;
    long long_value;
    double double_value;
};

int main() {
    std::cout << "01_union" << std::endl;

    numeric_type values{11};  // int_value = 10

    std::cout << "int_value: " << values.int_value << std::endl;
    std::cout << "long_value: " << values.long_value << std::endl;
    std::cout << "double_value: " << values.double_value << std::endl;

    values.double_value = 3.1416;

    std::cout << "int_value: " << values.int_value << std::endl;
    std::cout << "long_value: " << values.long_value << std::endl;
    std::cout << "double_value: " << values.double_value << std::endl;

    return 0;
}