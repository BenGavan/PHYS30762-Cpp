#include<iostream>

int main()
{
    std::cout << "Week 10 - Pre-lecture: Bad Memory Allocation" << std::endl;

    double* my_array;

    try {
        my_array = new double[100000000000000000];
    } catch (std::bad_alloc mem_fail) {
        std::cout << "Memory allocation failure" << std::endl;
        return 1;
    }

    delete[] my_array;

    return 0;
}