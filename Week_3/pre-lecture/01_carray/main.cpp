#include<iostream>

void charArray()
{
    const size_t no_char{100};
    char string1[no_char];

    char* string2;
    string2 = new char[no_char];

    std::cout << sizeof(string1) << " " << sizeof(string2) << std::endl;
    std::cout << sizeof(char*) << std::endl;
}

int main()
{
    std::cout << "01_carray" << std::endl;

    charArray();

    const size_t n_a{5};
    double a[n_a];

    for (size_t i{0}; i<n_a; i++) {
        a[i] = static_cast<double>(i+1);
    }

    for (size_t i{0}; i<n_a; i++) {
        std::cout << "a[" << i << "] = " << a[i] << std::endl;
    }

    return 0;
}
