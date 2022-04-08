#include<iostream>

class dynamic_array
{
private:
    size_t size{};
    double* array{nullptr};

public:
    dynamic_array() { std::cout << "Default constructor called." << std::endl; }

    dynamic_array(size_t);  // parameterized

    dynamic_array(dynamic_array&);  // copy

    dynamic_array(dynamic_array&&);  // move

    ~dynamic_array() { std::cout << "Destructor called" << std::endl; }

    dynamic_array& operator=(dynamic_array&);  // copy assignment

    dynamic_array& operator=(dynamic_array&&);  // move assignment

    size_t length() const { return size; }

    double & operator[](size_t i);

    void print() const { for (size_t i{0}; i<length(); i++) std::cout << array[i] << " "; };
};

dynamic_array::dynamic_array(dynamic_array &to_copy)
// copy constructor using deep copying
{
    // copy size and declare new array
    std::cout << "Copy constructor\n";
    array = nullptr;
    size = to_copy.length();

    if (size > 0) {
        array = new double[size];
        for (size_t i{0}; i<size; i++) {
            array[i] = to_copy[i];
        }
    }
}

dynamic_array::dynamic_array(dynamic_array &&to_move)
// Move constructor
{  // steal the data
    std::cout << "move constructor\n";
    size = to_move.size;
    array = to_move.array;
    to_move.size = 0;
    to_move.array = nullptr;
}

dynamic_array & dynamic_array::operator=(dynamic_array &rhs)
// Assignment operator using deep copying
{
    std::cout << "Copy assignment\n";
    if (&rhs == this) return *this; // no self assignment

    // first delete this object's array
    delete[] array;
    array = nullptr;
    size = rhs.length();

    if (size<0) return *this;

    array = new double[size];
    // copy values into new array
    for (size_t i{}; i<size; i++) {
        array[i] = rhs[i];
    }
    return *this;
}

dynamic_array & dynamic_array::operator=(dynamic_array &&rhs)
// Move assignment operator
{
    std::cout << "Move assignment\n";
    std::swap(size, rhs.size);
    std::swap(array, rhs.array);
    return *this;
}

dynamic_array::dynamic_array(size_t size_req)
{
    std::cout << "Parametrized constructor called" << std::endl;

    if (size_req < 1) {
        std::cout << "Error: trying to declare an array with size < 1" << std::endl;
        throw("size not positive");
    }

    size = size_req;
    array = new double[size];

    for (size_t i{0}; i<size; i++) {
        array[i] = 0;
    }
}

double & dynamic_array::operator[](size_t i)
// Overload element[] operator
{
    if (i<0 || i>size) {
        std::cout << "Error: trying to access array element out of bounds" << std::endl;
        throw("Out of Bounds error");
    }
    return array[i];
}

int main() {
    std::cout << "Week 6: pre-lecture" << std::endl;

    std::cout<<"Declaring array a1 with parameterized constructor"<<std::endl;

    dynamic_array a1(2);

    std::cout << "Length of a1 = " << a1.length() << std::endl;

    a1[0] = 0.2;
    a1[1] = 0.3;

    for (size_t i{0}; i<a1.length(); i++) std::cout << "a1[" << i << "] = " << a1[i] << std::endl;

    std::cout << "Declaring array a2 with default constructor" << std::endl;
    dynamic_array a2;
    std::cout << "Length of a2 = " << a2.length() << std::endl;
    std::cout << "a1 = ";
    a1.print();
    std::cout << "\na2=";
    a2.print();
    std::cout << std::endl;

    std::cout << "Now copy values from a1 by assignment" << std::endl;
    a2 = a1;
    std::cout << "Length of a2 = " << a2.length() << " and of a1 = " << a1.length() << std::endl;


    std::cout << "Declaring array a3 with parameterized constructor" << std::endl;

    return 0;
}