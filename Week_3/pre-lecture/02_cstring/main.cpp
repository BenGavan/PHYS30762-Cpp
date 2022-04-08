#include<iostream>
#include<cstring>

int main()
{
    std::cout << "02_cstring" << std::endl;

    const size_t no_char{100};
    char string1[no_char];

    std::cout << "string1: " << sizeof(string1) << ", " << string1 << std::endl;

    char* string2;
    string2 = new char[no_char];

    char string3[] = "This is string3";

    std::cout << "string2: " << sizeof(string2) << ", " << string2 << std::endl;
    std::cout << "string3: " << sizeof(string3) << ", " << string3 << std::endl;

    std::cout << " --- " << std::endl;

    strcpy(string1, "This is string1");
    strcpy(string2, "This is string2");

    std::cout << "string1: " << sizeof(string1) << ", " << string1 << std::endl;
    std::cout << "string2: " << sizeof(string2) << ", " << string2 << std::endl;
    std::cout << "string3: " << sizeof(string3) << ", " << string3 << std::endl;

    std::cout << "--- comparisons ---" << std::endl;

    if (strcmp(string1, string2)) {
        std::cout << "Strings are NOT equal" << std::endl;
    } else {
        std::cout << "Strings are equal" << std::endl;
    }

    std::cout << "--- comparisons with itself ---" << std::endl;

    if (strcmp(string1, string1)) {
        std::cout << "Strings are NOT equal" << std::endl;
    } else {
        std::cout << "Strings are equal" << std::endl;
    }

    std::cout << "--- concatenation ---" << std::endl;

    strcat(string1, string2);
    std::cout << "Joined strings1 and string2: " << string1 << std::endl;
    std::cout << "string2: " << string2 << std::endl;

    std::cout << "--- copying ---" << std::endl;
    strcpy(string2, string1);

    std::cout << "string1: " << sizeof(string1) << ", " << string1 << std::endl;
    std::cout << "string2: " << sizeof(string2) << ", " << string2 << std::endl;

    return 0;
}