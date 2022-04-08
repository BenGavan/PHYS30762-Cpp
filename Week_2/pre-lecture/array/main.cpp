#include<iostream>
#include<vector>

void print_array(const int array_entries, int* array)
{
    // show that array[i] is equivalent to *(array+i)
    for (int i{}; i < array_entries; i++) {
        std::cout << array[i] << " " << *(array + i) << std::endl;
    }

    printf("********\n");
    std::cout << *array << std::endl;
    printf("********\n");
    return;
}

void arr_experimenting()
{
    const int number_of_array_entries{11};
    int array[number_of_array_entries];
    for (int i{0}; i<number_of_array_entries; i++) {
        std::cout << i << ": " << array[i] << std::endl;
    }


}

void given()
{
    const int array_entries{3};
    int array[array_entries];
    for (int i{0}; i < array_entries; i++) array[i] = i;
    print_array(array_entries, array);

    std::vector<int> vect = {1,2,3};

    printf("********\n");

    int arrayB[5];
    int value{1};
    std::cout << "sizeof(arrayB): " << sizeof(arrayB) << std::endl;  // size of arrayB in bytes (8 bits)
    std::cout << "sizeof(value): " << sizeof(value) << std::endl;
    std::cout << "sizeof(1): " << sizeof(1) << std::endl;
    std::cout << "sizeof(int): " << sizeof(int) << std::endl;
    std::cout << "sizeof(std::string): " << sizeof(std::string) << std::endl;

    int arrayBElements = sizeof(arrayB) / sizeof(int);
    for (int i=0; i<arrayBElements; i++) {
        std::cout << i << ": " << array[i] << std::endl;
    }

    printf("********\n");

    int array_c[10];
    int array_c_length = sizeof(array_c) / sizeof(int);
    for (int i{0}; i<array_c_length; i++) {
        std::cout << i << ": " << array_c[i] << std::endl;
    }
}

int main()
{
    arr_experimenting();

    return 0;
}