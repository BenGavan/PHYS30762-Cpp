#include<iostream>
//#include<wchar.h>

void print_arr(const int number_of_values, double* array)
{
    std::cout << "Values: ";
    for(int i{0}; i<number_of_values; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int number_of_values;
    std::cout<<"Enter the number of values to enter: ";
    std::cin>>number_of_values;
    std::cout<<"You would like to enter "<<number_of_values<<" values"<<std::endl;

    double *values = new double[number_of_values];

    std::cout<<"Allocated memory for "<<number_of_values<<" doubles"<<std::endl;
    std::cout<<"Enter "<<number_of_values<<" doubles"<<std::endl;

    for(int i{0}; i<number_of_values; i++) {
        std::cin>>values[i];
    }

    print_arr(number_of_values, values);

    // Free memory
    delete[] values;
    std::cout<<"Freed memory"<<std::endl;

    double* replacement_arr = new double[number_of_values];
    for (int i{0}; i<number_of_values; i++) {
        replacement_arr[i] = -1;
    }

    print_arr(number_of_values, replacement_arr);

    print_arr(number_of_values, values);

    std::cout << "Before: ";
    std::cout << sizeof(replacement_arr) << std::endl;

    delete[] replacement_arr;

    std::cout << "After: ";
    std::cout << sizeof(replacement_arr) << std::endl;

    return 0;
}

