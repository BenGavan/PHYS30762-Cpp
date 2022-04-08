#include<iostream>

int main()
{
    std::cout << "Ref 3 " << std::endl;

    int number{4};

    int& ref{number};
    int& refAlt = number;

    int* pointer{&number};
    int* pointerAlt = &number;

    std::cout << number << " " << ref << std::endl;

    number++;

    std::cout << number << " " << ref << std::endl;

    ref++;

    std::cout << number << " " << ref << std::endl;
    std::cout << number << " " << refAlt << std::endl;

    std::cout << "pointer" << std::endl;
    std::cout << number << " " << pointer << " " << &pointer << " " << *pointer << std::endl;
    std::cout << number << " " << pointerAlt << " " << &pointerAlt << " " << *pointerAlt << std::endl;

    *pointer = *pointer + 1;

    std::cout << number << " " << pointer << " " << &pointer << " " << *pointer << std::endl;
    std::cout << number << " " << ref << std::endl;

    return 0;
}

